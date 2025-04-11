/* 
 * Archivo:   BibliotecaGenerica.h
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:54
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

void crealista(void *&lista,void*(*lee)(ifstream &),const char *nombArch);
void generaLista(void *&lista);
void insertaEnLista(void *lista,void *dato);
bool esListaVacia(void *lista);
void imprimelista(void *lista,void(*imprime)(ofstream &, void*dato),
                  const char *nombArch);
void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,
                  int(*compara)( void*, void*));
void *quitalista(void *lista);
#endif /* BIBLIOTECAGENERICA_H */

