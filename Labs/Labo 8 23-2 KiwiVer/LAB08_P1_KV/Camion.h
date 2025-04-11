/* 
 * Archivo:   Camion.h
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:13
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"


class Camion: public Vehiculo {
private:
    int ejes;
    int llantas;
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* CAMION_H */

