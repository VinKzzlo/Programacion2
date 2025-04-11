/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:56 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "bibliotecasComunes.hpp"
#include "Cliente.h"
#include "Producto.h"

class Almacen {
public:
    Almacen();
    ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetArreglo_productos(Producto *arreglo_productos);
    Producto *GetArreglo_productos();
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    void SetArreglo_clientes(Cliente *arreglo_clientes);
    Cliente *GetArreglo_clientes();
private:
    Cliente arreglo_clientes[150];
    int cantidad_clientes;
    Producto arreglo_productos[180];
    int cantidad_productos;
};

#endif /* ALMACEN_H */

