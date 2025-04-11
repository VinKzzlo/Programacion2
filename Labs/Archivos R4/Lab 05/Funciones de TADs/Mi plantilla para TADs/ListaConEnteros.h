/* 
 * File:   ListaConEnteros.h
 * Author: ramir
 *
 * Created on 1 de mayo de 2024, 20:33
 */
#include <fstream>
using namespace std;
#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leenumero(ifstream &archReg);
int cmpnumero(void *a,void *b);
void imprimenum(ofstream &archRep,void *dato);

#endif /* LISTACONENTEROS_H */
