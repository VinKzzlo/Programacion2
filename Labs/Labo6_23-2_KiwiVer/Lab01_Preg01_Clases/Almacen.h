/* 
 * Archivo:   Almacen.h
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:47
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Cliente.h"
#include "Producto.h"
class Almacen {
private:
    class Cliente arreglo_clientes[140];
    int cantidad_clientes;
    class Producto arreglo_productos;
    int cantidad_productos;
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();

};

#endif /* ALMACEN_H */

