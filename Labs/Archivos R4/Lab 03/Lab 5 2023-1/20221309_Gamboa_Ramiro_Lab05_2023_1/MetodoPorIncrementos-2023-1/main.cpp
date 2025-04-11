/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 14 de abril de 2024, 09:23
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoPorIncrementos.h"
int main(int argc, char** argv) {
    
    char ***cursos_datos,****cursos_alumnos;
    int *cursos_credito;
    double **cursos_informacion_economica;
    
    cargaCursos("matricula_ciclo_2023_1.csv",cursos_datos,cursos_credito,
                cursos_alumnos,cursos_informacion_economica);
    pruebaCursos("PruebaCursos.txt",cursos_datos,cursos_credito,cursos_alumnos,
                 cursos_informacion_economica);
    /*
    reporteDeAlumnosPorCurso("ReporteDeAlumnosPorCurso.txt",cursos_datos,
                    cursos_credito,cursos_alumnos,cursos_informacion_economica);
    */
    return 0;
}

