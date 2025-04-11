/* 
 * Archivo:   BibliotecaListaGenerica.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:45
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

void creaLista(const char*nombArch, void *&lista, void *(*lee)(ifstream&),
                 int(*compara)(const void*, const void*));
void insertarEnLista(void *dato, void*&lista,
                 int(*compara)(const void*, const void*));
void imprimirLista(const char*nombArch, void *lista,
                 void (*imprimeDato)(ofstream &arch, void*));
void eliminarLista(void *lista, void (*eliminarDato)(void*));


#endif /* BIBLIOTECALISTAGENERICA_H */

