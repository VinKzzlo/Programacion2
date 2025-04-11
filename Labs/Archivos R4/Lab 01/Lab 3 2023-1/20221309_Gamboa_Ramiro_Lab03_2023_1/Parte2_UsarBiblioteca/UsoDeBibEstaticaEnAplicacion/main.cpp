/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 30 de marzo de 2024, 20:31
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
#include "OperadoresSobrecargados.h"
int main(int argc, char** argv) {

    struct StCurso arrCur[10];
    struct StAlumno arrAlum[100];
    //Parte A
    leerCursos(arrCur,"Cursos.txt");
    //Parte B
    leerAlumnos(arrAlum,"Alumnos.txt");
    //Parte C
    leerMatricula(arrCur,arrAlum,"Matricula.txt");
    //Parte D
    calcularIngresosYCostos(arrCur,arrAlum,"Escalas.txt");
    //Parte E
    imprimirReporte(arrCur,arrAlum,"Reporte.txt");

    return 0;
}

