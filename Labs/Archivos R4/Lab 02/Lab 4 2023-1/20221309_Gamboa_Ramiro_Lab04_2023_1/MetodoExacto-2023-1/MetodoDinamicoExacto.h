/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: ramir
 *
 * Created on 7 de abril de 2024, 13:48
 */
#include <fstream>
using namespace std;
#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
//Lectura de Alumnos
void lecturaAlumnos(const char *nombArch,int *&alumno_Codigo,
                    char **&alumno_Nombre,char *&alumno_Modalidad,
                    int *&alumno_Porcentaje,int *&alumno_Escala);
char *leeCadena(ifstream &archAlum,int max,char delim);
void modificaModalidad(ifstream &archAlum,char &modalidad,int &porcentaje,
                       int &escala);
void cargarArrAlumnos(int *&alumno_Codigo,char **&alumno_Nombre,
                      char *&alumno_Modalidad,int *&alumno_Porcentaje,
                      int *&alumno_Escala,int *buffCod,char **buffNomb,
                      char *buffMod,int *buffPorc,int *buffEsc,int n);
//Prueba de Lectura de Alumnos
void pruebaLecturaAlumnos(const char *nombArch,int *alumno_Codigo,
                          char **alumno_Nombre,char *alumno_Modalidad,
                          int *alumno_Porcentaje,int *alumno_Escala);
//Lectura de Cursos
void lecturaCursos(const char *nombArch,int *alumno_Codigo,int *alumno_Escala,
              char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos);
void agregarAlumnoACurso(int **buffCurAlum,char **buffCurNomb,double *buffCurCred,
                         int *alumno_Codigo,int *alumno_Escala,int codAlum,
                         char *nombCur,double creditos,int *numAlum,int &i);
void cargaArrCursos(char **&curso_Nombre,double *&curso_Credito,
                    int **&curso_Alumnos,int **buffCurAlum,char **buffCurNomb,
                    double *buffCurCred,int *numAlum,int n);
void cargaAlumnosExacto(int *&curAlum,int *buffcuralum,int cantAlum);
//Prueba de Lectura de Cursos
void pruebaDeLecturaCursos(const char *nombArch,char **curso_Nombre,
                           double *curso_Credito,int **curso_Alumnos);
//Reporte de Recaudacion por Modalidad
void reporteDeRecaudacionPorModalidad(const char *nombArch,int *alumno_Codigo,
            char *alumno_Modalidad,int *alumno_Porcentaje,char **alumno_Nombre,
            char **curso_Nombre,double *curso_Credito,int **curso_Alumnos);
void leerEscalas(const char *nombArch,double *arrCostoXCred);
void imprimirLinea(ofstream &archRep,char c);
void imprimirEncabezadoCursos(ofstream &archRep);
int buscarPosicionAlumno(int *alumno_Codigo,int codAlum);
void imprimirPagos(ofstream &archRep,char modalidad,double creditos,
                   int porcentaje,int escala,double &recauPre,double &recauSem,
                   double &recauVir,double *arrCostoXCred);
#endif /* METODODINAMICOEXACTO_H */
