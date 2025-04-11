/* 
 * Archivo:   NPedido.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 23:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "NPedido.h"

NPedido::NPedido() {
    cantidad = 0;
    peso = 0.0;
    codigo = nullptr;
    sig = nullptr;
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
    if(codigo) delete codigo;
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
    if(codigo != nullptr ) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void NPedido::GetCodigo(char * cad) const {
    if(codigo == nullptr ) cad[0]=0;
    strcpy(cad,codigo);
}

