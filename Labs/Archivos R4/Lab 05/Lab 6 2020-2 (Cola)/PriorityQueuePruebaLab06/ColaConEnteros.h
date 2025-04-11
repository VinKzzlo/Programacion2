/* 
 * File:   ColaConEnteros.h
 * Author: ramir
 *
 * Created on 13 de mayo de 2024, 22:07
 */
#include <fstream>
using namespace std;
#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

void *leenumero(ifstream &archReg);
int prioridadnum(void *dato);
void imprimenum(ofstream &archRep,void *dato);

#endif /* COLACONENTEROS_H */
