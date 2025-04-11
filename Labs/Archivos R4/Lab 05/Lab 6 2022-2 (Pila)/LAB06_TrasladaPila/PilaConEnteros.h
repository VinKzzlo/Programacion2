/* 
 * File:   PilaConEnteros.h
 * Author: ramir
 *
 * Created on 30 de abril de 2024, 10:06
 */
#include <fstream>
using namespace std;
#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
void *leenumero(ifstream &arch);
int cmpnumero(const void *a,const void *b);
void imprimenumero(ofstream &archRep,void *dato);
#endif /* PILACONENTEROS_H */
