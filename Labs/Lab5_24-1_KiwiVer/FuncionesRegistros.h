/* 
 * Archivo:   FuncionesRegistros.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:54
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

void *leeregistro(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,char delim='\n');
void imprimeregistro(ofstream &arch, void* dato);
int cmpregistro( void *a,  void *b);
#endif /* FUNCIONESREGISTROS_H */

