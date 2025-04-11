/* 
 * Archivo:   Escala.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:53
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Escala.h"

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

