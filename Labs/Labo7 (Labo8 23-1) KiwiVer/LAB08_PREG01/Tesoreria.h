/* 
 * Archivo:   Tesoreria.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 20:29
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
private:
    class Presencial lpresencial[50];
    class Semipresencial lsemipresencial[50];
    class Virtual lvirtual[50];
    class Escala lescala[10];
public:
    Tesoreria();
    void cargaescalas(const char *nombArch);
    void cargaalumnos(const char *nombArch);
    void actualiza(int creditos);
    void imprime(const char *nombArch);
};

#endif /* TESORERIA_H */

