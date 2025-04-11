/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: ramir
 *
 * Created on 23 de abril de 2024, 10:48
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
void creaLista(void *&lista1,void *(*lee)(ifstream &),
               int (*cmpnum)(void*,void*),const char *nombArch);
void generaLista(void *&lista);
void insertaLista(void *lista,void *dato,int (*cmp)(void*,void*));
bool listavacia(void *lista);
void uneLista(void *lista1,void *lista2);
void imprimeLista(void *lista,void(*imprime)(void *,ofstream &),
                  const char *nombArch);
#endif /* BIBLIOTECALISTAGENERICA_H */
