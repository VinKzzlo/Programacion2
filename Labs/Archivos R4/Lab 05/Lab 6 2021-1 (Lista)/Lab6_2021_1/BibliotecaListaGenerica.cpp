/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: ramir
 * 
 * Created on 30 de abril de 2024, 22:10
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
//Crear lista
void creaLista(void *&lista,void*(*lee)(ifstream &),int(*cmpnum)(void*,void*),
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
        insertarLista(lista,dato);
    }
}

void generalista(void *&lista){
    void **dupla = new void*[2];
    //Inicializa la cabeza de la lista
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    //Devuelve la dupla creada a la lista
    lista = dupla;
}

void insertarLista(void *lista,void *dato){
    void **dupla = (void**)lista;
    void **nuevo,**aux;
    //Crea el espacio donde se guardara el dato en la lista
    nuevo = new void*[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    //Comprueba si la lista esta vacia
    if(listavacia(lista)){
        //Asigna la cabeza al nuevo dato
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        //Asigna el anterior dato colocado a que apunte al nuevo dato
        aux = (void**)dupla[1];
        aux[1] = nuevo;
        //Cambia el fin de la lista al nuevo dato agregado
        dupla[1] = nuevo;
    }
}

bool listavacia(void *lista){
    void **dupla = (void**)lista;
    if(dupla[0]==nullptr) return true;
    return false;
}
//Unir lista
void uneLista(void *lista1,void *lista2){
    void **dupla1 = (void**)lista1;
    void **dupla2 = (void**)lista2;
    
    void **aux1 = (void**)dupla1[1];
    //Une el ultimo dato de la primera lista con el primero de la segunda lista
    aux1[1] = dupla2[0];
    //Cambia el fin de la primera lista al fin de la segunda lista
    dupla1[1] = dupla2[1];
}
//Imprimir lista
void imprimeLista(void *lista,void(*imprime)(ofstream &,void*),
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