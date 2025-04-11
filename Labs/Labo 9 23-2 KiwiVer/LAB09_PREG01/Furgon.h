/* 
 * Archivo:   Furgon.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:58 PM
 */

#ifndef FURGON_H
#define FURGON_H
#include <list>
#include "Vehiculo.h"
#include "NPedido.h"

class Furgon: public Vehiculo {
private:
    int filas;
    int puertas;
    list<class NPedido> pdeposito;
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

