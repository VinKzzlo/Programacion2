/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 25 de marzo de 2024, 23:00
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
int main(int argc, char** argv) {

    ifstream archCur,archAlum,archMat;
    ofstream archRepCur,archRepAlum;
    AperturaDeUnArchivoDeTextosParaLeer(archCur,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMat,"Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCur,"ReporteCursos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepAlum,"ReporteAlumnos.txt");
    
    StCurso cur,arrCur[100];
    StAlumno alum,arrAlum[100];
    StRegistroDeMatricula matri;
    
    strcpy(arrCur[0].codigoDelCurso,"XXXXXX");
    arrAlum[0].semestre = 0;
    
    archCur>>cur;
    arrCur += cur;
    archAlum>>alum;
    arrAlum += alum;

    return 0;
}

