/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: ramir
 *
 * Created on 14 de mayo de 2024, 00:14
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
                  void*(*lee)(ifstream &),const char *nombArch);
void cargapila(void *&pila,void *arreglo);
void generapila(void *&pila);
void push(void *pila,void *dato);
void muevepila(void *pilaini,void *&pilafin);
void imprimepila(void *pilafin,void(*imprime)(ofstream &,void*),
                 const char *nombArch);

#endif /* BIBLIOTECAPILAGENERICA_H */
