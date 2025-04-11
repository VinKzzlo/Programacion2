/* 
 * File:   PrioridadAlta.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:21 PM
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H

#include "Pedido.h"

class PrioridadAlta:public Pedido {
public:
    PrioridadAlta();
    PrioridadAlta(const PrioridadAlta& orig);
    virtual ~PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    double recargo;
    double total;
};

#endif /* PRIORIDADALTA_H */

