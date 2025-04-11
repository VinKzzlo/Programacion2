/* 
 * Archivo:   NVehiculo.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    this->unidad = orig.unidad;
}

NVehiculo::~NVehiculo() {
}

void NVehiculo::leeTipoVehiculo(ifstream& arch) {
    char tipo;
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    switch(tipo){
        case 'F':
            unidad = new Furgon;
            break;
        case 'C':
            unidad = new Camion;
            break;
    }
    unidad->lee(arch);
}

bool NVehiculo::comparaCliente(int codigo) {
    return (unidad->GetCliente()==codigo);
}

void NVehiculo::insertaPedido(NPedido& nped) {
    unidad->cargadeposito(nped);
}

void NVehiculo::imprimeVehiculo(ofstream& arch) {
    unidad->imprime(arch);
}
