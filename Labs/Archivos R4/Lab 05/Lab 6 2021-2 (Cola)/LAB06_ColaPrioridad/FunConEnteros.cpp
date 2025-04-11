/* 
 * File:   FunConEnteros.cpp
 * Author: ramir
 * 
 * Created on 27 de abril de 2024, 21:20
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FunConEnteros.h"
void *leenumero(ifstream &arch){
    int *dato,d;
    
    arch>>d;
    if(arch.eof()) return nullptr;
    dato = new int;
    *dato = d;
    
    return dato;
}

int prioridadnumero(void *dato){
    int *prioridad = (int*)dato;
    
    if(*prioridad<50) return 3;
    else if(*prioridad>=50 and *prioridad<=100) return 2;
    else return 1;
}

void imprimirnum(void *cola,const char *nombArch){
    int *num,i=0;
    void **quinpleta = (void **)cola;
    void *dato,**aux;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    aux = (void**)quinpleta[0];
    while(aux){
        dato = aux[0];
        num = (int*)dato;
        archRep<<*num<<endl;
        aux = (void**)aux[1];
    }
    while(i<3){
        aux = (void**)quinpleta[i+1];
        dato = aux[0];
        num = (int*)dato;
        archRep<<"Prioridad "<<i+1<<": "<<*num<<endl;
        i++;
    }
    delete num;
}