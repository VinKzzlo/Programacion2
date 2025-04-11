/* 
 * File:   MetodoDinamicoDeMemoria.cpp
 * Author: ramir
 * 
 * Created on 4 de mayo de 2024, 16:39
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
//Lectura de Libros
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock){
    int numDatos = 0,capacidad = 0,*registroStk;
    char **registroLib;
    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib,nombArch);
    libros = nullptr;
    while(1){
        registroLib = leerRegistroLib(archLib);
        if(archLib.eof()) break;
        registroStk = leerRegistroStk(archLib);
        if(numDatos==capacidad)
            aumentarCapLibros(libros,stock,numDatos,capacidad);
        agregarLibros(libros,stock,registroLib,registroStk,numDatos);
    }
}
//Lectura de cadena al segundo nivel del puntero
char **leerRegistroLib(ifstream &archLib){
    char **registro,*codigo;
    
    codigo = LeeCadenaExacta(archLib,8,',');
    if(archLib.eof()) return nullptr;
    registro = new char*[3];
    registro[0] = codigo;
    registro[1] = LeeCadenaExacta(archLib,60,',');
    registro[2] = LeeCadenaExacta(archLib,40,',');
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

int *leerRegistroStk(ifstream &archLib){
    int *registro;
    char c;
    double precio;
    
    registro = new int[2];
    archLib>>registro[0]>>c>>precio;
    archLib.get();
    
    registro[1] = 0;
    return registro;
}

void aumentarCapLibros(char ***&libros,int **&stock,int &numDatos,int &capacidad){
    int **auxStock;
    char ***auxLibros;
    capacidad += INCREMENTO;
    if(libros==nullptr){
        libros = new char**[capacidad];
        stock = new int*[capacidad];
        libros[0] = nullptr;
        stock[0] = nullptr;
        numDatos++;
    }else{
        auxLibros = new char**[capacidad];
        auxStock = new int*[capacidad];
        for(int i=0;i<numDatos;i++){
            auxLibros[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxLibros;
        stock = auxStock;
    }
}

void agregarLibros(char ***libros,int **stock,char **registroLib,
                   int *registroStk,int &numDatos){
    libros[numDatos-1] = registroLib;
    libros[numDatos] = nullptr;
    stock[numDatos-1] = registroStk;
    stock[numDatos] = nullptr;
    numDatos++;
}
//Prueba de lectura de libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock){
    int *auxStock;
    char **auxLibros;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    archRep<<left<<setw(10)<<"Codigo"<<setw(60)<<"Nombre"<<setw(40)
           <<"Autor"<<right<<setw(10)<<"Stock"<<setw(22)
           <<"Cantidad no atendida"<<endl;
    for(int i=0;libros[i]!=nullptr;i++){
        auxLibros = libros[i];
        auxStock = stock[i];
        archRep<<left<<setw(10)<<auxLibros[0]<<setw(60)<<auxLibros[1]<<setw(40)
               <<auxLibros[2]<<right<<setw(8)<<auxStock[0]<<setw(16)
               <<auxStock[1]<<endl;
    }
}
//Atencion de pedidos
/*
000059,34460612   CRY6839    VYG3594
000132,69200503   CPE5718     KGO1734     IUG2294      ILG7766
*/
void atencionDePedidos(const char *nombArch,char ***libros,int **&stock,
                       int **&pedidosClientes,char ***&pedidosLibros,
                       bool **&pedidosAtendidos){
    int numDatosCli = 0,capacidadCli = 0,*numDatosPed,*capacidadPed,numLib;
    int numPed,dni,ind;
    char codigo[8];
    bool tieneStock;
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    pedidosLibros = nullptr,pedidosClientes = nullptr;
    while(1){
        archPed>>numPed;
        if(archPed.eof()) break;
        archPed.get();
        archPed>>dni;
        ind = buscarPosCliente(pedidosClientes,dni);
        if(ind==NO_ENCONTRADO){
            if(numDatosCli==capacidadCli)
                aumentarCapPedCli(pedidosClientes,numDatosPed,capacidadPed,
                                  numDatosCli,capacidadCli);
            agregarCliente(pedidosClientes,numDatosPed,capacidadPed,numDatosCli,
                           ind,dni);
        }
        agregarPedidos(pedidosClientes[ind])
    }
}

int buscarPosCliente(int **pedidosClientes,int dni){
    int *auxPedCli;
    if(pedidosClientes!=nullptr)
        for(int i=0;pedidosClientes[i]!=nullptr;i++){
            auxPedCli = pedidosClientes[i];
            if(auxPedCli[0]==dni) return i;
        }
    return NO_ENCONTRADO;
}

void aumentarCapPedCli(int **&pedidosClientes,int *&numDatosPed,
                       int *&capacidadPed,int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    if(pedidosClientes==nullptr){
        pedidosClientes = new int*[capacidad];
        numDatosPed = new int[capacidad];
        capacidadPed = new int[capacidad];
        pedidosClientes[0] = nullptr;
        numDatosPed[0] = 0;
        capacidadPed[0] = 0;
        numDatos++;
    }else
        cambiarAuxAPuntPedCli(pedidosClientes,numDatosPed,capacidadPed,
                              numDatos,capacidad);
}

void cambiarAuxAPuntPedCli(int **&pedidosClientes,int *&numDatosPed,
                           int *&capacidadPed,int numDatos,int capacidad){
    int **auxPedCli,*auxNumDatosPed,*auxCapacidadPed;
    auxPedCli = new int*[capacidad];
    auxNumDatosPed = new int[capacidad];
    auxCapacidadPed = new int[capacidad];
    for(int i=0;i<numDatos;i++){
        auxPedCli[i] = pedidosClientes[i];
        auxNumDatosPed[i] = numDatosPed[i];
        auxCapacidadPed[i] = capacidadPed[i];
    }
    delete pedidosClientes;
    delete numDatosPed;
    delete capacidadPed;
    pedidosClientes = auxPedCli;
    numDatosPed = auxNumDatosPed;
    capacidadPed = auxCapacidadPed;
}

void agregarCliente(int **&pedidosClientes,int *numDatosPed,int *capacidadPed,
                    int &numDatos,int &indice,int dni){
    agregarCapacidad(pedidosClientes[numDatos-1],dni,numDatosPed[numDatos-1],
                     capacidadPed[numDatos-1]);
    pedidosClientes[numDatos] = nullptr;
    numDatosPed[numDatos] = 0;
    capacidadPed[numDatos] = 0;
    indice = numDatos-1;
    numDatos++;
}

void agregarCapacidad(int *&pedCliente,int dni,int &numDatos,int &capacidad){
    int auxPedCli;
    capacidad += INCREMENTO;
    pedCliente = new int[capacidad];
    pedCliente[0] = dni;
    pedCliente[1] = 0;
    numDatos += 2;
}
//Ordenar pedidos clientes
void ordenarPedidosClientes(int **&pedidosClientes);
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos);