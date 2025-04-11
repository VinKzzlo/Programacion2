/* 
 * Archivo:   Funciones.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 10:15
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Funciones.h"

char *leeCadena(ifstream &arch,int max,char delim ){
    char buff[max], *cad;
    arch.getline(buff,100,delim);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeLinea(ofstream &arch, char c,int max){
    for(int i=0;i<max;i++)
        arch.put(c);
    arch<<endl;
}