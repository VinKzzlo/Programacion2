/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: cueva.r
 *
 * Created on 10 de septiembre de 2024, 10:23 AM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#include <fstream>
using namespace std;

    void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,
        double *escalas,const char*nomcur,const char*nomesc);
    void leecursos(char ***&cursos,double *&cursos_cred,ifstream &arch);
    void aumentarmemoria(char ***&cursos,double *&cursos_cred,
        int &numdat,int &capacidad);
    char **leecurso(ifstream &arch,double &creditos);
    char *leercadena(ifstream &arch,int max,char deli);
    void cargarAlumnos(int* &alumnos_cod,int**&alumnos,
        char ***&alumnos_nom_mod,const char*nom);
    void aumentarespacio(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,
                    int &numdat,int &capacidad);
    int leealumno(ifstream &arch,int *&regent,char**&regcad);

#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */
