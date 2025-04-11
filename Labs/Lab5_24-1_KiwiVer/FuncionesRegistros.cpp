/* 
 * Archivo:   FuncionesRegistros.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesRegistros.h"

void *leeregistro(ifstream &arch){
    void **registro;
    int *numPed, *dni;
    char *codLibro;
    
    numPed = new int;
    arch>>*numPed;
    if(arch.eof())return nullptr;
    arch.get();
    dni = new int;
    arch>>*dni;
    arch.get();
    codLibro = leeCadenaExacta(arch);
    
    registro = new void*[3]{};
    registro[0] = numPed;
    registro[1] = dni;
    registro[2] = codLibro;
    return registro;
}

char *leeCadenaExacta(ifstream &arch,char delim){
    char *cadena, buffer[50];
    arch.getline(buffer,50,delim);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void imprimeregistro(ofstream &arch, void* dato){
    void **registro = (void**)dato;
    
    int *numPed = (int*)registro[0];
    int *dni = (int*)registro[1];
    char *codLibro = (char*)registro[2];
    
    arch<<left<<setw(10)<<*numPed<<right<<setw(15)<<*dni
        <<setw(5)<<' '<<left<<setw(10)<<codLibro<<endl;
    
}

int cmpregistro(void *a, void *b){
    if(a==nullptr) return  1;
    if(b == nullptr) return -1;
    
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    
    void **registro1 = (void**)aux1[0];
    void **registro2 = (void**)aux2[0];
    int *numPed1 = (int*)registro1[0], *numPed2 = (int*)registro2[0];
    
    return *numPed1 - *numPed2;
}