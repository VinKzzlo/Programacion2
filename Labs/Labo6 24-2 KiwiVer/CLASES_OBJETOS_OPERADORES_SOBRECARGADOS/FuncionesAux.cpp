/* 
 * Archivo:   FuncionesAux.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 21:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "FuncionesAux.h"

char *leeCadenaExacta(ifstream &arch, int max, char delim){
    char buffer[max], *cad;
    arch.getline(buffer,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void imprimeLinea(ofstream &arch,int cant, char car){
    for(int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}