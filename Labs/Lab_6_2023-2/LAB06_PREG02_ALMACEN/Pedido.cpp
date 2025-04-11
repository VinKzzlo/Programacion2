/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:52 PM
 */

#include "Pedido.h"

/*
 void Cliente::SetNombre(char* nombre) {
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

char* Cliente::GetNombre() const {
    char *copiaNom=new char[strlen(nombre)+1];
    strcpy(copiaNom,nombre);
    return copiaNom;
}
*/

Pedido::Pedido() {
    codigo=nullptr;
    dni_cliente=0;
    precio_producto=0;
}

Pedido::~Pedido() {
    if(codigo)delete[] codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* codigo) {
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

char* Pedido::GetCodigo() const {
    char *copia=new char[strlen(codigo)+1];
    strcpy(copia,codigo);
    return copia;
}

bool operator>>(ifstream &arch,Pedido &pedido){
    int dni;
    char *codigo;
    
    codigo=leeCadena(arch,',');
    if(arch.eof())return false;
    arch>>dni;
    arch.get();
    
    pedido.SetCodigo(codigo);
    pedido.SetDni_cliente(dni);
    
    return true;
}