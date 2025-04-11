/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de abril de 2024, 14:46
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
    
    AperturaDeUnArchivoDeTextosParaLeer(archCur,"Cursos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,"Alumnos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archMat,"Matricula.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCur,"ReporteCursos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepAlum,"ReporteAlumnos.txt");
    
    struct StCurso arrCur[10],cur;
    struct StAlumno arrAlum[100],alum;
    struct StRegistroDeMatricula matri;
    
    strcpy(arrCur[0].codigoDelCurso,"XXXXXX");
    arrAlum[0].semestre = 0;
    
    while(1){
        if(!(archCur>>cur)) break;
        arrCur += cur;
    }
    while(1){
        if(!(archAlum>>alum)) break;
        arrAlum += alum;
    }
    while(1){
        if(!(archMat>>matri)) break;
        arrCur *= matri;
        arrAlum *= matri;
    }
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        archRepCur<<arrCur[i];
    for(int i=0;arrAlum[i].semestre!=0;i++)
        archRepAlum<<arrAlum[i];
    
    return 0;
}

