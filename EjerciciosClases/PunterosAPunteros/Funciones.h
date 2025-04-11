/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   Funciones.h
 * Autor: VinKzzlo
 *
 * Creado el on 28 de agosto de 2024, 9:25
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarAlumnos(int *&codigos, char **&nombres, char ***&cursos,
                   const char *nombArch);
char* leeNombre(ifstream &arch);
char** leeCursos(ifstream &arch);
void imprimirAlumnos(int *&codigos, char **&nombres, char ***&cursos,
                     const char *nombArch);
#endif /* FUNCIONES_H */

