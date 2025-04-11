/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: ramir
 *
 * Created on 21 de abril de 2024, 09:13
 */
#include <fstream>
using namespace std;
#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
//Cargar cursos y escalas
void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
                          const char *nombArchCur,const char *nombArchEsc);
void leerCursos(ifstream &archCur,char ***&cursos,double *&cursos_cred);
char **leerRegistroCur(ifstream &archCur,double &creditos);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
void aumentarCapCursos(char ***&cursos,double *&cursos_cred,int &numDatos,
                       int &capacidad);
void agregarCursos(char ***cursos,double *cursos_cred,char **registroCur,
                   double creditos,int &numDatos);
void leerEscalas(ifstream &archEsc,double *escalas);
//Prueba de carga de cursos
void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,
                           const char *nombArch);
//Cargar alumnos
void cargaAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,
                  const char *nombArch);
void aumentarCapAlumnos(int *&alumnos_cod,int **&alumnos,
                        char ***&alumnos_nom_mod,int &numDatos,int &capacidad);
void cambiarAuxAPuntero(int *&alumnos_cod,int **&alumnos,
                        char ***&alumnos_nom_mod,int numDatos,int capacidad);
void modificarRegistro(ifstream &archAlum,int *&registroAlumCod,
                       char **&registroAlumNomb,int codigo);
void agregarAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,
                    int codigo,int *registroAlumCod,char **registroAlumNomb,
                    int &numDatos);
//Prueba de carga de alumnos
void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,
                            char ***alumnos_nom_mod,const char *nombArch);
#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */
