/* 
 * Archivo:   Vehiculo.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 23:55
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "NPedido.h"

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    class NPedido *ped;
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* pla);
    void GetPlaca(char *cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* VEHICULO_H */

