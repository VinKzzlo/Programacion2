/* 
 * File:   FuncionesRegistros.cpp
 * Author: ramir
 * 
 * Created on 12 de mayo de 2024, 00:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesRegistros.h"
/*
2,14268463,BHD6079
7,42302422,RWW7975
*/
void *leeregistro(ifstream &archReg){
    void **registro;
    int *numPed,*dni;
    char *codLibro;
    
    numPed = new int;
    archReg>>*numPed;
    if(archReg.eof()) return nullptr;
    archReg.get();
    dni = new int;
    archReg>>*dni;
    archReg.get();
    codLibro = LeeCadenaExacta(archReg,8,'\n');
    
    registro = new void*[3];
    registro[0] = numPed;
    registro[1] = dni;
    registro[2] = codLibro;
    return registro;
}

char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeregistro(ofstream &archRep,void *dato){
    void **registro = (void**)dato;
    
    int *numPed = (int*)registro[0];
    int *dni = (int*)registro[1];
    char *codLibro = (char*)registro[2];
    
    archRep<<left<<setw(10)<<*numPed<<setw(10)<<*dni<<setw(10)<<codLibro<<endl;
}

int cmpregistro(void *a,void *b){
    if(a==nullptr) return -1;
    if(b==nullptr) return 1;
    int *numPed1,*numPed2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    void **registro1 = (void**)aux1[0];
    void **registro2 = (void**)aux2[0];
    
    numPed1 = (int*)registro1[0];
    numPed2 = (int*)registro2[0];
    return *numPed2-*numPed1;
}