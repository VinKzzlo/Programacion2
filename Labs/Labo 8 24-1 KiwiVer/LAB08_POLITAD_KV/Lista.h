/* 
 * Archivo:   Lista.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:33
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista {
private:
    double peso;
    class Nodo *ini;
public:
    Lista();
    virtual ~Lista();
    void SetPeso(double peso);
    double GetPeso() const;
    void insertar(class Nodo *nuevo);
    void cambiaVigencia();
    void imprimeLibros(ofstream &);
};

#endif /* LISTA_H */

