/* 
 * File:   PunterosGenericos.cpp
 * Author: ramir
 * 
 * Created on 26 de abril de 2024, 08:15
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
#define NO_ENCONTRADO -1
//Carga de productos
void cargaproductos(void *&productos){
    void *buff[200],**lproductos;
    ifstream archProd("Productos2.csv",ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos2.csv"<<endl;
        exit(1);
    }
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
    productos = lproductos;
    
    imprimeproductos(productos);
}
/*
BIT-434,Campana Extractora modelo Glass,375.09,S
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
*/
void *leerProductos(ifstream &archProd){
    void **registro;    //Crear registro pa retornar
    
    char *codigo,*descripcion,*tipo,c;
    double *precio;
    
    codigo = LeeCadenaExacta(archProd,8,',');
    if(archProd.eof()) return nullptr;
    descripcion = LeeCadenaExacta(archProd,60,',');
    tipo = new char;
    precio = new double;
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
    void *buff[200],**lclientes;
    ifstream archCli("Clientes2.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes2.csv"<<endl;
        exit(1);
    }
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
    
    int *dni,telefono,*lineaCred;
    char *codigo,c;
    
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    codigo = LeeCadenaExacta(archCli,60,',');
    lineaCred = new int;
    archCli>>telefono>>c>>*lineaCred;
    
    registro = new void*[4];
    registro[0] = dni;
    registro[1] = codigo;
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
    int posProd,posCli,cant,dni;
    char *codigo,c;
    ifstream archPed("Pedidos2.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos2.csv"<<endl;
        exit(1);
    }
    while(1){
        codigo = LeeCadenaExacta(archPed,8,',');
        if(archPed.eof()) break;
        archPed>>dni>>c>>cant;
        archPed.get();
        posCli = buscarPosCliente(clientes,dni);
        posProd = buscarPosProductos(productos,codigo);
        if(posCli!=NO_ENCONTRADO and posProd!=NO_ENCONTRADO)
            agregaPedido(lclientes[posCli],lproductos[posProd],cant);
    }
}

int buscarPosCliente(void *clientes,int dni){
    void **lclientes = (void**)clientes,**registroCli;
    for(int i=0;lclientes[i];i++){
        registroCli = (void**)lclientes[i];
        if(*(int*)registroCli[0]==dni) return i;
    }
    return NO_ENCONTRADO;
}

int buscarPosProductos(void *productos,char *codigo){
    void **lproductos = (void**)productos,**registroProd;
    for(int i=0;lproductos[i];i++){
        registroProd = (void**)lproductos[i];
        if(strcmp((char*)registroProd[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void agregaPedido(void *cliente,void *producto,int cant){
    
}