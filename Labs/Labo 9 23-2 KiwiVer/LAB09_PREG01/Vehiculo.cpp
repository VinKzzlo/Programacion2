/* 
 * Archivo:   Vehiculo.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:51 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
    actcarga = 0.0;
    maxcarga = 0.0;
    cliente = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* cad) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Vehiculo::GetPlaca(char* cad) const {
    if(placa == nullptr) cad[0] = 0;
    strcpy(cad,placa);
}


void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &arch) {
    char plac[8];
    arch>>cliente;
    arch.get();
    arch.getline(plac,8,',');
    SetPlaca(plac);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream& arch) {
    arch<<endl;
    arch<<"Codigo Cliente: "<<cliente<<endl;
    arch<<"Placa: "<<placa<<endl;
    arch<<"Carga Maxima: "<<maxcarga<<endl;
    arch<<"Carga Actual: "<<actcarga<<endl;
    
}
