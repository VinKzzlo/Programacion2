/* 
 * Archivo:   FunciionesDeEnteros.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FunciionesDeEnteros.h"

int miCmpInt(const void *a, const void *b){
    int *ai = (int*)a, *bi= (int*)b;
    return *ai-*bi;
}

void *leerInt(ifstream &arch){
    int dato, *ptDato;
    arch >> dato;
    if(arch.eof()) return nullptr;
    ptDato = new int;
    *ptDato = dato;
    return ptDato;
}

void imprimeInt(ofstream &arch,void*d){
    int *dato = (int*)d;
    arch << setw(5) << *dato;
}

void eliminaInt(void *d){
    int *dato = (int*)d;
    delete dato;
}