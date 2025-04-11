/* 
 * Archivo:   FuncionesDePunterosGenericos.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "FuncionesDeCadenas.h"
#include "FuncionesDePunterosGenericos.h"
#define INCREMENTO 5

void *leerRegistro(ifstream &arch){
    void **registro;
    int *codigo, cod;
    char *nombre;
    double *sueldo;
    arch >> cod;
    if(arch.eof()) return nullptr;
    codigo = new int;
    *codigo = cod;
    arch.get();
    nombre = leeCadena(arch,',');
    sueldo = new double;
    arch >> *sueldo;
    registro = new void*[3]{};
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = sueldo;
    return registro;
}

void imprimirDatos(void*per, int np, const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void **personal = (void **)per;
    for (int i = 0; i < np-1; i++)
        imprimePersona(arch,personal[i]);
}

void imprimePersona(ofstream &arch,void *per){
    void **persona = (void **)per;
    int *codigo = (int *)persona[0];
    char *nombre = (char*)persona[1];
    double *sueldo = (double*)persona[2];

    arch.precision(2);
    arch << fixed;
    arch << right << setw(10) << *codigo << "  " << left << setw(40) << nombre
         << right << setw(10) << *sueldo << endl;
}

int miVoidcmpCodigos(const void *a, const void *b){
    void **regA = (void **)(a), **regB = (void**)(b);
    int *codA = (int*)regA[0], *codB = (int*)regB[0];
    return *codA - *codB;
}

int miVoidcmpSueldos(const void *a, const void *b){
    void **regA = (void **)(a), **regB = (void**)(b);
    double *codA = (double*)regA[2], *codB = (double*)regB[2];
    return (int)(*codA - *codB);
}

int miVoidcmpNombres(const void *a, const void *b){
    void **regA = (void **)(a), **regB = (void**)(b);
    char *nombA = (char*)regA[1], *nombB = (char*)regB[1];
    return strcmp(nombA, nombB);
}

void eliminaReg(void *dato){
    void **reg = (void **)dato;
    int *codigo = (int*)reg[0];
    char *nombre = (char*)reg[1];
    double *sueldo = (double*)reg[2];

    delete codigo;
    delete nombre;
    delete sueldo;
    delete reg;
}

char*leeCadena(ifstream &arch, char delimitador){
    char buffer[60], *cad;
    arch.getline(buffer, 60, delimitador);
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}