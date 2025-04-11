/* 
 * File:   PunterosGenericos.cpp
 * Author: ramir
 * 
 * Created on 11 de mayo de 2024, 22:56
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#define NO_ENCONTRADO -1
//Carga de clientes
    void cargaclientes(void *&clientes){
    void *buff[100],**lclientes;
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
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
    
    muestraclientes(clientes);
}
/*
54393647,Reyes Tang Edward 
67066631,Arca Amezquita Edric Ronald
*/
void *leerClientes(ifstream &archCli){
    void **registro;
    int *dni;
    char *nombre;
    
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    nombre = LeeCadenaExacta(archCli,60,'\n');
    
    registro = new void*[2];
    registro[0] = dni;
    registro[1] = nombre;
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
//Creacion de reserva
void creareserva(void *&reserva){
    void *buff[300],**lreserva;
    ifstream archRes;
    AperturaDeUnArchivoDeTextosParaLeer(archRes,"Libros.csv");
    int i=0;
    while(1){
        buff[i] = leerReserva(archRes);
        if(archRes.eof()) break;
        i++;
    }
    int n=i;
    lreserva = new void*[n+1];
    for(i=0;i<n;i++) lreserva[i] = buff[i];
    lreserva[n] = nullptr;
    reserva = lreserva;
    
    muestrareservas(reserva);
}
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
void *leerReserva(ifstream &archRes){
    void **registro;
    int *stock;
    char *codigo,*nombre,*autor,c;
    double precio;
    
    codigo = LeeCadenaExacta(archRes,8,',');
    if(archRes.eof()) return nullptr;
    nombre = LeeCadenaExacta(archRes,60,',');
    autor = LeeCadenaExacta(archRes,40,',');
    stock = new int;
    archRes>>*stock>>c>>precio;
    archRes.get();
    
    registro = new void*[5];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = autor;
    registro[3] = crearMemoriaExacta(*stock);
    registro[4] = stock;
    return registro;
}

void *crearMemoriaExacta(int stock){
    void **registro = new void*[stock]{};
    return registro;
}
//Carga de reserva
/*
69200503,ZQY9966
14268463,BHD6079
*/
void cargareservar(void *clientes,void *reserva){
    void **lclientes = (void**)clientes,**lreserva = (void**)reserva;
    int dni,posCli,posLib,*stockActual;
    char *codigo;
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos2.csv");
    calcularStockActual(reserva,stockActual);
    while(1){
        archPed>>dni;
        if(archPed.eof()) break;
        archPed.get();
        codigo = LeeCadenaExacta(archPed,8,'\n');
        posCli = buscarPosCliente(clientes,dni);
        posLib = buscarPosLibro(reserva,codigo);
        if(posCli!=NO_ENCONTRADO and posLib!=NO_ENCONTRADO)
            agregarPedido(lreserva[posLib],lclientes[posCli],stockActual[posLib]);
    }
}
//Nota: Nunca pases como parametro un (void**), 0 inmediato
void calcularStockActual(void *reserva,int *&stockActual){
    void **lreserva = (void**)reserva,**registroRes;
    int numDat = 0;
    while(lreserva[numDat]) numDat++;
    stockActual = new int[numDat];
    for(int i=0;lreserva[i];i++){
        registroRes = (void**)lreserva[i];
        stockActual[i] = *(int*)registroRes[4];
    }
}

int buscarPosCliente(void *clientes,int dni){
    void **lclientes = (void**)clientes,**registroCli;
    int *dniEncontrado;
    for(int i=0;lclientes[i];i++){
        registroCli = (void**)lclientes[i];
        dniEncontrado = (int*)registroCli[0];
        if(*dniEncontrado==dni) return i;
    }
    return NO_ENCONTRADO;
}

int buscarPosLibro(void *reserva,char *codigo){
    void **lreserva = (void**)reserva,**registroRes;
    char *codigoEncontrado;
    for(int i=0;lreserva[i];i++){
        registroRes = (void**)lreserva[i];
        codigoEncontrado = (char*)registroRes[0];
        if(strcmp(codigoEncontrado,codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void agregarPedido(void *reserva,void *cliente,int &stockActual){
    void **registroRes = (void**)reserva,**registroCli = (void**)cliente;
    void **registroPed = (void**)registroRes[3],**registro;
    int numDat = 0;
    int *dni = (int*)registroCli[0];
    char *nombre = (char*)registroCli[1];
    if(stockActual>0){
        while(registroPed[numDat]) numDat++;
        registro = new void*[2];
        registro[0] = dni;
        registro[1] = nombre;
        registroPed[numDat] = registro;
        stockActual--;
    }
}