/* 
 * File:   ColaGenerica.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 20:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ColaGenerica.h"
void creaCola(void *&cola,void*(*lee)(ifstream &),int(*cmp)(void *,void *),
              const char *nombArch){
    void *dato;
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    generacola(cola);
    while(1){
        dato = lee(archReg);
        if(archReg.eof()) break;
        encola(cola,dato,cmp);
    }
}

void generacola(void *&cola){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    cola = dupla;
}

void encola(void *cola,void *dato,int(*cmp)(void *,void *)){
    void **dupla = (void**)cola;
    void **nuevo,**aux;
    nuevo = new void*[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    if(colavacia(cola)){
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        aux = (void**)dupla[1];
        aux[1] = nuevo;
        dupla[1] = nuevo;
    }
}

bool colavacia(void *cola){
    void **dupla = (void**)cola;
    if(dupla[0]==nullptr) return true;
    return false;
}

void *desencola(void *cola){
    
    if(colavacia(cola)) return nullptr;
    
    void **dupla = (void**)cola;
    void **colaIni = (void**)dupla[0];
    void **penultimo,*dato;
    
    if(dupla[0]==dupla[1]){
        dupla[0] = nullptr;
        dupla[1] = nullptr;
    }else{
        penultimo = (void**)colaIni[1];
        dupla[0] = penultimo;
        colaIni[1] = nullptr;
    }
    dato = colaIni[0];
    delete colaIni;
    return dato;
}