/* 
 * Archivo:   NodoLista.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "NodoLista.h"
#include "Furgon.h"
#include "Camion.h"

NodoLista::NodoLista() {
    unidad = nullptr;
    sig = nullptr;
}

NodoLista::NodoLista(char tipo) {
    sig = nullptr;
    switch(tipo){
        case 'F':
            unidad = new Furgon;
            break;
        case 'C':
            unidad = new Camion;
            break;
    }
}

NodoLista::~NodoLista() {
}

void NodoLista::leeRegistroVehiculo(ifstream& arch) {
    unidad->lee(arch);
}

void NodoLista::imprimeRegistro(ofstream& arch) {
    unidad->imprime(arch);
}
