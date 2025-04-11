/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Preg2_Funciones_de_historia_de_notas.h
 * Author: ramir
 *
 * Created on 22 de abril de 2024, 11:00
 */
#include <fstream>
using namespace std;
#ifndef PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
#define PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
//Cargar notas
void cargarNotas(char ***&cursos_cod,int ***&cursos_nota_sem_veces,
            double **&costos,int **alumnos,int *alumnos_nom_mod,double *escalas,
                 char ***cursos,double *cursos_cred,const char *nombArch);
int buscarPosAlum(int **alumnos,int codAlum);
//Prueba de carga de notas
void pruebaDeCargaDeNotas(char ***cursos_cod,int ***cursos_nota_sem_veces,
                          double **costos,int **alumnos,int *alumnos_nom_mod,
                          const char *nombArch);
#endif /* PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H */
