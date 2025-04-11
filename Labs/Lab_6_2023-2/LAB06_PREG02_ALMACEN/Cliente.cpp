/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:40 PM
 */

#include "Cliente.h"

Cliente::Cliente() {
    cantidad_productos_entregados=0;
    dni=0;
    monto_total=0;
    nombre=nullptr;
    telefono=0;
}

Cliente::~Cliente() {
    if(nombre)delete[] nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nombre) {
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

char* Cliente::GetNombre() const {
    char *copiaNom=new char[strlen(nombre)+1];
    strcpy(copiaNom,nombre);
    return copiaNom;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator>>(ifstream &arch,Cliente &cliente){
    int dni,telefono;
    char *nombre;
    
    arch>>dni;
    if(arch.eof())return false;
    arch.get();
    nombre=leeCadena(arch,',');
    arch>>telefono;
    
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetTelefono(telefono);
    
    return true;
}

void Cliente::operator+=(Pedido pedido){
    ProductoEntregado prod;
    prod.SetCodigo(pedido.GetCodigo());
    prod.SetPrecio(pedido.GetPrecio_producto());
    
    int n=cantidad_productos_entregados;
    productos_entregados[n]=prod;
    cantidad_productos_entregados++;
    monto_total+=pedido.GetPrecio_producto();
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

ProductoEntregado *Cliente::GetProductos_entregados(){
    return productos_entregados;
}

void operator<<(ofstream &arch,Cliente &cliente){
    arch<<left<<setw(10)<<cliente.GetDni()<<setw(60)<<cliente.GetNombre()<<right<<
            setw(10)<<cliente.GetTelefono()<<setw(10)<<cliente.GetMonto_total();
    arch<<' ';
    arch<<left<<setw(22)<<"Productos entregados: ";
    if(cliente.GetCantidad_productos_entregados()==0){
        arch<<"NO SE LE ENTREGARON PRODUCTOS";
    }else{
        ProductoEntregado *prod=cliente.GetProductos_entregados();
        for(int i=0;i<cliente.GetCantidad_productos_entregados();i++)
            arch<<left<<setw(10)<<prod[i].GetCodigo();
    }
}