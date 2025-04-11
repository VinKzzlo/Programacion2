
/* 
 * Archivo:   Cadena.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 27 de octubre de 2024, 21:11
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Cadena.h"

Cadena::Cadena() {
    cad = nullptr;
}

void Cadena::SetCad(const char *c){
    if (cad != nullptr) delete cad;
    cad = new char[strlen(c)+1];
    strcpy(cad,c);
}

void Cadena::GetCad(char *c) const {
    if(cad == nullptr) c[0] = 0;
    else strcpy(c, cad);
}

void Cadena::imprimeCad(void){
    cout << "Cadena = " << cad << endl;
}

void Cadena::operator +(const class Cadena &c){
    char aux[500], buffC[100];
    c.GetCad(buffC);
    if(cad != nullptr){
        strcpy(aux, cad);
        strcat(aux,buffC);
        SetCad(aux);
    }
    else
        SetCad(buffC);
}

