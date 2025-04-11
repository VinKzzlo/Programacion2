/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 28 de marzo de 2024, 11:40
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
    
    struct StCurso cur,arrCur[10];
    struct StAlumno alum,arrAlum[100];
    struct StRegistroDeMatricula matri;
    
    strcpy(arrCur[0].codigoDelCurso,"XXXXXX");
    arrAlum[0].semestre = 0;
    
    archCur>>cur;
    arrCur += cur;
    archAlum>>alum;
    arrAlum += alum;
    
    archMat>>matri;
    arrCur *= matri;
    arrAlum *= matri;
    archMat>>matri;
    arrCur *= matri;
    arrAlum *= matri;
    
    archRepCur<<arrCur[0];
    archRepAlum<<arrAlum[0];
    
    return 0;
}