/* 
 * File:   Preg2_Funciones_de_historia_de_notas.cpp
 * Author: ramir
 * 
 * Created on 22 de abril de 2024, 11:00
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_historia_de_notas.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1
//Cargar notas
/*
202123703,MEC270,202302,14
202315643,MEC270,202202,13
*/
void cargarNotas(char ***&cursos_cod,int ***&cursos_nota_sem_veces,
            double **&costos,int **alumnos,int *alumnos_nom_mod,double *escalas,
                 char ***cursos,double *cursos_cred,const char *nombArch){
    int **buffCurNotSemVec[100],codAlum,ind;
    char **buffCurCod[100],*codigo;
    double *buffCost[100];
    ifstream archNot;
    AperturaDeUnArchivoDeTextosParaLeer(archNot,nombArch);
    int i=0;
    while(1){
        archNot>>codAlum;
        if(archNot.eof()) break;
        ind = buscarPosAlum(alumnos,codAlum);
        
    }
}

int buscarPosAlum(int **alumnos,int codAlum){
    int *auxAlum;
    for(int i=0;alumnos[i]!=nullptr;i++){
        auxAlum = alumnos[i];
        if(auxAlum[0]==codAlum) return i;
    }
    return NO_ENCONTRADO;
}
//Prueba de carga de notas
void pruebaDeCargaDeNotas(char ***cursos_cod,int ***cursos_nota_sem_veces,
                          double **costos,int **alumnos,int *alumnos_nom_mod,
                          const char *nombArch);