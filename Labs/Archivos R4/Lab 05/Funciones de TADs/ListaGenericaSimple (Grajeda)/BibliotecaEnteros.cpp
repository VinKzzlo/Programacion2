/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaEnteros.cpp
 * Author: ISA
 * 
 * Created on 27 de abril de 2024, 05:22 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cmath>
#include "BibliotecaEnteros.h"


int* almacenaEntero(int entero){
    return new int{entero};
}
void* copiaEntero(void* entero){
    int *ptrentero = (int*)entero;
    int *copia = new int{*ptrentero};
    return copia;
}
void eliminarEntero(void *entero){
    int *ptr = (int*)entero;
    delete ptr;
}
void mostrarEntero(void *entero){
    int *ptrentero = (int*)entero;
    cout << *ptrentero;
}
void ImprimirEntero(ofstream &arch,int pos,void *entero){
    int *ptrentero = (int*)entero;
    int tam = 0;
//    if(*ptrentero != 0)tam = trunc(log10(fabs((double)*ptrentero)))+1;
    arch << pos <<left << setw(10 - tam)<<')'<<right<<setw(10)<<*ptrentero;
}

bool enterosIguales(void* EnteroI,void* EnteroK){
    int *ptrI = (int*)EnteroI,*ptrK = (int*)EnteroK;
    return *ptrI == *ptrK;
}
int compararEnteros(void* EnteroI,void* EnteroK){
    int *ptrI = (int*)EnteroI,*ptrK = (int*)EnteroK;
    return *ptrI - *ptrK;
}
void incrementarCantidadEnteros(void *&cantidad,void *entero){
    int *ptrcantidad = (int*)cantidad;
    if(cantidad == nullptr){
        ptrcantidad = new int{1};
        cantidad = ptrcantidad;
    } else (*ptrcantidad)++;
}
void decrementarCantidadEnteros(void *&cantidad,void *entero){
    int *ptrcantidad = (int*)cantidad;
    (*ptrcantidad)--;
    if(*ptrcantidad == 0){
        delete ptrcantidad;
        cantidad = nullptr;
    }
}
void UnirCantidadEnteros(void *cantidadP,void *&cantidadS){
    int *ptrcantidadP = (int*)cantidadP;
    int *ptrcantidadS = (int*)cantidadS;
    if(cantidadP != nullptr and cantidadS != cantidadS){
        *ptrcantidadP += *ptrcantidadS;
    }
    delete ptrcantidadS;
    cantidadS = nullptr;
}
void eliminarCantidadEnteros(void *&cantidad){
    int *ptrcantidad = (int*)cantidad;
    delete ptrcantidad;
    cantidad = nullptr;
}
void mostrarInformacionCantidad(void *cantidad){
    int *ptrcantidad = (int*)cantidad;
    cout << "Numero de enteros: "<< *ptrcantidad << endl;
}
void ImprimirInformacionCantidad(ofstream &arch,void *cantidad){
    int *ptrcantidad = (int*)cantidad;
    arch << "Numero de enteros: "<< *ptrcantidad << endl;
}

void incrementarSumaEnteros(void *&registro,void *entero){
    void **info = (void**) registro;
    int *cantidad,*suma;
    int *ptrentero = (int*)entero;
    if(registro == nullptr){
        info = new void*[2];
        cantidad = (int*)info[0];
        suma = (int*)info[1];
        cantidad = new int{1};
        suma = new int{*ptrentero};
        info[0] = cantidad;
        info[1] = suma;
        registro = info;
    }else{
        cantidad = (int*) info[0];
        suma = (int*) info[1];
        (*cantidad)++;
        *suma += *ptrentero;
    }
}
void decrementarSumaEnteros(void *&registro,void *entero){
    void **info = (void**) registro;
    int *cantidad = (int*)info[0],*suma = (int*)info[1];
    int *ptrentero = (int*)entero;
    (*cantidad)--;
    *suma -= *ptrentero;
    if(*cantidad == 0){
        delete cantidad;
        delete suma;
        delete info;
        registro = nullptr;
    }
}


void UnirCantidadSumaEnteros(void *registroP,void *&registroS){
    void **infoP = (void**)registroP;
    void **infoS = (void**)registroS;
    int *cantidadP = (int*)infoP[0],*sumaP = (int*)infoP[1];
    int *cantidadS = (int*)infoS[0],*sumaS = (int*)infoS[1];
    if(registroP != nullptr and registroS != cantidadS){
        *cantidadP += *cantidadS;
        *sumaP += sumaS;
    }
    delete cantidadS;
    delete sumaS;
    delete infoS;
    registroS = nullptr;
}
void eliminarSumaEnteros(void *&registro){
    void **info = (void**)registro;
    int *cantidad = (int*)info[0];
    int *suma = (int*)info[1];
    delete cantidad;
    delete suma;
    delete info;
    registro = nullptr;
}
void mostrarInformacionSuma(void *registro) {
    void **info = (void**) registro;
    int *cantidad = (int*)info[0], *suma = (int*)info[1];
    cout << "Numero de enteros: "<< *cantidad << endl;
    cout << "Suma de enteros: "<<*suma <<endl;
}
void ImprimirInformacionSuma(ofstream &arch,void *registro) {
    void **info = (void**) registro;
    int *cantidad = (int*)info[0], *suma = (int*)info[1];
    arch << "Numero de enteros: "<< *cantidad << endl;
    arch << "Suma de enteros: "<<*suma <<endl;
}