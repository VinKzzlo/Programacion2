/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 21 de abril de 2024, 09:13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
int main(int argc, char** argv) {
    
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred,escalas[5];
    int *alumnos_cod,**alumnos;
    
    //Cargar cursos y escalas
    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    //Prueba de carga de cursos
    pruebaDeCargaDeCursos(cursos,cursos_cred,"PruebaCursos.txt");
    //Cargar alumnos
    cargaAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    //Prueba de carga de alumnos
    pruebaDeCargaDeAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"PruebaAlumnos.txt");
    
    return 0;
}

