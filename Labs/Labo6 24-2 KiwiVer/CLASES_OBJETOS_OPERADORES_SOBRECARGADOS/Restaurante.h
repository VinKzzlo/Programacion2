/* 
 * Archivo:   Restaurante.h
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 21:28
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"

class Restaurante {
private:
    class Cliente *clientes;
    int cantidadDeClientes;
    class Plato *platos;
    int cantidadDePlatos;
public:
    Restaurante();
    virtual ~Restaurante();
    void operator <(const char *nombArch);
    void operator <=(const char *nombArch);
    void operator <<=(const char *nombArch);
    void operator >>(const char *nombArch); 
    int buscaCliente(int dniCli);
    int buscaPlato(char *codPla);
};

#endif /* RESTAURANTE_H */

