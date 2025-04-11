/* 
 * Archivo:   NPedido.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 07:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0.0;
}

NPedido::NPedido(const NPedido& orig) {
    codigo = nullptr;
    *this = orig;
}

NPedido::~NPedido() {
//    if(codigo) delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char* cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void NPedido::GetCodigo(char* cad) const {
    if(codigo == nullptr) cad[0] = 0;
    strcpy(cad,codigo);
}

void NPedido::leePedido(ifstream& arch) {
    char codProd[8];
    arch.getline(codProd,8,',');
    SetCodigo(codProd);
    arch>>cantidad;
    arch.get();
    arch>>peso;
}

void NPedido::operator=(const NPedido& orig) {
    char cod[8];
    orig.GetCodigo(cod);
    SetCodigo(cod);
    cantidad = orig.cantidad;
    peso = orig.peso;
}

void NPedido::imprimePedido(int id, ofstream &arch) {
    arch<<id<<"  "<<codigo<<"  "<<cantidad<<"  "<<peso<<endl;
}

void NPedido::imprimePedido(ofstream& arch) {
    arch<<codigo<<"  "<<cantidad<<"  "<<peso<<endl;
}
