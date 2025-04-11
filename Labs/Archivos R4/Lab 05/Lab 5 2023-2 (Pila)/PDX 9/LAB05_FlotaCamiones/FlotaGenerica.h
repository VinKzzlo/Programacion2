
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  FlotaGenerica.h
 * Autor: Redbull te da aaaaalas.jpg
/*/

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

                /*  - / > [ Declaracion de Funciones ] < / -  */

void cargaCamiones(void *&,const int,const double,void *(*)(ifstream &),
                   double *(*)(void *),const char *);

void push(void *,void **,const int,const double,int &,double *(*)(void *));

void agregarDatosHaciaPila(void *,void *,double *);

bool pilavacia(void **);

void muestraCamiones(void *,const int,void (*)(ofstream &,void **,int),
                     const char *);

#endif /* FLOTAGENERICA_H */
