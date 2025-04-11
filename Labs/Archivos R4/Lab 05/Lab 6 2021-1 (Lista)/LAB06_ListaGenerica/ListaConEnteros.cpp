/* 
 * File:   ListaConEnteros.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 23 de abril de 2024, 10:49
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
/*
35912665,O2Z-308,22/07/2019,156
32244565,M8W-853,18/11/2019,335
*/
void *leenum(ifstream &arch){
    int licencia,dd,mm,aa,*fecha,infraccion;
    char placa[8],c;
    
    arch>>licencia;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(placa,8,',');
    arch>>dd>>c>>mm>>c>>aa>>c>>infraccion;
    fecha = new int;
    *fecha = aa*10000+mm*100+dd;
    return fecha;
}

int cmpnum(void *a,void *b){
    void **ai = (void**)a,**bi = (void**)b;
    int *n1 = (int *)ai[0],*n2 = (int *)bi[0];
    return *n1-*n2;
}

void imprimenum(void *dato,ofstream &arch){
    int *fecha;
    fecha = (int *)dato;
    
    arch<<*fecha<<endl;
}