/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor: VinKzzlo
 *
 * Creado el on 4 de septiembre de 2024, 9:15
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void  cargarAlumnos(int *&codigos, int **&nombres, const char *nombArch);
char* leeCadena(ifstream &arch, char = '\n');
void incrementarEspacios(int *&codigos,char **&nombres,int &nd, int &cap);
void  cargarCursos(int *&codigos, char ***&cursos, const char *nombArch);
void  imprimirAlumnos(int *&codigos, int **&nombres, int ***&cursos,
                      const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */

