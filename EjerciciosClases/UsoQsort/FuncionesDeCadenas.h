/* 
 * Archivo:   FuncionesDeCadenas.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de septiembre de 2024, 9:14
 */

#ifndef FUNCIONESDECADENAS_H
#define FUNCIONESDECADENAS_H

void leerDatos(char**& personas,int &nPer, const char*nombArch);
char*leeCadena(ifstream &arch);
int miStrcmp(const void *,const void *);

#endif /* FUNCIONESDECADENAS_H */

