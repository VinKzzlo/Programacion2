/* 
 * Archivo:   Estante.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:40
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    id = 0;
    capacidad = 0.0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

bool Estante::verificaCapacidad(double pesoNuevo) {
    if(capacidad > (Llibros.GetPeso() + pesoNuevo))
        return true;
    return false;
}

void Estante::agregaLibro(Nodo* nuevo) {
    Llibros.insertar(nuevo);
}

void Estante::actualizaVigencia() {
    Llibros.cambiaVigencia();
}

void Estante::muestraEstantes(ofstream& arch) {
    arch<<endl;
    arch<<"Id: "<<id<<endl;
    arch<<"Tipo: ";
    switch(clase){
        case 'H':
            arch<<"Horizontal";
            break;
        case 'V':
            arch<<"Vertical";
            break;
    }
    arch<<"Capacidad: "<<capacidad<<endl;
    arch<<"Libros Contenidos:"<<endl;
    imprimeLinea(arch,'=');
    Llibros.imprimeLibros(arch);
    imprimeLinea(arch,'=');
}

void Estante::imprimeLinea(ofstream& arch, char c) {
    for(int i=0;i<80;i++)
        arch.put(c);
    arch<<endl;
}

