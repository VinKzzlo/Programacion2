/* 
 * File:   FunConEnteros.h
 * Author: ramir
 *
 * Created on 27 de abril de 2024, 21:20
 */

#include <fstream>
using namespace std;

#ifndef FUNCONENTEROS_H
#define FUNCONENTEROS_H

void *leenumero(ifstream &arch);
int prioridadnumero(void *dato);
void imprimirnum(void *cola,const char *nombArch);

#endif /* FUNCONENTEROS_H */
