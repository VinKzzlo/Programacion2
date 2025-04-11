/* 
 * Archivo:   Flota.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 11:04 PM
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "NVehiculo.h"
#include <vector>

class Flota {
private:
    vector<class NVehiculo> vflota;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void cargapedidos();
    void muestraflota();
};

#endif /* FLOTA_H */

