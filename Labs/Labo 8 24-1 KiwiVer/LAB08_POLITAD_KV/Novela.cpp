/* 
 * Archivo:   Novela.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
    if(autor != nullptr) delete autor;
}

void Novela::SetAutor(char* aut) {
    if(autor != nullptr) delete autor;
    autor = new char[strlen(aut)+1];
    strcpy(autor,aut);
}

void Novela::GetAutor(char *cad) const {
    if(autor == nullptr ) cad[0] = 0;
    else strcpy(cad,autor);
}

void Novela::lee(ifstream& arch) {
    Libro::lee(arch);
    char *autor;
    autor = leeCadenaExacta(arch);
    SetAutor(autor);
}

void Novela::actualiza() {

}

void Novela::imprime(ofstream& arch) {
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;
    
}
