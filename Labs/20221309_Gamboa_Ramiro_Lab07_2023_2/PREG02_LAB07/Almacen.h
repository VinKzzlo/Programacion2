/* 
 * File:   Almacen.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:26 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "OrdenVenta.h"

class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_ordenes(int cantidad_ordenes);
    int GetCantidad_ordenes() const;
    void cargar_pedidos();
    void actualizar_pedidos();
    void imprimir_ordenes_venta();
private:
    OrdenVenta ordenes[600];
    int cantidad_ordenes;
    void imprimirLinea(ofstream &,char);
};

#endif /* ALMACEN_H */

