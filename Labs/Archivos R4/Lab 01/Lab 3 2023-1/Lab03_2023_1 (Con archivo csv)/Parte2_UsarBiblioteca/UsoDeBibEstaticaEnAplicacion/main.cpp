/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de abril de 2024, 14:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"
int main(int argc, char** argv) {
    
    struct StCurso arrCur[10];
    struct StAlumno arrAlum[100];
    //Parte A
    leerCursos(arrCur,"Cursos.csv");
    //Parte B
    leerAlumnos(arrAlum,"Alumnos.csv");
    //Parte C
    completarCursosYAlumnos(arrCur,arrAlum,"Matricula.csv");
    //Parte D
    calcularIngresosYCostos(arrCur,arrAlum,"Escalas.csv");
    //Parte E
    imprimirReporte(arrCur,arrAlum,"Reporte.txt");
    
    return 0;
}

