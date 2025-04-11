/* 
 * File:   FuncionesEnteras.h
 * Author: ramir
 *
 * Created on 12 de mayo de 2024, 00:08
 */
#include <fstream>
using namespace std;
#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

void *leenum(ifstream &archReg);
void imprimenum(ofstream &archRep,void *dato);
int cmpnum(void *a,void *b);

#endif /* FUNCIONESENTERAS_H */
