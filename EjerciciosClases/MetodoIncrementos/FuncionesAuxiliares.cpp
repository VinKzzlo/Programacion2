/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 4 de septiembre de 2024, 8:52
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5

void leerDatos(const char *nombArch, int *&datos) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int dato, nd = 0, cap = 0;
    datos = nullptr;

    while (true) {
        arch >> dato;
        if (arch.eof()) break;
        if (nd == cap) aumentarEspacios(datos, nd, cap);
        datos[nd - 1] = dato;
        nd++;
    }


}

void aumentarEspacios(int *&datos, int &nd, int &cap) {
    int *aux;
    cap += INCREMENTO;
    if (datos == nullptr) {
        datos = new int[cap] {
        };
        nd = 1;
    }
    else {
        aux = new int[cap] {
        };
        for (int i = 0; i < nd; i++) {
            aux[i] = datos[i];
        }
        delete datos;
        datos = aux;
    }
}

void imprimirDatos(int *datos) {
    for(int i=0; datos[i];i++){
        cout<<setw(5)<<datos[i]<<endl;
    }

}