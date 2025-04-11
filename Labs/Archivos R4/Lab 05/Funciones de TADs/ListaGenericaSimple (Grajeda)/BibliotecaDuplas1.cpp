/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaDuplas1.cpp
 * Author: ISA
 * 
 * Created on 29 de abril de 2024, 08:55 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "BibliotecaDuplas1.h"

enum DUPLA{COD,NOM};
void* almacenarDupla1(const char* codigo,const char* nombre){
    void **registro = new void*[2];
    char *cod = new char[strlen(codigo)+1];
    char *nom = new char[strlen(nombre)+1];
    strcpy(cod,codigo);
    strcpy(nom,nombre);
    registro[COD] = cod;
    registro[NOM] = nom;
    return registro;
}
void* copiaDupla1(void* dupla){
    void **registro = (void**)dupla;
    char *reg_cod = (char*)registro[COD],*reg_nom = (char*)registro[NOM];
    void **copia = new void*[2];
    char *cod = new char[strlen(reg_cod) + 1];
    char *nom = new char[strlen(reg_nom) + 1];
    strcpy(cod, reg_cod);
    strcpy(nom, reg_nom);
    copia[COD] = cod;
    copia[NOM] = nom;
    return copia;
}
void eliminarDupla1(void *dupla){
    void **registro = (void**)dupla;
    char *cod = (char*)registro[COD],*nom = (char*)registro[NOM];
    delete cod;
    delete nom;
    delete registro;
}
bool dupla1CodigosIguales(void* duplaI,void* duplaK){
    void **regI = (void**)duplaI, **regK = (void**)duplaK;
    char *codI = (char*)regI[COD],*codK = (char*)regK[COD];
    return strcmp(codI,codK) == 0;
}
int comparardupla1Codigos(void* duplaI,void* duplaK){
    void **regI = (void**)duplaI, **regK = (void**)duplaK;
    char *codI = (char*)regI[COD],*codK = (char*)regK[COD];
    return strcmp(codI,codK);
}
bool dupla1NombresIguales(void* duplaI,void* duplaK){
    void **regI = (void**)duplaI, **regK = (void**)duplaK;
    char *nomI = (char*)regI[NOM],*nomK = (char*)regK[NOM];
    return strcmp(nomI,nomK) == 0;
}
int comparardupla1Nombres(void* duplaI,void* duplaK){
    void **regI = (void**)duplaI, **regK = (void**)duplaK;
    char *nomI = (char*) regI[NOM], *nomK = (char*) regK[NOM];
    return strcmp(nomI, nomK);
}

void mostrarDupla1(void *dupla){
    void **registro = (void**) dupla;
    char *cod = (char*) registro[COD], *nom = (char*) registro[NOM];
    cout << "{ "<< cod <<" - "<<nom<< " }";
}
void incrementarCantidadDuplas1(void *&cantidad,void *dupla){
    int *ptrcantidad = (int*)cantidad;
    if(cantidad == nullptr){
        ptrcantidad = new int{1};
        cantidad = ptrcantidad;
    } else (*ptrcantidad)++;
}
void decrementarCantidadDuplas1(void *&cantidad,void *dupla){
    int *ptrcantidad = (int*)cantidad;
    (*ptrcantidad)--;
    if(*ptrcantidad == 0){
        delete ptrcantidad;
        cantidad = nullptr;
    }
}
void UnirCantidadDuplas1(void *cantidadP,void *&cantidadS){
    int *ptrcantidadP = (int*)cantidadP;
    int *ptrcantidadS = (int*)cantidadS;
    if(cantidadP != nullptr and cantidadS != cantidadS){
        *ptrcantidadP += *ptrcantidadS;
    }
    delete ptrcantidadS;
    cantidadS = nullptr;
}
void eliminarCantidadDuplas1(void *&cantidad){
    int *ptrcantidad = (int*)cantidad;
    delete ptrcantidad;
    cantidad = nullptr;
}
void mostrarInformacionCantidadDuplas1(void *cantidad){
    int *ptrcantidad = (int*)cantidad;
    cout << "Numero de duplas1: "<< *ptrcantidad << endl;
}