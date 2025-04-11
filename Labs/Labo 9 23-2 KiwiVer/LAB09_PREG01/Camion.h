/* 
 * Archivo:   Camion.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:53 PM
 */

#ifndef CAMION_H
#define CAMION_H
#include <map>
#include "Vehiculo.h"
#include "NPedido.h"

class Camion: public Vehiculo {
private:
    int ejes;
    int llantas;
    map<int, class NPedido> mdeposito;
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

