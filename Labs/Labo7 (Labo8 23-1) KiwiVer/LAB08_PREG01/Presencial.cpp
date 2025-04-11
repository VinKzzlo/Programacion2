/* 
 * Archivo:   Presencial.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:58
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total = 0.0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream& arch) {
    Alumno::leeDatos(arch);
    arch>>recargo;
    arch.get();
}

int Presencial::actualiza(double montoT) {
    total = montoT*(GetRecargo()/100);
    Alumno::SetTotal(total+montoT);
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<'-'<<setw(10)<<Alumno::GetTotal()<<endl;
}
