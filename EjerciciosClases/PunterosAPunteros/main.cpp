/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 28 de agosto de 2024, 9:23
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *codigos;
    char **nombres, ***cursos;
    cargarAlumnos(codigos,nombres,cursos,"Alumnos-Cursos.txt");
    imprimirAlumnos(codigos,nombres,cursos,"Reporte.txt");
    return 0;
}

