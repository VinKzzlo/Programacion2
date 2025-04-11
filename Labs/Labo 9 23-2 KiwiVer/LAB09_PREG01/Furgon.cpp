/* 
 * Archivo:   Furgon.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Furgon.h"

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();
}

void Furgon::imprime(ofstream& arch) {
    Vehiculo::imprime(arch);
    arch<<"#Filas: "<<filas<<endl;
    arch<<"#Puertas: "<<puertas<<endl;
}
