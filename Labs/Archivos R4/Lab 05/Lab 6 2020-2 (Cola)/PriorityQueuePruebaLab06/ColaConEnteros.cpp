/* 
 * File:   ColaConEnteros.cpp
 * Author: ramir
 * 
 * Created on 13 de mayo de 2024, 22:07
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ColaConEnteros.h"
/*
Prioridad Numero
2 3
4 1
*/
void *leenumero(ifstream &archReg){
    void **registro;
    int *prioridad,*dato;
    
    prioridad = new int;
    archReg>>*prioridad;
    if(archReg.eof()) return nullptr;
    dato = new int;
    archReg>>*dato;
    
    registro = new void*[2];
    registro[0] = prioridad;
    registro[1] = dato;
    return registro;
}

int prioridadnum(void *dato){
    void **registro = (void**)dato;
    int *prioridad;
    prioridad = (int*)registro[0];
    return *prioridad;
}

void imprimenum(ofstream &archRep,void *dato){
    void **registro = (void**)dato;
    int *num1,*num2;
    num1 = (int *)registro[0];
    num2 = (int *)registro[1];
    
    archRep<<*num1<<" "<<*num2<<endl;
}