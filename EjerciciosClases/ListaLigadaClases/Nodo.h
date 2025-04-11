/* 
 * Archivo:   Nodo.h
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 8:29
 */

#ifndef NODO_H
#define NODO_H
#include "Lista.h"

class Nodo {
private:
    int dato;
    class Nodo *sig;
public:
    Nodo();
    friend class Lista;
};

#endif /* NODO_H */

