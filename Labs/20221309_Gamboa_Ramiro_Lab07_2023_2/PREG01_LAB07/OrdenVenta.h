/* 
 * File:   OrdenVenta.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:25 PM
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H

#include "Pedido.h"

class OrdenVenta {
public:
    OrdenVenta();
    OrdenVenta(const OrdenVenta& orig);
    virtual ~OrdenVenta();
    void leepedidos(ifstream &);
    void imprimeordenes(ofstream &);
private:
    Pedido *ptr_orden;
};

#endif /* ORDENVENTA_H */

