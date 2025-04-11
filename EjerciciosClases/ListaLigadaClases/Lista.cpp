/* 
 * Archivo:   Lista.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 8:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    lista = nullptr;
}

Lista::~Lista() {
    elimina();
}

void Lista::crear(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int d;
    while(true){
        arch>>d;
        if(arch.eof())break;
        insertar(d);
    }
}

void Lista::insertar(int d) {
    class Nodo *p=lista, *ant = nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo->dato = d;
    while(p){
        if(p->dato>d) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if(ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void Lista::imprimir(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Nodo *p = lista;
    while(p){
        arch<<setw(4)<<p->dato;
        p = p->sig;
    }
    arch<<endl;
}

void Lista::elimina() {
    class Nodo *sale;
    while(lista){
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
    lista = nullptr;//Si se quiere reutilizar el objeto para llenar otra lista
}

void Lista::imprimeRecursivo(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimeR(arch, lista);
    arch<<endl;
}

void Lista::imprimeR(ofstream& arch, Nodo* lista) {
    if(lista==nullptr) return;
    imprimeR(arch,lista->sig);
    arch<<setw(4)<<lista->dato;
}




