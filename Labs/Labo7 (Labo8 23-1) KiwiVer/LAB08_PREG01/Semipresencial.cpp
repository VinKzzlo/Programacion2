/* 
 * Archivo:   Semipresencial.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 17:06
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0.0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leerDatos(ifstream& arch) {
    Alumno::leeDatos(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::actualiza(double montoT) {
    total = montoT*(GetDescuento()/100);
    Alumno::SetTotal(montoT-total);
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<'+'<<setw(10)<<Alumno::GetTotal()<<endl;
}
