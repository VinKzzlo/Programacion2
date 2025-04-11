/* 
 * File:   PunterosGenericos.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 25 de abril de 2024, 13:18
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1
//Carga de productos
void cargaproductos(void *&productos){
    void *buff[200],**lproductos;
    ifstream archProd;
    AperturaDeUnArchivoDeTextosParaLeer(archProd,"Productos2.csv");
    int i=0;
    while(1){
        buff[i] = leerProductos(archProd);
        if(archProd.eof()) break;
        i++;
    }
    int n=i;
    lproductos = new void*[n+1];
    for(i=0;i<n;i++) lproductos[i] = buff[i];
    lproductos[n] = nullptr;
    productos = lproductos; //void* <- void**
    
    imprimeproductos(productos);
}
/*
BIT-434,Campana Extractora modelo Glass,375.09,S
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
*/
void *leerProductos(ifstream &archProd){
    void **registro;
    char *codigo,*descripcion,*tipo,c;
    double *precio;
    codigo = LeeCadenaExacta(archProd,8,',');
    if(archProd.eof()) return nullptr;
    descripcion = LeeCadenaExacta(archProd,60,',');
    precio = new double;
    tipo = new char;
    archProd>>*precio>>c>>*tipo;
    archProd.get();
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = tipo;
    return registro;
}

char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
//Carga de clientes
void cargaclientes(void *&clientes){
    void *buff[150],**lclientes;
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes2.csv");
    int i=0;
    while(1){
        buff[i] = leerClientes(archCli);
        if(archCli.eof()) break;
        i++;
    }
    int n=i;
    lclientes = new void*[n+1];
    for(i=0;i<n;i++) lclientes[i] = buff[i];
    lclientes[n] = nullptr;
    clientes = lclientes;
    
    imprimeclientes(clientes);
}
/*
79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
*/
void *leerClientes(ifstream &archCli){
    void **registro;
    int *dni,*lineaCred,telefono;
    char *nombre,c;
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    nombre = LeeCadenaExacta(archCli,60,',');
    lineaCred = new int;
    archCli>>telefono>>c>>*lineaCred;
    registro = new void*[4];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = nullptr;
    registro[3] = lineaCred;
    return registro;
}
//Carga de pedidos
/*
JXD-139,50375303,6
CRU-009,50375303,5
*/
void cargapedidos(void *productos,void *clientes){
    void **lproductos = (void**)productos,**lclientes = (void**)clientes;
    int posProd,posCli,dni,cant;
    char *codigo,c;
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos2.csv");
    while(1){
        codigo = LeeCadenaExacta(archPed,8,',');
        if(archPed.eof()) break;
        archPed>>dni>>c>>cant;
        archPed.get();
        posProd = buscarPosProd(lproductos,codigo);
        posCli = buscarPosCli(lclientes,dni);
        if(posProd!=NO_ENCONTRADO and posCli!=NO_ENCONTRADO)
            agregarPedidos(lclientes[posCli],lproductos[posProd],cant);
    }
    crearMemoriaExacta(clientes,lclientes);
    imprimerepfinal(clientes);
}

int buscarPosProd(void **lproductos,char *codigo){
    void **auxProd;
    for(int i=0;lproductos[i]!=nullptr;i++){
        auxProd = (void**)lproductos[i];
        if(strcmp((char*)auxProd[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

int buscarPosCli(void **lclientes,int dni){
    void **auxCli;
    for(int i=0;lclientes[i]!=nullptr;i++){
        auxCli = (void**)lclientes[i];
        if(*(int *)auxCli[0]==dni) return i;
    }
    return NO_ENCONTRADO;
}

void agregarPedidos(void *cliente,void *producto,int cant){
    void **registroCli = (void**)cliente,**registroProd = (void**)producto;
    void **registroPed;
    int *cantPed;
    char *codProd,*usaLinea;
    double *totPed,*lineaCred,*precio,monto;
    precio = (double *)registroProd[2];
    usaLinea = (char *)registroProd[3];
    lineaCred = (double *)registroCli[3];
    monto = (*precio)*cant;
    if(*usaLinea!='S' or monto<*lineaCred){
        if(*usaLinea=='S')
            *(double *)registroCli[3] -= monto; //Casteamos la linea de credito
        codProd = new char[strlen((char *)registroProd[0])+1];
        strcpy(codProd,(char *)registroProd[0]);
        cantPed = new int;
        *cantPed = cant;
        totPed = new double;
        *totPed = monto;
        registroPed = new void*[3];
        registroPed[0] = codProd;
        registroPed[1] = cantPed;
        registroPed[2] = totPed;
        insertarPedidoEnCliente(registroCli[2],registroPed);
    }
}

void insertarPedidoEnCliente(void *&dirPed,void *registroPed){
    void **arregloPed = (void **)dirPed;
    int cantPed=0;
    if(arregloPed==nullptr) arregloPed = new void*[100]{};
    while(arregloPed[cantPed]) cantPed++;
    arregloPed[cantPed] = registroPed;
    dirPed = arregloPed;
}

void crearMemoriaExacta(void *&clientes,void **lclientes){
    void **auxCli;
    for(int i=0;lclientes[i]!=nullptr;i++){
        auxCli = (void **)lclientes[i];
        ajustarArreglo(auxCli[2]);
    }
    clientes = lclientes;
}

void ajustarArreglo(void *&dirPed){
    void **arregloPed = (void **)dirPed,**auxArregloPed;
    int n = 0;
    if(arregloPed!=nullptr){
        while(arregloPed[n]!=nullptr) n++;
        auxArregloPed = new void*[n+1];
        for(int i=0;i<n;i++) auxArregloPed[i] = arregloPed[i];
    }
    arregloPed = auxArregloPed;
}