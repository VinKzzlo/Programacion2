/* 
 * Archivo:   FuncionesDePunterosGenericos.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:46
 */

#ifndef FUNCIONESDEPUNTEROSGENERICOS_H
#define FUNCIONESDEPUNTEROSGENERICOS_H

void *leerRegistro(ifstream &arch);
void imprimirDatos(void*per, int np, const char *nombArch);
void imprimePersona(ofstream &arch,void *per);
int miVoidcmpCodigos(const void *a, const void *b);
int miVoidcmpNombres(const void *a, const void *b);
int miVoidcmpSueldos(const void *a, const void *b);
void eliminaReg(void *dato);
char*leeCadena(ifstream &arch, char delimitador='\n');

#endif /* FUNCIONESDEPUNTEROSGENERICOS_H */

