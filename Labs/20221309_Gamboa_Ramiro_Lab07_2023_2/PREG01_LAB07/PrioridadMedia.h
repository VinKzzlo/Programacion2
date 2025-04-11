/* 
 * File:   PrioridadMedia.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:22 PM
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H

#include "Pedido.h"

class PrioridadMedia:public Pedido {
public:
    PrioridadMedia();
    PrioridadMedia(const PrioridadMedia& orig);
    virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(char *cad);
    void GetDescripcion(char *cad) const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    char *descripcion;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADMEDIA_H */

