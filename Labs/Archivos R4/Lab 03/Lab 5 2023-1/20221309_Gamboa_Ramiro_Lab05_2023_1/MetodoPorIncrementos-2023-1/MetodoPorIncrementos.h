/* 
 * File:   MetodoPorIncrementos.h
 * Author: ramir
 *
 * Created on 14 de abril de 2024, 09:24
 */
#include <fstream>
using namespace std;
#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H
//Carga de Cursos
void cargaCursos(const char *nombArch,char ***&cursos_datos,int *&cursos_credito,
               char ****&cursos_alumnos,double **&cursos_informacion_economica);
char **leeRegistroDeCurso(ifstream &archCur);
char *leeCadenaExacta(ifstream &arch,int max,char delim);
void aumentarCapCurso(char ***&cursos_datos,int *&cursos_credito,
                char ****&cursos_alumnos,double **&cursos_informacion_economica,
                      int *&numAlum,int *&capAlum,int &numDatos,int &capacidad);
void cambiarAuxAPuntero(char ***&cursos_datos,int *&cursos_credito,
                char ****&cursos_alumnos,double **&cursos_informacion_economica,
                        int *&numAlum,int *&capAlum,int numDatos,int capacidad);
void agregarCurso(char ***&cursos_datos,int *&cursos_credito,char **regCurso,
                  int credito,int &numDatos);
void agregarAlumnos(ifstream &archCur,char ***&cursos_alumnos,int &numDatos,
                    int &capacidad,double &ingrBruto);
void leeRegistroDeAlumno(ifstream &archCur,char **&regAlum,double &escala);
//Prueba de Cursos
void pruebaCursos(const char *nombArch,char ***cursos_datos,int *cursos_credito,
                  char ****cursos_alumnos,double **cursos_informacion_economica);
//Reporte de Alumnos por Curso
void reporteDeAlumnosPorCurso(const char *nombArch,char ***cursos_datos,
                              int *cursos_credito,char ****cursos_alumnos,
                              double **cursos_informacion_economica);
#endif /* METODOPORINCREMENTOS_H */
