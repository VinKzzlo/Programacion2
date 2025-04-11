/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:52 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "bibliotecasComunes.hpp"

class Pedido {
public:
    Pedido();
    ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
};

bool operator>>(ifstream &arch,Pedido &pedido);

#endif /* PEDIDO_H */

