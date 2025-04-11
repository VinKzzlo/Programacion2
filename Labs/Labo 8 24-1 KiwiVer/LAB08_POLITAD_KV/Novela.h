/* 
 * Archivo:   Novela.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:16
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"


class Novela: public Libro {
private:
    char* autor;
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(char* autor);
    void GetAutor(char *cad) const;
    void lee(ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch);
};

#endif /* NOVELA_H */

