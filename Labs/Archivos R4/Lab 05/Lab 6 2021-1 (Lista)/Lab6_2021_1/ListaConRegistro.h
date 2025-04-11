/* 
 * File:   ListaConRegistro.h
 * Author: ramir
 *
 * Created on 30 de abril de 2024, 22:11
 */
#include <fstream>
using namespace std;
#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H
void *leeregistro(ifstream &archReg);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
int cmpregistro(void *a,void *b);
void imprimeregistro(ofstream &archRep,void *dato);
char *buscarNombConductor(int licencia);
#endif /* LISTACONREGISTRO_H */
