/* 
 * Archivo:   Pedido.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Pedido.h"
#include "Funciones.h"

Pedido::Pedido() {
    codigo = nullptr;
}

Pedido::~Pedido() {
    if(codigo!=nullptr) delete []codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if(codigo != nullptr) delete [] codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

char *Pedido::GetCodigo() const {
    char *copia = new char[strlen(codigo)+1];
    strcpy(copia,codigo);
    return copia;
}

bool operator >>(ifstream &arch, class Pedido &ped){
    char *codProd;
    int dniCli;
    
    codProd = leeCadena(arch,8,',');
    if(arch.eof()) return false;
    arch>>dniCli;
    arch.get();
    
    ped.SetCodigo(codProd);
    ped.SetDni_cliente(dniCli);
    
    return true;    
}