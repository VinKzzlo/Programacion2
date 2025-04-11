/* 
 * File:   ColaConRegistros.h
 * Author: ramir
 *
 * Created on 13 de mayo de 2024, 23:11
 */
#include <fstream>
using namespace std;
#ifndef COLACONREGISTROS_H
#define COLACONREGISTROS_H

void *leeregistro(ifstream &archReg);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
int prioridadregistro(void *dato);
void imprimeregistro(ofstream &archRep,void *dato);
void leerTarifas(double **&arrTarifas,const char *nombArchTar);
void agregarDatos(double *&arrTarifas,double codEsp,double tarifa);
void imprimirEncabezado(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);

#endif /* COLACONREGISTROS_H */
