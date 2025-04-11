/* 
 * File:   PilaConEnteros.cpp
 * Author: ramir
 * 
 * Created on 30 de abril de 2024, 10:06
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"
void *leenumero(ifstream &arch){
    int *dato,d;
    
    arch>>d;
    if(arch.eof()) return nullptr;
    dato = new int;
    *dato = d;
    return dato;
}

int cmpnumero(const void *a,const void *b){
    int *num1,*num2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    
    num1 = (int*)(*aux1);
    num2 = (int*)(*aux2);
    
    return *num2 - *num1;
}

void imprimenumero(ofstream &archRep,void *dato){
    int *num;
    
    num = (int*)dato;
    archRep<<*num<<endl;
}