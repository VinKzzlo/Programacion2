/* 
 * Archivo:   Lista.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    peso = 0.0;
    ini = nullptr;
}

Lista::~Lista() {
    
}

void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

void Lista::insertar(Nodo* nuevo) {
    Nodo *ptr = ini;
    if(ini==nullptr)
        ini = nuevo;
    else{
        while(ptr->sig) ptr = ptr->sig;
        ptr->sig = nuevo;
    }
    peso += nuevo->plibro->GetPeso();
}

void Lista::cambiaVigencia() {
    Nodo *ptr = ini;
    while(ptr){
        ptr->plibro->actualiza();
        ptr = ptr->sig;
    }
}

void Lista::imprimeLibros(ofstream&arch) {
    Nodo *ptr = ini;
    while(ptr){
        ptr->plibro->imprime(arch);
        arch<<endl;
        ptr = ptr->sig;
    }
}
