/* 
 * Archivo:   Nodo.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 8:49
 */

#ifndef NODO_H
#define NODO_H
#include "Arbol.h"

class Nodo {
private:
    int dato;
    class Nodo *derecha;
    class Nodo *izquierda;
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

