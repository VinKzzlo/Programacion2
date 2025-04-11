/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 3 de septiembre de 2024, 8:57
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int *codigos;
    char **nombres, ***cursos;
    cargarAlumnos(codigos,nombres,cursos,"Alumnos-Cursos.txt");
    return 0;
}

