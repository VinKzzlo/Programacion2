/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:48 PM
 */

#include "NodoLista.h"
#include "Furgon.h"
#include "Camion.h"

NodoLista::NodoLista() {
    unidad=nullptr;
    sig=nullptr;
}

NodoLista::NodoLista(char tipo) {
    sig=nullptr;
    switch(tipo){
        case'F':
            unidad=new Furgon;
            break;
        case'C':
            unidad=new Camion;
            break;
    }
}

NodoLista::~NodoLista() {
}

void NodoLista::leeRegistroVehiculo(ifstream& arch) {
    unidad->lee(arch);
}

void NodoLista::imprimirRegistro(ofstream& arch) {
    unidad->imprime(arch);
}

void NodoLista::insertarPedidoEnPila(NPedido& nodoAux) {
    unidad->push(nodoAux);
}
