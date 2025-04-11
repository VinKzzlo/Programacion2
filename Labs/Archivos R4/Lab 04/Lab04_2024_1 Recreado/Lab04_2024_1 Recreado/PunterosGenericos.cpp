/* 
 * File:   PunterosGenericos.cpp
 * Author: n422
 * 
 * Created on 23 de abril de 2024, 01:51 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#define NO_ENCONTRADO -1
//Cargar clientes
void cargaClientes(void *&clientes){
    void *buff[100],**lclientes;
    ifstream archCli("Clientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.csv"<<endl;
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
}
/*
54393647,Reyes Tang Edward 
67066631,Arca Amezquita Edric Ronald
*/
void *leerClientes(ifstream &archCli){
    void **registro;
    int *dni,*cantLib;
    char *nombre;
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    nombre = LeeCadenaExacta(archCli,60,'\n');
    cantLib = new int;
    *cantLib = 0;
    registro = new void*[4];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = nullptr;
    registro[3] = cantLib;
    return registro;
}
//Lectura de cadena al primer nivel del puntero
char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
//Cargar libros
void cargaLibros(void *&libros){
    void *buff[300],**loslibros;
    ifstream archLib("Libros.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        buff[i] = leerLibros(archLib);
        if(archLib.eof()) break;
        i++;
    }
    int n=i;
    loslibros = new void*[n+1];
    for(i=0;i<n;i++) loslibros[i] = buff[i];
    loslibros[n] = nullptr;
    libros = loslibros;
}
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
void *leerLibros(ifstream &archLib){
    void **registro;
    int stock;
    double precio;
    char *codigo,*nombre,*autor,c;
    codigo = LeeCadenaExacta(archLib,8,',');
    if(archLib.eof()) return nullptr;
    nombre = LeeCadenaExacta(archLib,60,',');
    autor = LeeCadenaExacta(archLib,40,',');
    archLib>>stock>>c>>precio;
    archLib.get();
    
    registro = new void*[3];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = autor;
    return registro;
}
//Cargar pedidos
/*
34460612,  CRY6839
42302422,  WPU8819
*/
void cargaPedidos(void *clientes,void *libros){
    void **lclientes = (void **)clientes,**loslibros = (void **)libros;
    int dni,posLib,posCli;
    char *codigo;
    ifstream archPed("Pedidos.txt",ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.txt"<<endl;
        exit(1);
    }
    while(1){
        archPed>>dni;
        if(archPed.eof()) break;
        archPed.get();
        archPed>>ws;
        codigo = LeeCadenaExacta(archPed,8,'\n');
        posLib = buscarPosLib(libros,codigo);
        posCli = buscarPosCli(clientes,dni);
        if(posLib!=NO_ENCONTRADO and posCli!=NO_ENCONTRADO)
            agregaPedido(lclientes[posCli],loslibros[posLib]);
    }
    clientes = lclientes;
    libros = loslibros;
}

int buscarPosLib(void *libros,char *codigo){
    void **loslibros = (void**)libros,**registroLib,*libro;
    for(int i=0;loslibros[i];i++){
        libro = loslibros[i];
        registroLib = (void**)libro;
        if(strcmp((char*)registroLib[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

int buscarPosCli(void *clientes,int dni){
    void **lclientes = (void**)clientes,**registroCli,*cliente;
    for(int i=0;lclientes[i];i++){
        cliente = lclientes[i];
        registroCli = (void**)cliente;
        if(*(int*)registroCli[0]==dni) return i;
    }
    return NO_ENCONTRADO;
}

void agregaPedido(void *&cliente,void *&libro){
    void **registroCli = (void **)cliente,**registroLib = (void **)libro;
    void **arregloPed = (void **)registroCli[2],**registroPed;
    int *cantLib;
    *cantLib = *(int *)registroCli[3];
    
    char *codLib = (char *)registroLib[0],*nombre = (char *)registroLib[1];
    registroPed = new void*[2];
    registroPed[0] = codLib;
    registroPed[1] = nombre;
    
    if(*cantLib<20){
        if(arregloPed==nullptr) arregloPed = new void*[21];
        arregloPed[*cantLib] = registroPed;
        arregloPed[*cantLib+1] = nullptr;
        *cantLib = *cantLib + 1;
    }
    cliente = arregloPed;
    libro = arregloPed;
}
//Imprimir reporte
void imprimeReporte(void *clientes){
    void **lclientes = (void**)clientes;
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.txt"<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;lclientes[i];i++){
        
    }
}