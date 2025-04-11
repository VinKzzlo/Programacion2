/* 
 * Archivo:   FuncionesDeCadenas.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "FuncionesDeCadenas.h"

void*leeCadena(ifstream &arch){
    char buffer[60], *cad;
    arch.getline(buffer,60);
    cad = new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

int miStrcmp(const void*a, const void *b){
    char *ai = (char*)a,*bi = (char*)b;
    return strcmp(ai,bi);
}

void imprimeStr(ofstream &arch, void*dato){
    char *cadena = (char*)dato;
    arch << cadena << endl;
}

void eliminaStr(void*dato){
    char *cadena = (char*)dato;
    delete cadena;
}