/* 
 * Archivo:   NVehiculo.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:59 PM
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include "Vehiculo.h"

class NVehiculo {
private:
    Vehiculo *unidad;
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    void leeTipoVehiculo(ifstream &arch);
    void imprimeVehiculo(ofstream &arch);
    bool comparaCliente(int codigo);
    void insertaPedido(class NPedido &nped);
};

#endif /* NVEHICULO_H */

