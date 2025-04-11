/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:40 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "bibliotecasComunes.hpp"
#include "ProductoEntregado.h"
#include "Pedido.h"

class Cliente {
public:
    Cliente();
    ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetDni(int dni);
    int GetDni() const;
    int GetCantidad_productos_entregados() const;
    ProductoEntregado *GetProductos_entregados();
    
    void operator+=(Pedido pedido);
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[50];
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator>>(ifstream &arch,Cliente &cliente);
void operator<<(ofstream &arch,Cliente &cliente);

#endif /* CLIENTE_H */

