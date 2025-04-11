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
#include "Pedido.h"

#define NO_ENCONTRADO -1

class Almacen {
public:
    Almacen();
    ~Almacen();
    
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    int buscarCliente(int dniCli);
    int buscarPredido(char *codProd);
    void mostrar_datos();
    
private:
    Cliente arreglo_clientes[150];
    int cantidad_clientes;
    Producto arreglo_productos[180];
    int cantidad_productos;
};

#endif /* ALMACEN_H */

