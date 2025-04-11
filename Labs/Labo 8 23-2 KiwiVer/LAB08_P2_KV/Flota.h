/* 
 * Archivo:   Flota.h
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:18
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "LVehiculos.h"

class Flota {
private:
    LVehiculos lista;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void cargapedidos();
    void muestracarga();
};

#endif /* FLOTA_H */

