/* 
 * Archivo:   NodoLista.h
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:14
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Vehiculo.h"

class NodoLista {
private:
    Vehiculo *unidad;
    NodoLista *sig;
public:
    NodoLista();
    NodoLista(char tipo);
    virtual ~NodoLista();
    friend class LVehiculos;
    void leeRegistroVehiculo(ifstream &arch);
    void imprimeRegistro(ofstream &arch);
};

#endif /* NODOLISTA_H */

