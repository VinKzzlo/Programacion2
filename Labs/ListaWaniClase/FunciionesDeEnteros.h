/* 
 * Archivo:   FuncionesDeEnteros.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:45
 */

#ifndef FUNCIONESDEENTEROS_H
#define FUNCIONESDEENTEROS_H

int miCmpInt(const void *, const void *);
void *leerInt(ifstream &arch);
void imprimeInt(ofstream &arch,void*d);
void eliminaInt(void *d);

#endif /* FUNCIONESDEENTEROS_H */

