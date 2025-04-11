/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: ramir
 * 
 * Created on 29 de julio de 2024, 10:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 140
//Lectura de libros
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock){
    char **buffLib[300];
    int *buffStock[300];
    double precio;
    ifstream archLib(nombArch,ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        buffLib[i] = leerLibros(archLib);
        if(archLib.eof()) break;
        buffStock[i] = leerStock(archLib);
        archLib>>precio;
        archLib.get();
        i++;
    }
    int n=i;
    libros = new char**[n+1];
    stock = new int*[n];
    for(int i=0;i<n;i++){
        libros[i] = buffLib[i];
        stock[i] = buffStock[i];
    }
    libros[n] = nullptr;
}

char **leerLibros(ifstream &archLib){
    char *codLibro,**trio;
    
    codLibro = LeeCadenaExacta(archLib,8,',');
    if(archLib.eof()) return nullptr;
    trio = new char*[3];
    trio[0] = codLibro;
    trio[1] = LeeCadenaExacta(archLib,60,',');
    trio[2] = LeeCadenaExacta(archLib,40,',');
    return trio;
}

char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

int *leerStock(ifstream &archLib){
    int stock,*dupla;
    
    archLib>>stock;
    if(archLib.eof()) return nullptr;
    archLib.get();
    dupla = new int[2];
    dupla[0] = stock;
    dupla[1] = 0;
    return dupla;
}
//Prueba de Lectura de Libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    char **auxLib;
    int *auxStk;
    for(int i=0;libros[i]!=nullptr;i++){
        auxLib = libros[i];
        auxStk = stock[i];
        archRep<<left<<setw(10)<<auxLib[0]<<setw(60)<<auxLib[1]<<setw(40)
               <<auxLib[2]<<right<<setw(8)<<auxStk[0]<<setw(8)<<auxStk[1]<<endl;
    }
}
//Atencion de Pedidos
/*
000059,34460612   CRY6839    VYG3594
000140,42302422   WPU8819    CTW5846
*/
void atencionDePedidos(const char *nombArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    int *buffPedCli[200]{},numPed,dni,posCli=NO_ENCONTRADO,cantLibEnPed[200]{};
    char **buffPedLib[200]{};
    bool *buffPedAten[200]{};
    ifstream archPed(nombArch,ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cantCli=0,cantPed=0;
    while(1){
        archPed>>numPed;
        if(archPed.eof()) break;
        archPed.get();
        archPed>>dni;
        if(cantCli>0) posCli = buscarCliente(buffPedCli,dni);
        if(posCli==NO_ENCONTRADO)
            agregarCliente(buffPedCli[cantCli],dni,posCli,cantCli);
        agregarPedido(buffPedCli[posCli],numPed);
        leerPedidos(archPed,libros,stock,buffPedLib[numPed],buffPedAten[numPed],
                    cantLibEnPed[numPed]);
        cantPed++;
    }
    cargarArreglos(pedidosClientes,pedidosLibros,pedidosAtendidos,buffPedCli,  
                   buffPedLib,buffPedAten,cantCli,cantPed,cantLibEnPed);
}

int buscarCliente(int **buffPedCli,int dni){
    int *auxPedCli;
    for(int i=0;buffPedCli[i]!=nullptr;i++){
        auxPedCli = buffPedCli[i];
        if(auxPedCli[0]==dni) return i;
    }
    return NO_ENCONTRADO;
}

void agregarCliente(int *&buffpedcli,int dni,int &posCli,int &cantCli){
    buffpedcli = new int[20];
    buffpedcli[0] = dni;
    buffpedcli[1] = 0;
    posCli = cantCli;
    cantCli++;
}

void agregarPedido(int *buffpedcli,int numPed){
    buffpedcli[2+buffpedcli[1]] = numPed;
    buffpedcli[1]++;
}

void leerPedidos(ifstream &archPed,char ***libros,int **stock,
                 char **&buffPedLib,bool *&buffPedAten,int &cantLib){
    int posLib;
    char codLib[8];
    buffPedLib = new char*[20];
    buffPedAten = new bool[20];
    while(1){
        archPed>>codLib;
        buffPedLib[cantLib] = new char[8];
        strcpy(buffPedLib[cantLib],codLib);
        posLib = buscarLibro(libros,codLib);
        modificarPedidoAtendido(stock[posLib],buffPedAten[cantLib]);
        cantLib++;
        if(archPed.get()=='\n') break;
    }
}

int buscarLibro(char ***libros,char *codLib){
    char **auxLib;
    for(int i=0;libros[i]!=nullptr;i++){
        auxLib = libros[i];
        if(strcmp(auxLib[0],codLib)==0) return i;
    }
    return NO_ENCONTRADO;
}

void modificarPedidoAtendido(int *stock,bool &seAtendio){
    if(stock[0]>0){
        seAtendio = true;
        stock[0]--;
    }else{
        seAtendio = false;
        stock[1]++;
    }
}

void cargarArreglos(int **&pedidosClientes,char ***&pedidosLibros,
                   bool **&pedidosAtendidos,int **buffPedCli,char ***buffPedLib,   
                   bool **buffPedAten,int cantCli,int cantPed,int *cantLibEnPed){
    pedidosClientes = new int*[cantCli+1];
    pedidosLibros = new char**[cantPed+1];
    pedidosAtendidos = new bool*[cantPed];
    
    int *auxBuffCli;
    for(int i=0;i<cantCli;i++){
        auxBuffCli = buffPedCli[i];
        pedidosClientes[i] = new int[auxBuffCli[1]+2];
        cargaClienteNivelInterno(pedidosClientes[i],buffPedCli[i]);
    }
    pedidosClientes[cantCli] = nullptr;
    
    for(int i=1;i<cantPed+1;i++){
        pedidosLibros[i] = new char*[cantLibEnPed[i]+1];
        pedidosAtendidos[i] = new bool[cantLibEnPed[i]];
        cargaPedidoNivelInterno(pedidosLibros[i],pedidosAtendidos[i],
                                buffPedLib[i],buffPedAten[i],cantLibEnPed[i]);
    }
    pedidosLibros[cantPed+1] = nullptr;
}

void cargaClienteNivelInterno(int *pedidoscliente,int *buffpedcli){
    for(int i=0;i<buffpedcli[1]+2;i++){
        pedidoscliente[i] = buffpedcli[i];
    }
}

void cargaPedidoNivelInterno(char **pedidoslibros,bool *pedidosatendidos,
                             char **buffpedlib,bool *buffpedaten,int n){
    for(int i=0;i<n;i++){
        pedidoslibros[i] = buffpedlib[i];
        pedidosatendidos[i] = buffpedaten[i];
    }
    pedidoslibros[n] = nullptr;
}
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos){
    int *auxPedCli;
    char **auxPedLib;
    bool *auxPedAten;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    imprimirTitulo(archRep);
    for(int i=0;pedidosClientes[i]!=nullptr;i++){
        auxPedCli = pedidosClientes[i];
        archRep<<"CLIENTE: "<<auxPedCli[0]<<endl;
        imprimirLinea(archRep,'=');
        for(int j=2;j<auxPedCli[1]+2;j++){
            imprimirEncabezadoCliente(archRep);
            archRep<<right<<setw(32)<<" "<<setfill('0')<<setw(6)<<auxPedCli[j]
                   <<setfill(' ')<<endl;
            auxPedLib = pedidosLibros[auxPedCli[j]];
            auxPedAten = pedidosAtendidos[auxPedCli[j]];
            for(int k=0;auxPedLib[k]!=nullptr;k++){
                archRep<<right<<setw(75)<<auxPedLib[k];
                if(auxPedAten[k]) archRep<<right<<setw(42)<<"ATENDIDO"<<endl;
                else archRep<<right<<setw(45)<<"NO ATENDIDO"<<endl;
            }
            imprimirLinea(archRep,'-');
        }
        imprimirLinea(archRep,'=');
    }
}

void imprimirTitulo(ofstream &archRep){
    archRep<<setw(89)<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    imprimirLinea(archRep,'=');
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void imprimirEncabezadoCliente(ofstream &archRep){
    archRep<<setw(40)<<"Pedido No."<<setw(40)<<"Codigo del libro"<<setw(40)
           <<"Observacion"<<endl;
    imprimirLinea(archRep,'-');
}