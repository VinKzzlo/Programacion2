/* 
 * File:   ListaGenerica.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 20:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaGenerica.h"
void creaLista(void *&lista,void*(*lee)(ifstream &),int(*cmp)(void *,void *),
               const char *nombArch){
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
        insertarLista(lista,dato,cmp);
    }
}

void generalista(void *&lista){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void insertarLista(void *lista,void *dato,int(*cmp)(void *,void *)){
    //Dupla: Casteo para acceder a la cabeza
    //Nuevo: Donde se guardara el dato
    //Aux: El anterior dato para que apunte al nuevo
    void **dupla = (void**)lista;
    void **nuevo,**aux;
    //Creacion de espacio de memoria para el nuevo
    nuevo = new void*[2];   //Literalmente creando un nodo
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    //Verificar si es el primer dato que se añade, porque si no existe un aux
    //el programa se cae
    if(listavacia(lista)){
        //Nuevo es el primer y ultimo dato
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        //Hay que hacer que el anterior nodo (aux) apunte al nuevo
        aux = (void**)dupla[1];
        aux[1] = nuevo;
        //Se agrega al final
        dupla[1] = nuevo;
    }
}

bool listavacia(void *lista){
    void **dupla = (void**)lista;
    if(dupla[0]==nullptr) return true;
    return false;
}

void uneLista(void *lista1,void *lista2){
    //Casteando las cabezas de cada lista
    void **dupla1 = (void**)lista1;
    void **dupla2 = (void**)lista2;
    
    void **aux1 = (void**)dupla1[1];
    aux1[1] = dupla2[0];
    dupla1[1] = dupla2[1];
}

void imprimeLista(void *lista,void(*imprime)(ofstream &,void *),
                  const char *nombArch){
    void **dupla = (void**)lista;
    void **aux = (void**)dupla[0];
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