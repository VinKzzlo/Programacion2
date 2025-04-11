/* 
 * Archivo:   Virtual.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 17:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100.0;
}

Virtual::~Virtual() {
    if(licencia!=nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* lic) {
    if(licencia!=nullptr) delete licencia;
    licencia = new char[strlen(lic)+1];
    strcpy(licencia,lic);
}

void Virtual::GetLicencia(char* cad) const {
    if(licencia==nullptr) cad[0] = 0;
    strcpy(cad,licencia);
}

void Virtual::leerDatos(ifstream& arch) {
    Alumno::leeDatos(arch);
    char lic[10];
    arch.getline(lic,10);
    SetLicencia(lic);   
}

void Virtual::actualiza(double montoT) {
    Alumno::SetTotal(montoT+total);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<licencia<<setw(10)<<Alumno::GetTotal()<<endl;
}
