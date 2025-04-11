/* 
 * Archivo:   Cliente.h
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:20
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Funciones.h"
#include "ProductoEntregado.h"
#include "Pedido.h"
 
class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[10];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nombre);
    char *GetNombre() const;
    void SetDni(int dni);
    int GetDni() const;
    int GetCantidad_productos_entregados() const;
    ProductoEntregado *GetProductos_entregados();

    void operator +=(class Pedido &ped);
};

bool operator>>(ifstream &arch,class Cliente &cli);
void operator<<(ofstream &arch,class Cliente &cli);

#endif /* CLIENTE_H */

