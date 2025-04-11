/* 
 * Archivo:   MetodoPorIncrementos.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 18:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoPorIncrementos.h"
#define INCREMENTO 5



void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numDat=0, cap=0, *regStock;
    char **regLibro;
    libros = nullptr;
    while(true){
        regLibro = leerLibro(arch);
        if(arch.eof())break;
        regStock = leerStock(arch);
        if(numDat==cap)
            aumentarEspacios(libros,stock,numDat,cap);
        agregarRegs(libros,stock,regLibro,regStock,numDat);
    }
}
char **leerLibro(ifstream &arch){
    char **regLibro, *codigo;
    codigo = leeCadenaExacta(arch,8,',');
    if(arch.eof())return nullptr;
    regLibro = new char*[3]{};
    regLibro[0] = codigo;
    regLibro[1] = leeCadenaExacta(arch,65,',');
    regLibro[2] = leeCadenaExacta(arch,40,',');
    return regLibro;
}

char *leeCadenaExacta(ifstream &arch,int max,char delim){
    char buffer[max], *cadena;
    arch.getline(buffer,max,delim);
    if(arch.eof()) return nullptr;
    cadena = new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

int *leerStock(ifstream &arch){
    double precio;
    int *regStock;
    char c;
    regStock = new int[2]{};
    arch>>regStock[0]>>c>>precio;
    arch.get();//Sacamos el salto de linea
    return regStock;
}

void aumentarEspacios(char ***&libros,int **&stock,int &numDat,int &cap){
    int **auxStock;
    char ***auxLibro;
    cap += INCREMENTO;
    if(libros==nullptr){
        libros = new char **[cap]{};
        stock = new int *[cap]{};
        numDat++;
    }
    else{
        auxLibro = new char **[cap]{};
        auxStock = new int *[cap]{};
        for(int i=0;i<numDat;i++){
            auxLibro[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxLibro;
        stock = auxStock;
    }
}

void agregarRegs(char ***libros,int **stock,
                 char **regLibro,int *regStock,int &numDat){
    libros[numDat-1] = regLibro;
    stock[numDat-1] = regStock;
    numDat++;
}

void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock){
    int *auxStock;
    char **auxLib;
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"CODIGO"<<setw(65)<<"TITULO"<<setw(40)<<"AUTOR"
        <<setw(7)<<"STOCK"<<"CANTIDAD NO ATENDIDA"<<endl;
    for(int i=0;libros[i];i++){
        auxStock = stock[i];
        auxLib = libros[i];
        arch<<left<<setw(10)<<auxLib[0]<<setw(65)<<auxLib[1]<<setw(40)<<auxLib[2]
            <<setw(3)<<' '<<right<<setw(2)<<auxStock[0]<<setw(6)<<auxStock[1]<<endl;
    }
    
}