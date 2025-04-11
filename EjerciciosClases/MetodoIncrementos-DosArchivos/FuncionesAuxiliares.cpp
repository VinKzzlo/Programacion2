/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 4 de septiembre de 2024, 9:15
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5


void cargarAlumnos(int *&codigos, int **&nombres, const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int nd = 0, cap = 0, cod;
    char **nomb;
    codigos = nullptr;
    nombres = nullptr;
    while (true) {
        arch >> cod;
        if (arch.eof())break;
        arch.get();
        nomb = leeCadena(arch);
        if(nd == cap) incrementarEspacios(codigos,nombres,nd,cap);
        codigos[nd-1] = cod;
        nombres[nd-1] = nomb;
        nd++;
    }
}

void incrementarEspacios(int *&codigos,char **&nombres,int &nd, int &cap){
    int *auxCod;
    char **auxNomb;
    
    cap += INCREMENTO;
    if(nd==0){
        codigos = new int[cap]{};
        nombres = new char*[cap]{};
        nd=1;
    }
    else{
        auxCod = new int[cap]{};
        auxNomb = new char*[cap]{};
        for(int i=0;i<nd;i++){
            auxCod[i] = codigos[i];
            auxNomb[i] = nombres[i];
        }
        delete codigos;
        delete nombres;
        codigos = auxCod;
        nombres = auxNomb;
    }
    
}

char*leeCadena(ifstream &arch, char delimitador) {
    char buffer[60], *cad;
    arch.getline(buffer, 60, delimitador);
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void cargarCursos(int *&codigos, char ***&cursos, const char *nombArch) {

}

void imprimirAlumnos(int *&codigos, int **&nombres, int ***&cursos,
        const char *nombArch) {

}