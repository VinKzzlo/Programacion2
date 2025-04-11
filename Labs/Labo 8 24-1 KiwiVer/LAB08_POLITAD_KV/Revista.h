/* 
 * Archivo:   Revista.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:17
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"


class Revista:public Libro {
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
public:
    Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &arch);
    void actualiza();
};

#endif /* REVISTA_H */

