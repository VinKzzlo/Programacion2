/* 
 * Archivo:   Nodo.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:26
 */

#ifndef NODO_H
#define NODO_H
#include "Libro.h"

class Nodo {
private:
    class Libro *plibro;
    class Nodo *sig;
public:
    Nodo();
    virtual ~Nodo();
    friend class Lista;
    void asignaMemoria(char tipo);
    friend class Biblioteca;
};

#endif /* NODO_H */

