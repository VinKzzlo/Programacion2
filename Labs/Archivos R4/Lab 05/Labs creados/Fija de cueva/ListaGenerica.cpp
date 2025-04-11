/* 
 * File:   ListaGenerica.cpp
 * Author: ramir
 * 
 * Created on 2 de mayo de 2024, 23:37
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaGenerica.h"
void creaLista(void *&lista,void*(*lee)(ifstream &),const char *nombArch){
    void *dato;
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    generalista(lista);
    while(1){
        dato = lee(archReg);
        if(archReg.eof()) break;
        insertarLista(lista,dato);
    }
}

void generalista(void *&lista){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void insertarLista(void *lista,void *dato){
    void **dupla = (void**)lista;
    void **nuevo = new void*[2],**aux;
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

void uneLista(void *&listafin,void *lista1,void *lista2,int(*cmp)(void*,void*)){
    void **dupla1 = (void**)lista1,**dupla2 = (void**)lista2;
    void **aux1 = (void**)dupla1[0],**aux2 = (void**)dupla2[0];
    generalista(listafin);
    while(1){
        if(aux1==nullptr and aux2==nullptr) break;
        if(cmp(aux1,aux2)>0){
            insertarLista(listafin,aux1[0]);
            aux1 = (void**)aux1[1];
        }else if(cmp(aux1,aux2)<0){
            insertarLista(listafin,aux2[0]);
            aux2 = (void**)aux2[1];
        }else{
            insertarLista(listafin,aux1[0]);
            aux1 = (void**)aux1[1];
            aux2 = (void**)aux2[1];
        }
    }
}

void imprimeLista(void *lista,void(*imprime)(ofstream &,void *),
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