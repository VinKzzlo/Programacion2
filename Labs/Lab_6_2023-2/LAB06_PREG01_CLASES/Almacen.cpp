/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:56 PM
 */

#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetArreglo_productos(Producto *arreglo_productos) {
    for(int i=0;i<180;i++){
        this->arreglo_productos[i] = arreglo_productos[i];
    }
}

Producto *Almacen::GetArreglo_productos(){
    return arreglo_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::SetArreglo_clientes(Cliente *arreglo_clientes) {
    for(int i=0;i<150;i++){
        this->arreglo_clientes[i] = arreglo_clientes[i];
    } 
}

Cliente *Almacen::GetArreglo_clientes(){
    return arreglo_clientes;
}

