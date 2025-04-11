/* 
 * File:   Enciclopedia.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:25
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia:public Libro {
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &);
    void actualiza();
    void imprime(ofstream &);
private:
    int sku;
    int anho;
    int vigencia;
};

#endif /* ENCICLOPEDIA_H */

