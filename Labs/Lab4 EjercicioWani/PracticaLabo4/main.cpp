/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  4 de octubre de 2024, 0:07
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumnos;
    cargarAlumnos(alumnos, "Alumnos.csv");
    cargarNotas(alumnos, "CursosNotas.csv");
    calcularPromedios(alumnos);
    ordenarAlumnos(alumnos);
    probarLaLectura(alumnos, "ReporteDePrueba.txt");
    liberarEspacios(alumnos);

    return 0;
}

