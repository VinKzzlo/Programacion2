
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  PilaConRegistros.h
 * Autor: Redbull te da aaaaalas.jpg
/*/

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

                /*  - / > [ Declaracion de Funciones ] < / -  */

void *leeregistro(ifstream &);

double *calcularegistro(void *);

int cmpregistro(const void *,const void *);

void imprimeregistro(ofstream &,void **,int);

char *obtenerCadenaExacta(ifstream &,char);

#endif /* PILACONREGISTROS_H */
