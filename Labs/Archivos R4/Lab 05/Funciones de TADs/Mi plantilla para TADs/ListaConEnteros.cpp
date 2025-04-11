/* 
 * File:   ListaConEnteros.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 20:33
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaConEnteros.h"
void *leenumero(ifstream &archReg){
    int *dato,d;
    archReg>>d;
    if(archReg.eof()) return nullptr;
    dato = new int;
    *dato = d;
    return dato;
}

int cmpnumero(void *a,void *b){
    int *num1,*num2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    
    num1 = (int*)aux1[0];
    num2 = (int*)aux2[0];
    return *num1-*num2;
}

void imprimenum(ofstream &archRep,void *dato){
    int *num;
    num = (int*)dato;
    
    archRep<<*num<<endl;
}