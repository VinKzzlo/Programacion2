/* 
 * Archivo:   Enciclopedia.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:12
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    vigencia = 1;
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream& arch) {
    Libro::lee(arch);
    char c;
    arch>>sku>>c>>anho;
    arch.get();
}

void Enciclopedia::actualiza() {
    if(anho<=2020) SetVigencia(0);
}

void Enciclopedia::imprime(ofstream& arch) {
    Libro::imprime(arch);
    arch<<"SKU: "<<sku<<setw(10)<<' '<<"Año: "<<anho
        <<setw(10)<<' '<<"Vigencia: "<<vigencia<<endl;
}
