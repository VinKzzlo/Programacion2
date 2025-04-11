/* 
 * File:   ListaGenerica.h
 * Author: ramir
 *
 * Created on 2 de mayo de 2024, 23:37
 */
#include <fstream>
using namespace std;
#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H

void creaLista(void *&lista,void*(*lee)(ifstream &),const char *nombArch);
void generalista(void *&lista);
void insertarLista(void *lista,void *dato);
bool listavacia(void *lista);
void uneLista(void *&listafin,void *lista1,void *lista2,int(*cmp)(void*,void*));
void imprimeLista(void *lista,void(*imprime)(ofstream &,void *),
                  const char *nombArch);

#endif /* LISTAGENERICA_H */
