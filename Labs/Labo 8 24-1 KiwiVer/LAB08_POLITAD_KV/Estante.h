/* 
 * Archivo:   Estante.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:40
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Lista.h"
class Estante {
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
    void imprimeLinea(ofstream &arch,char c);
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    bool verificaCapacidad(double pesoNuevo);
    void agregaLibro(class Nodo *nuevo);
    void actualizaVigencia();
    void muestraEstantes(ofstream &arch);
};

#endif /* ESTANTE_H */

