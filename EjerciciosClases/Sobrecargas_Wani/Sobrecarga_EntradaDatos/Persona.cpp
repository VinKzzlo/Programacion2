/* 
 * Archivo:   Persona.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 23:59
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

char* Persona::GetNombre(char *nomb) const {
    strcpy(nomb, nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

istream & operator>>(istream & in, class Persona &p) {
    char nomb[200], c;
    int dni;
    double sueldo;

    cout << "DNI: ";
    in >> dni;

    cout << "NOMBRE: ";
    in>>nomb;
    cout << "SUELDO: ";
    in>>sueldo;

    p.SetDni(dni);
    p.SetNombre(nomb);
    p.SetSueldo(sueldo);

    return in;
}

ostream & operator<<(ostream &out, const class Persona &p) {
    out.precision(2);
    out << fixed;
    char nomb[200];

    p.GetNombre(nomb);
    out << left << setw(10) << p.GetDni() << setw(40) << nomb << setw(15)
            << right << p.GetSueldo() << endl;
    ;

    return out;
}