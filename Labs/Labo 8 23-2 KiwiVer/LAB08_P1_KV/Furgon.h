/* 
 * Archivo:   Furgon.h
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:14
 */

#ifndef FURGON_H
#define FURGON_H
#include "Vehiculo.h"

class Furgon:public Vehiculo {
private:
    int filas;
    int puertas;
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* FURGON_H */

