/* 
 * File:   MetodoPorIncrementos.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 14 de abril de 2024, 09:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoPorIncrementos.h"
#define INCREMENTO 5
//Carga de Cursos
/*
INF263,Algoritmia,4,PATINO MEZA MANUEL,20239927.3,LEE VASQUEZ JENNY,20239103.4,...
*/
void cargaCursos(const char *nombArch,char ***&cursos_datos,int *&cursos_credito,
               char ****&cursos_alumnos,double **&cursos_informacion_economica){
    int credito,numDatos = 0,capacidad = 0,*numAlum,*capAlum;
    char **regCurso;
    double ingrBrutos;
    ifstream archCur(nombArch,ios::in);
    if(not archCur.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    cursos_datos = nullptr;
    while(1){
        ingrBrutos = 0;
        regCurso = leeRegistroDeCurso(archCur);
        if(archCur.eof()) break;
        archCur>>credito;
        archCur.get();
        if(numDatos==capacidad)
            aumentarCapCurso(cursos_datos,cursos_credito,cursos_alumnos,
                             cursos_informacion_economica,numAlum,capAlum,
                             numDatos,capacidad);
        agregarCurso(cursos_datos,cursos_credito,regCurso,credito,numDatos);
        while(1){
            agregarAlumnos(archCur,cursos_alumnos[numDatos-1],
                           numAlum[numDatos-1],capAlum[numDatos-1],ingrBrutos);
            if(archCur.get()=='\n');
        }
    }
}
//Lectura de cadena del segundo nivel del puntero
char **leeRegistroDeCurso(ifstream &archCur){
    char **registro,*codigo;
    codigo = leeCadenaExacta(archCur,7,',');
    if(archCur.eof()) return nullptr;
    registro = new char*[2];
    registro[0] = codigo;
    registro[1] = leeCadenaExacta(archCur,40,',');
    return registro;
}
//Lectura de cadena del primer nivel del puntero
char *leeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void aumentarCapCurso(char ***&cursos_datos,int *&cursos_credito,
                char ****&cursos_alumnos,double **&cursos_informacion_economica,
                      int *&numAlum,int *&capAlum,int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    if(cursos_datos==nullptr){
        cursos_datos = new char**[capacidad];
        cursos_credito = new int[capacidad];
        cursos_alumnos = new char***[capacidad];
        cursos_informacion_economica = new double*[capacidad];
        numAlum = new int[capacidad];
        capAlum = new int[capacidad];
        cursos_datos[0] = nullptr;
        cursos_credito[0] = 0;
        cursos_alumnos[0] = nullptr;
        cursos_informacion_economica[0] = nullptr;
        numAlum[0] = 0;
        capAlum[0] = 0;
    }else
        cambiarAuxAPuntero(cursos_datos,cursos_credito,cursos_alumnos,
                           cursos_informacion_economica,numAlum,capAlum,
                           numDatos,capacidad);
}

void cambiarAuxAPuntero(char ***&cursos_datos,int *&cursos_credito,
                char ****&cursos_alumnos,double **&cursos_informacion_economica,
                        int *&numAlum,int *&capAlum,int numDatos,int capacidad){
    int *auxCurCred,*auxNumAlum,*auxCapAlum;
    char ***auxCurDat,****auxCurAlum;
    double **curInfEcom;
    auxCurDat = new char**[capacidad];
    auxCurCred = new int[capacidad];
    auxCurAlum = new char***[capacidad];
    curInfEcom = new double*[capacidad];
    auxNumAlum = new int[capacidad];
    auxCapAlum = new int[capacidad];
    for(int i=0;i<numDatos;i++){
        auxCurDat[i] = cursos_datos[i];
        auxCurCred[i] = cursos_credito[i];
        auxCurAlum[i] = cursos_alumnos[i];
        curInfEcom[i] = cursos_informacion_economica[i];
        auxNumAlum[i] = numAlum[i];
        auxCapAlum[i] = capAlum[i];
    }
    delete cursos_datos;
    delete cursos_credito;
    delete cursos_alumnos;
    delete cursos_informacion_economica;
    delete numAlum;
    delete capAlum;
    cursos_datos = auxCurDat;
    cursos_credito = auxCurCred;
    cursos_alumnos = auxCurAlum;
    cursos_informacion_economica = curInfEcom;
    numAlum = auxNumAlum;
    capAlum = auxCapAlum;
}

void agregarCurso(char ***&cursos_datos,int *&cursos_credito,char **regCurso,
                  int credito,int &numDatos){
    cursos_datos[numDatos-1] = regCurso;
    cursos_datos[numDatos] = nullptr;
    cursos_credito[numDatos-1] = credito;
    cursos_credito[numDatos] = -1;
}
//PATINO MEZA MANUEL,20239927.3
void agregarAlumnos(ifstream &archCur,char ***&cursos_alumnos,int &numDatos,
                    int &capacidad,double &ingrBruto){
    double escala;
    char **regAlum;
    leeRegistroDeAlumno(archCur,regAlum,escala);
}

void leeRegistroDeAlumno(ifstream &archCur,char **&regAlum,double &escala){
    double codigo;
    char *codigoEscStr = new char[11];
    regAlum = new char*[2];
    regAlum[0] = leeCadenaExacta(archCur,40,',');
    archCur>>codigo;
    sprintf(codigoEscStr,"%.1f",codigo);
    
}
//Prueba de Cursos
void pruebaCursos(const char *nombArch,char ***cursos_datos,int *cursos_credito,
                  char ****cursos_alumnos,double **cursos_informacion_economica);
//Reporte de Alumnos por Curso
void reporteDeAlumnosPorCurso(const char *nombArch,char ***cursos_datos,
                              int *cursos_credito,char ****cursos_alumnos,
                              double **cursos_informacion_economica);