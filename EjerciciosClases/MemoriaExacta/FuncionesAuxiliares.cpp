/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 28 de agosto de 2024, 8:41
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"

void leerDatosDeManeraExacta(int *&datos2,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int buffer[100], dato;
    int numDat=0;
    while(true){
        arch>>dato;
        if(arch.eof())break;
        buffer[numDat]=dato;
        numDat++;
    }
    /*
     * int datos[numDat]{};
     * corregir esta parte
     */
    
    for(int i=0;i<numDat;i++){
        datos[i] = buffer[i];
    }
    
}

void imprimirDatos(int *&datos2,const char *nombArch){
    
}