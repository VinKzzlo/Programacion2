/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:46 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "bibliotecasComunes.hpp"
#include "Pedido.h"

class Producto {
public:
    Producto();
    ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    char* GetDescripcion() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
    
    bool operator+=(Pedido &pedido);
    int GetCantidad_clientes_no_servidos() const;
    int GetCantidad_clientes_servidos() const;
    int *GetClientes_no_servidos();
    int *GetClientes_servidos();
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};

bool operator>>(ifstream &arch,Producto &producto);
void operator<<(ofstream &arch,Producto producto);

#endif /* PRODUCTO_H */

