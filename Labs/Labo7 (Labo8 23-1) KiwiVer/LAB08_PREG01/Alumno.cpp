/* 
 * Archivo:   Alumno.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:53
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
}

Alumno::~Alumno() {
    if(nombre != nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0] = 0;
    strcpy(cad,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

//P,202119153,MENDOZA/ARIAS/HENRY,4,10
void Alumno::leeDatos(ifstream& arch) {
    char nomb[50];
    
    arch>>codigo;
    arch.get();
    arch.getline(nomb,50,',');
    SetNombre(nomb);
    arch>>escala;
    arch.get();
    
}

void Alumno::imprime(ofstream& arch) {
    arch<<left<<setw(15)<<codigo<<setw(50)<<nombre<<right<<setw(3)<<escala;
}
