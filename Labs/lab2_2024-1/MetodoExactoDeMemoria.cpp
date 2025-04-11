/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: Bleak
 * 
 * Created on September 12, 2024, 9:27 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros (const char *nomb,char ***&libros, int **&stock){
    ifstream arch(nomb,ios::in);
    char **bufflibros[300];
    char **libro;
    int i=0, *buffstock[300];
    while(true){
        libro = obtienelibro(arch);
        if(libro == nullptr) break;
        buffstock[i] = obtienestock(arch);
        bufflibros[i] = libro;
        i++;
    }
    libros = new char **[i+1];
    stock = new int *[i+1];
    for(int j=0;j<i;j++){
        libros[j] = bufflibros[j];
        stock[j] = buffstock[j];
    }
    libros[i] = nullptr;
    stock[i] = nullptr;
}

char **obtienelibro(ifstream &arch){
    char **triple = new char *[3];
    char *codigo, *nombre, *autor;
    codigo = leecadenaexacta(arch,',');
    if(codigo == nullptr) return nullptr;
    nombre = leecadenaexacta(arch,',');
    autor = leecadenaexacta(arch,',');
    triple[0] = codigo;
    triple[1] = nombre;
    triple[2] = autor;
    return triple;
}

int *obtienestock(ifstream &arch){
    double precio;
    int *dupla = new int[2];
    arch>>dupla[0];
    arch.get();
    arch>>precio;
    arch.get();
    dupla[1] = 0;
    return dupla;
}

char *leecadenaexacta(ifstream &arch, char delim){
    char buff[100], *cad;
    arch.getline(buff,100,',');
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void pruebaDeLecturaDeLibros (const char *nomb,char ***libros, int **stock){
    ofstream arch(nomb,ios::out);
    arch<<"REPORTE DE LIBROS"<<endl<<endl;
    arch<<"CODIGO"<<setw(20)<<"TITULO"<<setw(60)<<"AUTOR"<<endl;
    char **auxlibro;
    int *auxstock;
    for(int i=0;libros[i]!=nullptr;i++){
        auxlibro = libros[i];
        auxstock = stock[i];
        arch<<left<<setw(10)<<auxlibro[0]<<setw(60)<<auxlibro[1]<<setw(30)<<auxlibro[2]<<auxstock[0]<<endl;
    }
}

void atencionDePedidos (const char *nomb, char ***libros, int **stock, int **&pedidosClientes,
        char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream arch(nomb,ios::in);
    int *buffpedcli[200]{}, tampedlib[200]{}, tampedcli[200]{};
    char **buffpedlib[200]{};
    bool *buffpedAt[200];
    int pedido, cliente, ncli=0, nped=1;
    char *cod;
    for(int i=0;i<200;i++){
        buffpedlib[i] = new char *[10];
        buffpedAt[i] = new bool [10];
    }
    while(true){
        arch>>pedido;
        if(arch.eof()) break;
        arch.get();
        arch>>cliente;
        guardacliente(cliente,pedido,buffpedcli,ncli,tampedcli);
        while(true){
            cod = leecadena(arch);
            guardarlibro(buffpedlib[pedido],cod,buffpedAt[pedido],tampedlib[pedido],libros,stock);
            if (arch.get()=='\n') break;
        }
        nped++;
    }
    cargapedlib(buffpedlib,buffpedAt,tampedlib,nped,pedidosLibros,pedidosAtendidos);
    cargapedcli(buffpedcli,tampedcli,ncli,pedidosClientes);
}

void guardacliente(int cliente,int pedido, int **buffpedcli,int &ncli, int *tampedcli){
    int posCli = buscacli(cliente, buffpedcli);
    int *aux;
    if(posCli==-1){
        buffpedcli[ncli] = new int [20];
        aux = buffpedcli[ncli];
        aux[0] = cliente;
        aux[1] = 0;
        tampedcli[ncli] = 2;
        posCli=ncli;
        ncli++;
    }
    aux = buffpedcli[posCli];
    aux[tampedcli[posCli]] = pedido;
    tampedcli[posCli]++;
}

int buscacli(int cliente, int **buffpedcli){
    int *aux;
    for(int i=0;buffpedcli[i]!=nullptr;i++){
        aux=buffpedcli[i];
        if(aux[0]==cliente) return i;
    }
    return -1;
}

void guardarlibro(char **buffpedlib,char *cod, bool *buffpedAt,int &n, char ***libros, int **stock){
    int posLibro = buscaLibro(libros,cod);
    int *dupla;
    if(posLibro!=-1){
        buffpedlib[n] = cod;
        dupla = stock[posLibro];
        if(dupla[0] > 0){
            buffpedAt[n] = true;
            dupla[0]--;
        }else buffpedAt[n] = false;
        n++;
    }
}

int buscaLibro(char ***libros, char *cod){
    char **triple;
    for(int i=0;libros[i]!=nullptr;i++){
        triple = libros[i];
        if(strcmp(triple[0],cod)==0) return i;
    }
    return -1;
}

char *leecadena(ifstream &arch){
    char buff[100], *cad;
    arch>>buff;
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void cargapedlib(char ***buffpedlib,bool **buffpedAt,int *tampedlib,int nped,char ***&pedidosLibros,bool **&pedidosAtendidos){
    pedidosLibros = new char **[nped+2]{};
    pedidosAtendidos = new bool *[nped+2]{};
    char **auxchar, **auxfchar;
    bool *auxbool, *auxfbool;
    for(int i=1;i<nped+1;i++){
        pedidosLibros[i] = new char *[tampedlib[i]+1];
        pedidosAtendidos[i] = new bool [tampedlib[i]+1];
        auxfchar = pedidosLibros[i];
        auxfbool = pedidosAtendidos[i];
        auxchar = buffpedlib[i];
        auxbool = buffpedAt[i];
        for(int j=0;j<tampedlib[i];j++){
            auxfchar[j] = auxchar[j];
            auxfbool[j] = auxbool[j];
        }
        auxfchar[tampedlib[i]] = nullptr;
        delete auxchar;
        delete auxbool;
    }
    pedidosLibros[nped+1] = nullptr;
    pedidosAtendidos[nped+1] = nullptr;
}

void cargapedcli(int **buffpedcli,int *tampedcli,int ncli,int **&pedidosClientes){
    int *aux, *auxf;
    pedidosClientes = new int *[ncli+1];
    for(int i=0;i<ncli;i++){
        aux = buffpedcli[i];
        pedidosClientes[i] = new int [tampedcli[i]+1];
        auxf = pedidosClientes[i];
        for(int j=0;j<tampedcli[i];j++){
            auxf[j] = aux[j];
        }
        auxf[tampedcli[i]] = 0;
        delete aux;
    }
    pedidosClientes[ncli] = nullptr;
}

void reporteDeEntregaDePedidos (const char *nomb, int **pedidosClientes, char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream arch(nomb,ios::out);
    int *aux;
    if(!arch){
        cout<<"No se encontro el archivo "<<nomb;
        exit(1);
    }
    arch << setw(60)<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    for(int i=0;pedidosClientes[i]!=nullptr;i++){
        aux = pedidosClientes[i];
        arch<<"CLIENTE: "<<aux[0]<<endl;
        imprimirlinea('=',80,arch);
        imprimePorLibro(pedidosClientes[i],pedidosLibros,pedidosAtendidos,arch);
        imprimirlinea('=',80,arch);
    }
}

void imprimePorLibro(int *pedidos, char ***pedLib, bool **pedAt, ofstream &arch){
    char **aux;
    bool *auxbool;
    for(int i=2;pedidos[i]!=0;i++){
        if(i!=2) imprimirlinea('-',80,arch);
        arch<<setw(20)<<"Pedido No."<<setw(20)<<"Codigo del libro"<<setw(20)<<"Observacion"<<endl;
        imprimirlinea('-',80,arch);
        arch<<setw(10)<<' '<<setfill('0')<<setw(6)<<pedidos[i]<<setfill(' ')<<setw(14)
                <<' '<<left;
        aux = pedLib[pedidos[i]];
        auxbool = pedAt[pedidos[i]];
        for(int j=0;aux[j]!=nullptr;j++){
            if(j!=0) arch<<setw(30)<<' ';
            arch<<setw(20)<<aux[j];
            if(auxbool[j]) arch<<"ATENDIDO"<<endl;
            else arch<<"NO ATENDIDO"<<endl;
        }
        arch<<right;
    }
}

void imprimirlinea(char simbolo, int cant, ofstream &arch){
    for(int i=0;i<cant;i++) arch.put(simbolo);
    arch<<endl;
}