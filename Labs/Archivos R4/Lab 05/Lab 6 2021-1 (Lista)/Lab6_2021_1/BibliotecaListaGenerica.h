/* 
 * File:   BibliotecaListaGenerica.h
 * Author: ramir
 *
 * Created on 30 de abril de 2024, 22:10
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
//Crear lista
void creaLista(void *&lista,void*(*lee)(ifstream &),int(*cmpnum)(void*,void*),
               const char *nombArch);
void generalista(void *&lista);
void insertarLista(void *lista,void *dato);
bool listavacia(void *lista);
//Unir lista
void uneLista(void *lista1,void *lista2);
//Imprimir lista
void imprimeLista(void *lista,void(*imprime)(ofstream &,void*),
                  const char *nombArch);
#endif /* BIBLIOTECALISTAGENERICA_H */
