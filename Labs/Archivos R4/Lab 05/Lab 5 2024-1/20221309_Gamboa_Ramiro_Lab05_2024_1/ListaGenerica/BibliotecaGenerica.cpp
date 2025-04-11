/* 
 * File:   BibliotecaGenerica.cpp
 * Author: ramir
 * 
 * Created on 12 de mayo de 2024, 00:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaGenerica.h"
void crealista(void *&lista,void*(*lee)(ifstream &),const char *nombArch){
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    generalista(lista);
    while(1){
        dato = lee(archReg);
        if(archReg.eof()) break;
        insertalista(lista,dato);
    }
}

void generalista(void *&lista){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void insertalista(void *lista,void *dato){
    void **dupla = (void**)lista;
    void **nuevo,**aux;
    nuevo = new void*[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    if(listavacia(lista)){
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        aux = (void**)dupla[1];
        aux[1] = nuevo;
        dupla[1] = nuevo;
    }
}

bool listavacia(void *lista){
    void **dupla = (void**)lista;
    if(dupla[0]==nullptr) return true;
    return false;
}

void imprimelista(void *lista,void(*imprime)(ofstream &,void*),
                  const char *nombArch){
    void **dupla = (void**)lista,**aux = (void**)dupla[0];
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(aux){
        imprime(archRep,aux[0]);
        aux = (void**)aux[1];
    }
}

void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,
                  int(*cmp)(void*,void*)){
    generalista(pedidosfinal);
    void **dupla1 = (void**)pedidos1,**dupla2 = (void**)pedidos2;
    void *dato;
    while(!listavacia(pedidos1) or !listavacia(pedidos2)){
        if(cmp(dupla1[0],dupla2[0])>0){
            dato = quitalista(pedidos1);
            insertalista(pedidosfinal,dato);
        }else if(cmp(dupla1[0],dupla2[0])<0){
            dato = quitalista(pedidos2);
            insertalista(pedidosfinal,dato);
        }else{
            dato = quitalista(pedidos1);
            dato = quitalista(pedidos2);
            insertalista(pedidosfinal,dato);
        }
    }
}

void *quitalista(void *lista){
    
    if(listavacia(lista)) return nullptr;
    
    void **dupla = (void**)lista;
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