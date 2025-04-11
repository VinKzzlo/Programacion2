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
    class Cliente arreglo_clientes[150];
    int cantidad_clientes;
    class Producto arreglo_productos[180];
    int cantidad_productos;
public:
    Almacen();
    virtual ~Almacen();
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    void mostrar_datos();
    int buscarCliente(int dni);
    int buscarProducto(char *codigo);
};

#endif /* ALMACEN_H */

