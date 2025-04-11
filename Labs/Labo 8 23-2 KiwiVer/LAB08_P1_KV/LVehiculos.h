/* 
 * Archivo:   LVehiculos.h
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:16
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H
#include "NodoLista.h"

class LVehiculos {
private:
    NodoLista *lini;
    NodoLista *lfin;
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
    void leeVehiculos(ifstream &arch);
    void insertar(class NodoLista *&nuevo);
    void imprimirReporte(ofstream &arch);
};

#endif /* LVEHICULOS_H */

