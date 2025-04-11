/* 
 * Archivo:   Enciclopedia.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:12
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"


class Enciclopedia: public Libro {
private:
    int sku;
    int anho;
    int vigencia;
public:
    Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch);
};

#endif /* ENCICLOPEDIA_H */

