/* 
 * File:   PrioridadBaja.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:24 PM
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H

#include "Pedido.h"

class PrioridadBaja:public Pedido {
public:
    PrioridadBaja();
    PrioridadBaja(const PrioridadBaja& orig);
    virtual ~PrioridadBaja();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDias_espera(int dias_espera);
    int GetDias_espera() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int dias_espera;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADBAJA_H */

