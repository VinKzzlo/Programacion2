/* 
 * Archivo:   ProductoEntregado.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:19
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}

ProductoEntregado::~ProductoEntregado() {
    if(codigo != nullptr) delete [] codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* cod) {
    if(codigo != nullptr) delete [] codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

char* ProductoEntregado::GetCodigo() const {
    char *copiaCod=new char[strlen(codigo)+1];
    strcpy(copiaCod,codigo);
    return copiaCod;
}

