/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: ramir
 *
 * Created on 30 de abril de 2024, 10:06
 */
#include <fstream>
using namespace std;
#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H
void cargaarreglo(void *&arreglo,int(*cmp)(const void*,const void*),
                  void*(*lee)(ifstream &),const char *nombArch);
void cargapila(void *&pilaini,void *arreglo);
void generapila(void *&pila);
void push(void *pila,void *dato);
void muevepila(void *pilaini,void *&pilafin);
void hanoi(int n,void *ini,void *aux,void *fin);
void *pop(void *pila);
bool pilavacia(void *pila);
void imprimepila(void *pila,void(*imprime)(ofstream &,void*),
                 const char *nombArch);
#endif /* BIBLIOTECAPILAGENERICA_H */
