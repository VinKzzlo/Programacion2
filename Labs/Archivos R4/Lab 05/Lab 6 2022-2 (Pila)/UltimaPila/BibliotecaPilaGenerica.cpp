/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Author: ramir
 * 
 * Created on 14 de mayo de 2024, 00:14
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaPilaGenerica.h"
void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
                  void*(*lee)(ifstream &),const char *nombArch){
    void *buff[10],**larreglo;
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        buff[i] = lee(archReg);
        if(archReg.eof()) break;
        i++;
    }
    int n=i;
    larreglo = new void*[n+1];
    for(i=0;i<n;i++) larreglo[i] = buff[i];
    larreglo[n] = nullptr;
    qsort(larreglo,n,sizeof(void*),cmp);
    arreglo = larreglo;
}

void cargapila(void *&pila,void *arreglo){
    void **larreglo = (void**)arreglo;
    int i=0;
    generapila(pila);
    while(larreglo[i]){
        push(pila,larreglo[i]);
        i++;
    }
}

void generapila(void *&pila){
    void **dupla = new void*[2];
    int *dato;
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

void muevepila(void *pilaini,void *&pilafin){
    
}

void imprimepila(void *pilafin,void(*imprime)(ofstream &,void*),
                 const char *nombArch);