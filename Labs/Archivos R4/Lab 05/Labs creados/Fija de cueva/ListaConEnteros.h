/* 
 * File:   ListaConEnteros.h
 * Author: ramir
 *
 * Created on 2 de mayo de 2024, 23:37
 */
#include <fstream>
using namespace std;
#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leenumero(ifstream &archReg);
int cmpnumero(void *a,void *b);
void imprimenumero(ofstream &archRep,void *dato);

#endif /* LISTACONENTEROS_H */
