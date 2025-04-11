/* 
 * Archivo:   Revista.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:17
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Revista.h"

Revista::Revista() {
    vigencia = 1;
}


void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream& arch) {
    Libro::lee(arch);
    char c;
    arch>>ISSN>>c>>anho>>c>>numero;
    arch.get();
}

void Revista::actualiza() {
    if(anho<=2020) SetVigencia(0);
}
