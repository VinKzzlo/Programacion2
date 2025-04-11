/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 4 de septiembre de 2024, 9:12
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int *codigos;
    char **nombres, ***cursos;
    
    cargarAlumnos(codigos,nombres,"Alumnos.csv");
    cargarCursos(codigos,cursos,"Cursos.csv");
    imprimirAlumnos(codigos,nombres,cursos,"ReporteDeAlumnos.txt");
    
    return 0;
}

