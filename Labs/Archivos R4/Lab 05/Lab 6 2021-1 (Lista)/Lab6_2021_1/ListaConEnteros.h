/* 
 * File:   ListaConEnteros.h
 * Author: ramir
 *
 * Created on 30 de abril de 2024, 22:11
 */
#include <fstream>
using namespace std;
#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
void *leenum(ifstream &archReg);
int cmpnum(void *a,void *b);
void imprimenum(ofstream &archRep,void *dato);
#endif /* LISTACONENTEROS_H */
