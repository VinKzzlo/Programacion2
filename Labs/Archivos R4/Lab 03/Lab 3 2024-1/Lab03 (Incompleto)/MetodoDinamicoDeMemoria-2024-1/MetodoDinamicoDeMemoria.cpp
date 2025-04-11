/* 
 * File:   MetodoDinamicoDeMemoria.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 20 de abril de 2024, 03:33
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
#define MAX_LINEA 140
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
//Asignar nueva direccion al stock
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
    char ***auxLib;
    capacidad += INCREMENTO;    //Aumentar la capacidad
    if(libros==nullptr){    //Verificar si es la primera vez que se incrementa
        libros = new char**[capacidad];
        stock = new int*[capacidad];
        libros[0] = nullptr;
        stock[0] = nullptr;
        numDatos++;     //Aumentar el numero de datos para incluir el nullptr
    }else{
        auxLib = new char**[capacidad];
        auxStock = new int*[capacidad];
        for(int i=0;i<numDatos;i++){    //Pasar los datos de los punteros a
            auxLib[i] = libros[i];      //los auxiliares
            auxStock[i] = stock[i];
        }
        delete libros;  //Liberar el espacio de memoria
        delete stock;
        libros = auxLib;    //Asignar nueva direccion del puntero
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
//Prueba de Lectura de Libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock){
    int *auxStock;
    char **auxLib;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    for(int i=0;libros[i]!=nullptr;i++){
        auxLib = libros[i];
        auxStock = stock[i];
        archRep<<left<<setw(10)<<auxLib[0]<<setw(60)<<auxLib[1]<<setw(30)
               <<auxLib[2]<<right<<setw(8)<<auxStock[0]<<setw(8)<<auxStock[1]
               <<endl;
    }
}
//Atencion de Pedidos
/*
000059,34460612   CRY6839    VYG3594
000132,69200503   CPE5718     KGO1734     IUG2294      ILG7766
*/
void atencionDePedidos(const char *nombArch,char ***libros,int **&stock,
                       int **&pedidosClientes,char ***&pedidosLibros,
                       bool **&pedidosAtendidos){
    int numCli=0,capCli=0,*numPed,*capPed,numLibPed,capLibPed,codPed,dni,ind;
    int numLib = 0;
    char codigo[8];
    bool tieneStock;
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    pedidosLibros = nullptr,pedidosClientes = nullptr;
    while(1){   //Lectura del dni y numero de pedido
        numLibPed = 0,capLibPed = 0;
        archPed>>codPed;
        if(archPed.eof()) break;
        archPed.get();
        archPed>>dni;
        ind = buscarPosCliente(pedidosClientes,dni); //Parte 1
        if(ind==NO_ENCONTRADO){
            if(numCli==capCli)  //Parte 2
                aumentarCapPedCli(pedidosClientes,numPed,capPed,numCli,capCli);
            agregarCliente(pedidosClientes,numPed,capPed,numCli,ind,dni);   //Parte 3
        }
        agregarPedidos(pedidosClientes[ind],numPed[ind],capPed[ind],codPed);   //Parte 4
        if(numLib<codPed)   //Lectura de los codigos de los libros
            aumentarCapPedLib(pedidosLibros,pedidosAtendidos,codPed,numLib);   //Parte 5
        pedidosLibros[codPed] = nullptr;    
        while(1){
            archPed>>codigo;
            if(numLibPed==capLibPed)
                aumentarCapLibEnPed(pedidosLibros[codPed],pedidosAtendidos[codPed],
                                    numLibPed,capLibPed);   //Parte 6
            ind = buscarPosicionLib(libros,codigo); //Parte 7
            tieneStock = verificarStock(stock[ind]);
            agregarLibYAten(pedidosLibros[codPed],pedidosAtendidos[codPed],
                            codigo,tieneStock,numLibPed);   //Parte 8
            if(archPed.get()=='\n') break;
        }
    }
    agregarCantDePedidos(pedidosClientes,numPed);   //Parte 9
}
//Parte 1 (Busqueda de posicion de cliente para asignar pedidos al cliente)
int buscarPosCliente(int **pedidosClientes,int dni){
    int *auxPedCli;
    if(pedidosClientes!=nullptr)
        for(int i=0;pedidosClientes[i]!=nullptr;i++){
            auxPedCli = pedidosClientes[i];
            if(auxPedCli[0]==dni) return i;
        }
    return NO_ENCONTRADO;
}
//Parte 2 (Aumentar la capacidad del **pedidosClientes)
void aumentarCapPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                       int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    if(pedidosClientes==nullptr){
        pedidosClientes = new int*[capacidad];
        numPed = new int[capacidad];
        capPed = new int[capacidad];
        pedidosClientes[0] = nullptr;
        numPed[0] = 0;
        capPed[0] = 0;
        numDatos++;
    }else cambiarAuxAPuntPedCli(pedidosClientes,numPed,capPed,numDatos,
                                capacidad);
}

void cambiarAuxAPuntPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                           int numDatos,int capacidad){
    int **auxPedCli,*auxNumPed,*auxCapPed;
    auxPedCli = new int*[capacidad];
    auxNumPed = new int[capacidad];
    auxCapPed = new int[capacidad];
    for(int i=0;i<numDatos;i++){
        auxPedCli[i] = pedidosClientes[i];
        auxNumPed[i] = numPed[i];
        auxCapPed[i] = capPed[i];
    }
    delete pedidosClientes;
    delete numPed;
    delete capPed;
    pedidosClientes = auxPedCli;
    numPed = auxNumPed;
    capPed = auxCapPed;
}
//Parte 3 (Agregar cliente nuevo despues de o sin haber incrementado)
void agregarCliente(int **&pedidosClientes,int *numPed,int *capPed,int &numDatos,
                    int &indice,int dni){
    agregarCapacidad(pedidosClientes[numDatos-1],dni,numPed[numDatos-1],
                     capPed[numDatos-1]);   //Parte 3.1
    pedidosClientes[numDatos] = nullptr;
    numPed[numDatos] = 0;
    capPed[numDatos] = 0;
    indice = numDatos-1;
    numDatos++;
}
//Parte 3.1 (Crear una capacidad inicial del arreglo de pedidos del cliente)
void agregarCapacidad(int *&pedCliente,int dni,int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    pedCliente = new int[capacidad];
    pedCliente[0] = dni;
    pedCliente[1] = 0;
    numDatos += 2;
}
//Parte 4 (Agregar el numero de pedido que hizo el cliente)
void agregarPedidos(int *&pedCliente,int &numDatos,int &capacidad,int numPed){
    if(numDatos==capacidad)
        aumentarCapPedidos(pedCliente,numDatos,capacidad);  //Parte 4.1
    pedCliente[numDatos] = numPed;
    numDatos++;
}
//Parte 4.1 (Aumentar la capacidad del arreglo de pedidos)
void aumentarCapPedidos(int *&pedCliente,int numDatos,int &capacidad){
    int *auxPedCli;
    capacidad += INCREMENTO;
    auxPedCli = new int[capacidad];
    for(int i=0;i<numDatos;i++) auxPedCli[i] = pedCliente[i];
    delete pedCliente;
    pedCliente = auxPedCli;
}
//Parte 5 (Aumentar la capacidad de ***pedidosLibros y **pedidosAtendidos)
void aumentarCapPedLib(char ***&pedidosLibros,bool **&pedidosAtendidos,
                       int codPed,int &numLib){
    int numDatos = numLib;
    char ***auxPedLib;
    bool **auxPedAten;
    numLib = codPed+INCREMENTO;
    if(pedidosLibros==nullptr){
        pedidosLibros = new char**[numLib];
        pedidosAtendidos = new bool*[numLib];
        pedidosLibros[0] = nullptr;
        pedidosAtendidos[0] = nullptr;
    }else{
        auxPedLib = new char**[numLib];
        auxPedAten = new bool*[numLib];
        for(int i=0;i<numDatos;i++){
            auxPedLib[i] = pedidosLibros[i];
            auxPedAten[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxPedLib;
        pedidosAtendidos = auxPedAten;
    }
}
//Parte 6 (Incrementar la capacidad de los libros del pedido)
void aumentarCapLibEnPed(char **&pedLibros,bool *&pedAtendidos,int &numDatos,
                         int &capacidad){
    char **auxPedLib;
    bool *auxPedAten;
    capacidad += INCREMENTO;
    if(pedLibros==nullptr){
        pedLibros = new char*[capacidad];
        pedAtendidos = new bool[capacidad];
        pedLibros[0] = nullptr;
        pedAtendidos[0] = true;
        numDatos++;
    }else{
        auxPedLib = new char*[capacidad];
        auxPedAten = new bool[capacidad];
        for(int i=0;i<numDatos;i++){
            auxPedLib[i] = pedLibros[i];
            auxPedAten[i] = pedAtendidos[i];
        }
        delete pedLibros;
        delete pedAtendidos;
        pedLibros = auxPedLib;
        pedAtendidos = auxPedAten;
    }
}
//Parte 7 (Verificar si el pedido cuenta con stock para realizarse)
int buscarPosicionLib(char ***libros,char *codigo){
    char **auxLib;
    for(int i=0;libros[i]!=nullptr;i++){
        auxLib = libros[i];
        if(strcmp(auxLib[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

bool verificarStock(int *stock){
    if(stock[0]>0){
        stock[0]--;
        return true;
    }else{
        stock[1]++;
        return false;
    }
}
//Parte 8 (Agregar los datos del libro y si tiene stock)
void agregarLibYAten(char **pedLibros,bool *pedAtendidos,char *codigo,
                     bool tieneStock,int &numDatos){
    pedLibros[numDatos-1] = new char[strlen(codigo)+1];
    strcpy(pedLibros[numDatos-1],codigo);
    pedLibros[numDatos] = nullptr;
    pedAtendidos[numDatos-1] = tieneStock;
    pedAtendidos[numDatos] = true;
    numDatos++;
}
//Parte 9 (Agregar la cantidad de pedidos al arreglo de **pedidosClientes)
void agregarCantDePedidos(int **pedidosClientes,int *numPed){
    int *auxPedCli;
    for(int i=0;pedidosClientes[i]!=nullptr;i++){
        auxPedCli = pedidosClientes[i];
        auxPedCli[1] = numPed[i]-2;
    }
}
//Ordenamiento (De mayor a menor en cuanto cantidad de pedidos)
void ordenar(int **pedCli){
    int numDat = 0;
    while(pedCli[numDat]) numDat++;
    qSort(pedCli,0,numDat-1);
}

void qSort(int **pedCli,int izq,int der){
    int limite,pos,*auxPedCli1,*auxPedCli2;
    if(izq>=der) return;
    pos = (izq+der)/2;
    cambiar(pedCli[izq],pedCli[pos]);
    limite = izq;
    for(int i=izq+1;i<=der;i++){
        auxPedCli1 = pedCli[i];
        auxPedCli2 = pedCli[izq];
        if(auxPedCli1[1]>auxPedCli2[1] or 
          (auxPedCli1[1]==auxPedCli2[1] and auxPedCli1[0]<auxPedCli2[0])){
            limite++;
            cambiar(pedCli[limite],pedCli[i]);
        }
    }
    cambiar(pedCli[limite],pedCli[izq]);
    qSort(pedCli,izq,limite-1);
    qSort(pedCli,limite+1,der);
}

void cambiar(int *&pedCliI,int *&pedCliK){
    int *auxPedCli;
    auxPedCli = pedCliI;
    pedCliI = pedCliK;
    pedCliK = auxPedCli;
}
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos){
    int *auxPedCli;
    char **auxPedLib;
    bool *auxPedAten;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
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
    archRep<<setw(85)<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
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