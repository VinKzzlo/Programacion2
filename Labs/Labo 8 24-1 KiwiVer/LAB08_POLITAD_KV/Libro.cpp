/* 
 * Archivo:   Libro.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
    paginas = 0;
    peso = 0.0;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(nombre != nullptr) delete nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Libro::GetNombre(char* cad) const {
    if(nombre == nullptr) cad[0] = '0';
    else strcpy(cad,nombre);
}

void Libro::lee(ifstream& arch) {
    char *titulo,c;
    int numPag;
    double peso;
    
    titulo = leeCadenaExacta(arch,',');
    arch>>numPag>>c>>peso;
    arch.get();
    
    SetNombre(titulo);
    SetPaginas(numPag);
    SetPeso(peso);
    
}

char* Libro::leeCadenaExacta(ifstream& arch, char delim) {
    char buffer[60], *cad;
    arch.getline(buffer,60,delim);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void Libro::imprime(ofstream& arch) {
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<peso<<endl;
}
