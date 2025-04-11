/* 
 * File:   FuncionesRegistros.h
 * Author: ramir
 *
 * Created on 12 de mayo de 2024, 00:08
 */
#include <fstream>
using namespace std;
#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

void *leeregistro(ifstream &archReg);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
void imprimeregistro(ofstream &archRep,void *dato);
int cmpregistro(void *a,void *b);

#endif /* FUNCIONESREGISTROS_H */
