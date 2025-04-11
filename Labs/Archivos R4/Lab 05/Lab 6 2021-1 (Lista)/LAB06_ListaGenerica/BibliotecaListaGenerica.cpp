/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 23 de abril de 2024, 10:48
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
//Crear Lista
void creaLista(void *&lista,void *(*lee)(ifstream &),
               int (*cmp)(void*,void*),const char *nombArch){
    //void *: Devuelve el valor void*
    //(*lee): Es puntero a funcion
    //(ifstream &): Necesitara el parametro ifstream &arch
    //
    //       int                (*            cmp)        (void*,void*)
    //Tipo que devuelve  Puntero a funcion   Nombre  Parametros de la funcion
    
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    generaLista(lista);
    while(1){
        dato = lee(archReg);
        if(archReg.eof()) break;
        insertaLista(lista,dato,cmp);
    }
}
//Inicializa la lista
void generaLista(void *&lista){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void insertaLista(void *lista,void *dato,int (*cmp)(void*,void*)){
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
    else return false;
}

void uneLista(void *lista1,void *lista2){
    void **dupla1 = (void**)lista1;
    void **dupla2 = (void**)lista2;
    
    void **aux1 = (void**)dupla1[1];
    aux1[1] = dupla2[0];
    dupla1[1] = dupla2[1];
}

void imprimeLista(void *lista,void(*imprime)(void *,ofstream &),
                  const char *nombArch){
    void **dupla = (void**)lista;
    void **aux = (void**)dupla[0];
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(aux){
        imprime(aux[0],archRep);
        aux = (void**)aux[1];
    }
}