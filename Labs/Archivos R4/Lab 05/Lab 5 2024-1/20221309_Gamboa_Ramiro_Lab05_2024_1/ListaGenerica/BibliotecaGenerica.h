/* 
 * File:   BibliotecaGenerica.h
 * Author: ramir
 *
 * Created on 12 de mayo de 2024, 00:08
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

void crealista(void *&lista,void*(*lee)(ifstream &),const char *nombArch);
void generalista(void *&lista);
void insertalista(void *lista,void *dato);
bool listavacia(void *lista);
void imprimelista(void *lista,void(*imprime)(ofstream &,void*),
                  const char *nombArch);
void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,
                  int(*cmp)(void*,void*));
void *quitalista(void *lista);

#endif /* BIBLIOTECAGENERICA_H */
