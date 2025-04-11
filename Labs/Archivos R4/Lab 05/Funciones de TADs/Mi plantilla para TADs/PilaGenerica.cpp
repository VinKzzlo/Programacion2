/* 
 * File:   PilaGenerica.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 20:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaGenerica.h"
void generapila(void *&pila){
    int *dato;
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dato = new int;
    *dato = 0;
    dupla[1] = dato;
    pila = dupla;
}

void push(void *pila,void *dato){
    void **dupla = (void**)pila;
    void **nuevo;
    int *cont;
    
    nuevo = new void*[2];
    nuevo[0] = dupla[0];
    nuevo[1] = dato;
    
    dupla[0] = nuevo;
    cont = (int*)dupla[1];
    (*cont)++;
}

void *pop(void *pila){
    int *cont;
    void **dupla = (void**)pila,*dato = nullptr,**aux;
    
    if(!pilavacia(pila)){
        aux = (void**)dupla[0];
        dato = aux[1];
        dupla[0] = aux[0];
        aux[0] = nullptr;
        cont = (int*)dupla[1];
        (*cont)--;
        delete aux;
    }
    return dato;
}

bool pilavacia(void *pila){
    void **dupla = (void**)pila;
    if(dupla[0]==nullptr) return true;
    return false;
}