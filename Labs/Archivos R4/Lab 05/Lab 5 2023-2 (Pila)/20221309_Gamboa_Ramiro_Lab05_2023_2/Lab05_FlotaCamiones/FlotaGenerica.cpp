/* 
 * File:   FlotaGenerica.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 23:51
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FlotaGenerica.h"
void cargacamiones(void *&flota,int numcamiones,double pesomaximo,
                   void*(*lee)(ifstream &),double(*calcula)(void *),
                   const char *nombArch){
    void *dato;
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(int i=0;i<numcamiones;i++){
        
    }
}