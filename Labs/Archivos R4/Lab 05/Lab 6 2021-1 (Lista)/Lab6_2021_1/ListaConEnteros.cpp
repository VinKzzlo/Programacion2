/* 
 * File:   ListaConEnteros.cpp
 * Author: ramir
 * 
 * Created on 30 de abril de 2024, 22:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaConEnteros.h"
/*
35912665,O2Z-308,22/07/2019,156
32244565,M8W-853,18/11/2019,335
*/
void *leenum(ifstream &archReg){
    int licencia,dd,mm,aa,*fecha,infraccion;
    char placa[8],c;
    
    archReg>>licencia;
    if(archReg.eof()) return nullptr;
    archReg.get();
    archReg.getline(placa,8,',');
    archReg>>dd>>c>>mm>>c>>aa>>c>>infraccion;
    fecha = new int;
    *fecha = aa*10000+mm*100+dd;
    return fecha;
}

int cmpnum(void *a,void *b){
    int *num1,*num2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    
    num1 = (int*)aux1[0];
    num2 = (int*)aux2[0];
    return *num2-*num1;
}

void imprimenum(ofstream &archRep,void *dato){
    int *fecha;
    fecha = (int*)dato;
    archRep<<*fecha<<endl;
}