/* 
 * File:   ListaGenerica.h
 * Author: ramir
 *
 * Created on 1 de mayo de 2024, 20:31
 */
#include <fstream>
using namespace std;
#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H

void creaLista(void *&lista,void*(*lee)(ifstream &),int(*cmp)(void *,void *),
               const char *nombArch);
void generalista(void *&lista);
void insertarLista(void *lista,void *dato,int(*cmp)(void *,void *));
bool listavacia(void *lista);
void uneLista(void *lista1,void *lista2);
void imprimeLista(void *lista,void(*imprime)(ofstream &,void *),
                  const char *nombArch);

#endif /* LISTAGENERICA_H */
