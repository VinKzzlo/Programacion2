/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Author: ramir
 * 
 * Created on 30 de abril de 2024, 10:06
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "BibliotecaPilaGenerica.h"
void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
                  void*(*lee)(ifstream &),const char *nombArch){
    void *buff[100],**larreglo;
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
    int *dato;
    void **dupla;
    //Cabeza de la pila
    dupla = new void*[2];
    dupla[0] = nullptr;
    //Numero de elementos de la pila
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
    void *auxPila;
    void **dupla = (void**)pilaini;
    generapila(pilafin);
    generapila(auxPila);
    
    int *num = (int*)dupla[1];
    
    hanoi(*num,pilaini,auxPila,pilafin);
}

void hanoi(int n,void *ini,void *aux,void *fin){
    if(n==1){
        push(fin,pop(ini));
        return;
    }else{
        hanoi(n-1,ini,fin,aux);
        push(fin,pop(ini));
        hanoi(n-1,aux,ini,fin);
    }
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

void imprimepila(void *pila,void(*imprime)(ofstream &,void*),
                 const char *nombArch){
    void **dupla = (void**)pila,**aux;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    aux = (void**)dupla[0];
    while(aux){
        imprime(archRep,aux[1]);
        aux = (void**)aux[0];
    }
}