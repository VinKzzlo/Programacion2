/* 
 * Archivo:   Lista.h
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 8:30
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Persona.h"

class Lista {
private:
    class Nodo *lista;
    void imprimeR(ofstream &arch, class Nodo *lista);
public:
    Lista();
    virtual ~Lista();
    void crear(const char *nombArch);
    void insertar(const class Persona &per);
    void imprimir(const char *nombArch);
    void elimina();
    void imprimeRecursivo(const char *nombArch);
};

#endif /* LISTA_H */

