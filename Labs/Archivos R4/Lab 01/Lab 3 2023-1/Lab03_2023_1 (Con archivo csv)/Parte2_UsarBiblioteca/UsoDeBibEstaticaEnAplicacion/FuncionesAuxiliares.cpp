/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ramir
 * 
 * Created on 4 de abril de 2024, 14:51
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
#define MAX_ESC 5
#define NO_ENCONTRADO -1
//Parte A
void leerCursos(struct StCurso *arrCur,const char *nombArch){
    ifstream archCur;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCur,nombArch);
    
    struct StCurso cur;
    
    strcpy(arrCur[0].codigoDelCurso,"XXXXXX");
    
    while(1){
        if(!(archCur>>cur)) break;
        arrCur += cur;
    }
}
//Parte B
void leerAlumnos(struct StAlumno *arrAlum,const char *nombArch){
    ifstream archAlum;
    
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,nombArch);
    
    struct StAlumno alum;
    
    arrAlum[0].semestre = 0;
    
    while(1){
        if(!(archAlum>>alum)) break;
        arrAlum += alum;
    }
}
//Parte C
void completarCursosYAlumnos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch){
    ifstream archMat;
    
    AperturaDeUnArchivoDeTextosParaLeer(archMat,nombArch);
    
    struct StRegistroDeMatricula matri;
    
    while(1){
        if(!(archMat>>matri)) break;
        arrCur *= matri;
        arrAlum *= matri;
    }
}
//Parte D
void calcularIngresosYCostos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch){
    double arrCostoXEsc[MAX_ESC];
    leerEscalas(arrCostoXEsc,nombArch);
    //Calculo de ingresos de cursos
    int escAlum;
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        for(int j=0;j<arrCur[i].numeroDeAlumnos;j++){
            escAlum = buscarEscalaDelAlumno(arrCur[i].alumnos[j],arrAlum);
            if(escAlum!=NO_ENCONTRADO)
                arrCur[i].ingresos += arrCostoXEsc[escAlum-1]*
                                      arrCur[i].creditos;
        }
    //Calculo de costo total del alumno
    double credCur;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        for(int j=0;j<arrAlum[i].numeroDeCursos;j++){
            credCur = buscarCredDelCurso(arrAlum[i].cursos[j],arrCur);
            if(credCur!=NO_ENCONTRADO)
                arrAlum[i].costoTotal += arrCostoXEsc[arrAlum[i].escala-1]*
                                         credCur;
        }
}
/*G2,362.00*/
void leerEscalas(double *arrCostoXEsc,const char *nombArch){
    ifstream archEsc;
    
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,nombArch);
    
    char c;
    int escala;
    double costo;
    for(int i=0;i<MAX_ESC;i++){
        archEsc>>c>>escala>>c>>costo;
        archEsc.get();
        arrCostoXEsc[escala-1] = costo;
    }
}

int buscarEscalaDelAlumno(int codAlum,struct StAlumno *arrAlum){
    int semestre = codAlum/10000;
    int codigo = codAlum%10000;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        if(arrAlum[i].semestre==semestre && arrAlum[i].codigo==codigo)
            return arrAlum[i].escala;
    return NO_ENCONTRADO;
}

double buscarCredDelCurso(char *codCurso,struct StCurso *arrCur){
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        if(strcmp(arrCur[i].codigoDelCurso,codCurso)==0) 
            return arrCur[i].creditos;
    return NO_ENCONTRADO;
}

//Parte E
void imprimirReporte(struct StCurso *arrCur,struct StAlumno *arrAlum,
                     const char *nombArch){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE CURSOS"<<endl;
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        archRep<<arrCur[i];
    
    archRep<<"REPORTE DE ALUMNOS"<<endl;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        archRep<<arrAlum[i];
}