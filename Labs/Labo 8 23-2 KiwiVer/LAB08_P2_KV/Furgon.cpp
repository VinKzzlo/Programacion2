/* 
 * Archivo:   Furgon.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:14
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
    char cadena[10];
    arch<<"Codigo cliente: "<<GetCliente()<<endl;
    GetPlaca(cadena);
    arch<<"Placa: "<<cadena<<endl;
    arch<<"Carga Maxima: "<<GetMaxcarga()<<endl;
    arch<<"Carga Maxima: "<<GetActcarga()<<endl;
    arch<<"#Filas: "<<GetFilas()<<endl;
    arch<<"#Puertas: "<<GetPuertas()<<endl;
    Vehiculo::imprime(arch);
}
