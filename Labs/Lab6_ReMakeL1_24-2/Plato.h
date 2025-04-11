/* 
 * Archivo:   Plato.h
 * Autor:     VinKzzlo
 *
 * Creado el  31 de octubre de 2024, 1:45
 */

#ifndef PLATO_H
#define PLATO_H

class Plato {
private:
    char *codigo;
    char *nombre;
    double precio;
    int totalDePedidos;
    double totalRecaudado;
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();

};

#endif /* PLATO_H */

