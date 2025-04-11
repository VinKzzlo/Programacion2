/* 
 * Archivo:   Biblioteca.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:41
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"

class Biblioteca {
private:
    class Estante AEstantes[10];
    void agregar(class Nodo *);
    void imprimeLinea(ofstream &arch,char c);
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga(const char *nombArch);
    void llena(const char *nombArch);
    void baja();
    void muestra(const char *nombArch);
    
};

#endif /* BIBLIOTECA_H */

