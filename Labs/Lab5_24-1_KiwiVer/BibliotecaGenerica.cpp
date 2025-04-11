/* 
 * Archivo:   BibliotecaGenerica.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"

void crealista(void *&lista,void*(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    generaLista(lista);
    while(true){
        dato = lee(arch);
        if(arch.eof())break;
        insertaEnLista(lista,dato);
    }
}

void generaLista(void *&lista){
    void **dupla = new void *[2]{};
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    lista = dupla;
}

void insertaEnLista(void *lista,void *dato){
    void **dupla = (void**)lista;
    void **nuevo, **aux;
    nuevo = new void*[2]{};
    nuevo[0] = dato;
    if(esListaVacia(lista)){
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        aux = (void**)dupla[1];
        aux[1] = nuevo;
        dupla[1] = nuevo;
    }
}

bool esListaVacia(void *lista){
    void **dupla = (void**)lista;
    if(dupla[0]== nullptr) return true;
    else return false;
}

void imprimelista(void *lista,void(*imprime)(ofstream &, void*dato),
                  const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **dupla = (void**)lista;
    void **aux = (void**)dupla[0];
    while(aux){
        imprime(arch,aux[0]);
        aux = (void**)aux[1];
    }
}

void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,
                  int(*compara)( void*, void*)){
    generaLista(pedidosfinal);
    void **dupla1 = (void**)pedidos1, **dupla2 = (void**)pedidos2;
    void *dato;
    while(!esListaVacia(pedidos1) or !esListaVacia(pedidos2)){
        if(compara(dupla1[0],dupla2[0])>0){
            dato = quitalista(pedidos2);
            insertaEnLista(pedidosfinal,dato);
        }
        else if(compara(dupla1[0],dupla2[0])<0){
            dato = quitalista(pedidos1);
            insertaEnLista(pedidosfinal,dato);
        }
        else{
            dato = quitalista(pedidos1);
            dato = quitalista(pedidos2);
            insertaEnLista(pedidosfinal,dato);
        }
    }
}

void *quitalista(void *lista){
    if(esListaVacia(lista)) return nullptr;
    void **dupla = (void**)lista;
    void **listaIni = (void**)dupla[0];
    void **siguiente, *dato;
    if(dupla[0]==dupla[1]){
        dupla[0] = nullptr;
        dupla[1] = nullptr;
    }
    else{
        siguiente = (void**)listaIni[1];
        dupla[0] = siguiente;
        listaIni[1] = nullptr;
    }
    dato = listaIni[0];
    delete listaIni;
    return dato;
}