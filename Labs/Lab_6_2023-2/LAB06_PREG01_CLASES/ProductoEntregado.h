/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:31 PM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

#include "bibliotecasComunes.hpp"

class ProductoEntregado {
public:
    ProductoEntregado();
    ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

