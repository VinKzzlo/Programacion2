/* 
 * Archivo:   Persona.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 9:35
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
    nombre = nullptr;
    *this = orig;
}

Persona::~Persona() {
    if(nombre!=nullptr) delete nombre;
}

void Persona::SetPrecio(double precio) {
    this->precio = precio;
}

double Persona::GetPrecio() const {
    return precio;
}

void Persona::SetNombre(const char* nomb) {
    if(nombre)delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Persona::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0] = 0;
    strcpy(cad,nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator=(const Persona& per) {
    char aux[60];
    dni = per.dni;
    precio = per.precio;
    per.GetNombre(aux);
    SetNombre(aux);
}

void operator>>(ifstream &, class Persona &per){
    
}