/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 10 de septiembre de 2024, 10:19 AM
 */

#include "Preg1_Funciones_de_cursos_y_alumnos.h"

using namespace std;

int main(int argc, char** argv) {
    int *alumnos_cod,**alumnos;
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred,escalas[5];

    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    
    return 0;
}

