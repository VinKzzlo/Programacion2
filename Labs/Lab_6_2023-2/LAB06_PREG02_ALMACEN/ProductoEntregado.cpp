/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:31 PM
 */

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo=nullptr;
    precio=0;
}

ProductoEntregado::~ProductoEntregado() {
    if(codigo)delete[] codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* codigo) {
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

char* ProductoEntregado::GetCodigo() const {
    char *copiaCod=new char[strlen(codigo)+1];
    strcpy(copiaCod,codigo);
    return copiaCod;
}

