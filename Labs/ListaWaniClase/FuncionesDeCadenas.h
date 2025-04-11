/* 
 * Archivo:   FuncionesDeCadenas.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:45
 */

#ifndef FUNCIONESDECADENAS_H
#define FUNCIONESDECADENAS_H

void*leeCadena(ifstream &arch);
int miStrcmp(const void*, const void *);
void imprimeStr(ofstream &arch, void*);
void eliminaStr(void*dato);

#endif /* FUNCIONESDECADENAS_H */

