
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  PilaConEnteros.h
 * Autor: Redbull te da aaaaalas.jpg
/*/

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

                /*  - / > [ Declaracion de Funciones ] < / -  */

void *leenumero(ifstream &);

double *calculanumero(void *);

int cmpnumero(const void *,const void *);

void imprimenumero(ofstream &,void **,int);

#endif /* PILACONENTEROS_H */
