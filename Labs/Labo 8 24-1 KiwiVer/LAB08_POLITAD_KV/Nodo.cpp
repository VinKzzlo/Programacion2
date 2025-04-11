/* 
 * Archivo:   Nodo.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:26
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Nodo.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"

Nodo::Nodo() {
    plibro = nullptr;
    sig = nullptr;
}

Nodo::~Nodo() {
    
}

void Nodo::asignaMemoria(char tipo) {
    switch (tipo){
        case 'N':
            plibro = new Novela;
            break;
        case 'E':
            plibro = new Enciclopedia;
            break;
        case 'R':
            plibro = new Revista;
            break;
    }
}
