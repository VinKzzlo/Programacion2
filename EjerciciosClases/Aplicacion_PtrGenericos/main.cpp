/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  17 de septiembre de 2024, 8:32
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
    void *alumnos,*notas;
    cargarAlumno(alumnos,"Alumnos.csv");
    ordenarAlumnos(alumnos);
    probarLaLectura(alumnos,"ReporteDePrueba.txt");
//    cargarNotas(notas,"Notas.csv");
    return 0;
}

