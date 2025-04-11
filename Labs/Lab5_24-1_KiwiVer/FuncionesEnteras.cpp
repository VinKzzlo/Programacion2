/* 
 * Archivo:   FuncionesEnteras.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesEnteras.h"

void *leenum(ifstream &arch){
    int *ptrDato, dato;
    
    arch>>dato;
    if(arch.eof())return nullptr;
    ptrDato = new int;
    *ptrDato = dato;
    return ptrDato;
}

void imprimenum(ofstream &arch, void *dato){
    int *numero = (int*)dato;
    
    arch<<*numero<<endl;
    
}

int cmpnum( void *a,  void *b){
    if(a==nullptr) return 1;
    if(b==nullptr) return -1;
    int *num1, *num2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    num1 = (int*)aux1[0];
    num2 = (int*)aux2[0];
    return *num1 - *num2;
}