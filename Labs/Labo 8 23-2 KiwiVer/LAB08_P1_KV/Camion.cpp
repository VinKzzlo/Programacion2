/* 
 * Archivo:   Camion.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:13
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Camion.h"

Camion::Camion() {
    llantas = 0;
    ejes = 0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream& arch) {
    char cadena[10];
    arch<<"Codigo cliente: "<<GetCliente()<<endl;
    GetPlaca(cadena);
    arch<<"Placa: "<<cadena<<endl;
    arch<<"Carga Maxima: "<<GetMaxcarga()<<endl;
    arch<<"Carga Maxima: "<<GetActcarga()<<endl;
    arch<<"#Ejes: "<<GetEjes()<<endl;
    arch<<"#Llantas: "<<GetLlantas()<<endl;
    Vehiculo::imprime(arch);
}
