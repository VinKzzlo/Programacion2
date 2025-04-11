/* 
 * Archivo:   MetodoExactoDeMemoria.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  12 de septiembre de 2024, 16:06
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#define NOT_FOUND -1

void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **buffLibros[300]{}, **datLibro;
    int *buffStock[300]{}, numLibros=0;
    
    while(true){
        datLibro = leerDatLibro(arch);
        if(arch.eof()) break;
        buffLibros[numLibros] = datLibro;
        buffStock[numLibros] = leerStock(arch);
        numLibros++;
    }
    libros = new char **[numLibros+1]{};
    stock = new int *[numLibros+1]{};
    for(int i=0;i<numLibros;i++){
        libros[i] = buffLibros[i];
        stock[i] = buffStock[i];
    }
    
}

char **leerDatLibro(ifstream &arch){
    char *codigo, **datLibro;
    codigo = leeCadenaExacta(arch,',');
    if(arch.eof()) return nullptr;
    datLibro = new char *[3];
    datLibro[0] = codigo;
    datLibro[1] = leeCadenaExacta(arch,','); //Titulo
    datLibro[2] = leeCadenaExacta(arch,','); //Autor
    return datLibro;
}

int *leerStock(ifstream &arch){
    int *datStock;
    double precio;
    char c;
    datStock = new int[2]{};
    arch>>datStock[0]>>c>>precio;
    arch.get();//Saco el cambio de línea
    return datStock;
}

char *leeCadenaExacta(ifstream &arch,char delim){
    char buffer[100], *cadena;
    arch.getline(buffer,100,delim);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock){
    //Codigo Titulo Autor Stock CantNoAtend
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"CODIGO"<<setw(60)<<"TITULO"<<setw(40)<<"AUTOR"
        <<setw(10)<<"STOCK"<<"CANTIDAD NO ATENDIDA"<<endl;
    for(int i=0;libros[i];i++){
        imprimeLibro(libros[i],stock[i],arch);
    }
    
    
}
void imprimeLibro(char **libro,int *stock,ofstream &arch){
    arch<<left<<setw(10)<<libro[0]<<setw(60)<<libro[1]<<setw(40)<<libro[2]
        <<right<<setw(5)<<stock[0]<<setw(10)<<stock[1]<<endl;
}

void atencionDePedidos(const char *nombArch,char ***libros, int **stock,
                       int **&pedidosClientes, char ***&pedidosLibros, 
                       bool **&pedidosAtendidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int *buffPedCli[200]{}, numPed, dni, cantCli=0, cantLib[200]{};
    char **buffPedLib[200]{}, c, codLib[8];
    bool *buffPedAtend[200]{};
    inicializarBuffers(buffPedCli,buffPedLib,buffPedAtend);
    while(true){
        arch>>numPed;
        if(arch.eof())break;
        arch>>c>>dni;
        asignarPedidoACliente(numPed,dni,buffPedCli,cantCli);
        while(true){
            arch>>codLib;
            asignarLibros(codLib,buffPedLib[numPed-1],buffPedAtend[numPed-1],
                          cantLib[numPed-1],libros,stock);
            if(arch.get()=='\n') break;
        }
    }
    
    
}

void inicializarBuffers(int **buffPedCli,char ***buffPedLib, bool **buffPedAtend){
    for(int i=0;i<200;i++){
        buffPedCli[i] = new int[20]{};
        buffPedLib[i] = new char *[10]{};
        buffPedAtend[i] = new bool[10]{};
    }
}

void asignarPedidoACliente(int numPed,int dni,int **buffPedCli,int &cantCli){
    int posCli, *cliente;
    posCli = buscarCliente(dni,buffPedCli,cantCli);
    if(posCli == NOT_FOUND){
        cliente = buffPedCli[cantCli];
        cliente[0] = dni;
        cantCli++;
    }
    else
        cliente = buffPedCli[posCli];
    cliente[2+cliente[1]] = numPed;
    cliente[1]++;
}

int buscarCliente(int dni,int **buffPedCli,int cantCli){
    int *cliente;
    for(int i=0;i<cantCli;i++){
        cliente = buffPedCli[i];
        if(cliente[0]==dni) return i;
    }
    return NOT_FOUND;
}

void asignarLibros(char *codLib,char **buffPedLib,bool *buffPedAtend,
                   int &cantLib, char ***libros,int **stock){
    int posLibro, *auxStock;
    posLibro = buscarLibro(libros,codLib);
    if(posLibro != NOT_FOUND){
        buffPedLib[cantLib] = codLib;
        auxStock = stock[posLibro];
        if(auxStock[0]>0){
            buffPedAtend[cantLib] = true;
            auxStock[0]--;
        }
        else{
            buffPedAtend[cantLib] = false;
            auxStock[1]++;
        }
        cantLib++;                    
    }
            
    
}

int buscarLibro(char ***libros,char *codLib){
    char **aux;
    for(int i=0;libros[i]!=nullptr;i++){
        aux = libros[i];
        if(strcmp(aux[0],codLib)==0) return i;
    }
    return NOT_FOUND;
}