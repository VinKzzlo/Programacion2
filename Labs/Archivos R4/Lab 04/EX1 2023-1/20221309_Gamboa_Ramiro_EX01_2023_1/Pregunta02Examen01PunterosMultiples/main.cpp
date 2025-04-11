/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 22 de abril de 2024, 10:51
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_historia_de_notas.h"
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
    
    int ***cursos_nota_sem_veces;
    double **costos;
    char ***cursos_cod;
    
    //Cargar notas
    cargarNotas(cursos_cod,cursos_nota_sem_veces,costos,alumnos,alumnos_nom_mod,
                escalas,cursos,cursos_cred,"HistoriaDeNotas.csv");
    //Prueba de carga de notas
    pruebaDeCargaDeNotas(cursos_cod,cursos_nota_sem_veces,costos,alumnos,
                         alumnos_nom_mod,"PruebaDeNotas.txt");
    
    return 0;
}