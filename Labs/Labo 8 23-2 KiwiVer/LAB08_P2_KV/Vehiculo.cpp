/* 
 * Archivo:   Vehiculo.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 23:55
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
    ped = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
    if(placa) delete placa;
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
    if(placa != nullptr ) delete placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Vehiculo::GetPlaca(char *cad) const {
    if(placa == nullptr ) cad[0]=0;
    strcpy(cad,placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream& arch) {
    char c, placaA[8];
    arch>>cliente>>c;
    arch.getline(placaA,8,',');
    SetPlaca(placaA);
    arch>>maxcarga>>c;
}

void Vehiculo::imprime(ofstream& arch) {
    arch<<"Pedidos:"<<endl;
    if(not pilavacia()){
        imprimePila(arch);
    }
    else
        arch<<"No hay pedidos para el cliente"<<endl;
    arch<<endl;
}

void Vehiculo::push(NPedido& nodoAux) {
    NPedido *nuevoNodo = new NPedido(nodoAux);
    
    nuevoNodo->sig = ped;
    ped = nuevoNodo;
}

bool Vehiculo::pilavacia() {
    return ped == nullptr;
}

void Vehiculo::imprimePila(ofstream& arch) {
    NPedido *ptr = ped;
    while(ptr){
        ptr->imprimePedidoss(arch);
        ptr = ptr->sig;
    }
}
