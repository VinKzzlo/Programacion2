/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:46 PM
 */

#include "Producto.h"

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

Producto::Producto() {
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
    codigo=nullptr;
    descripcion=nullptr;
    precio=0;
    stock=0;
}

Producto::~Producto() {
    if(codigo)delete[] codigo;
    if(descripcion)delete[] descripcion;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(char* descripcion) {
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

char* Producto::GetDescripcion() const {
    char *copia=new char[strlen(descripcion)+1];
    strcpy(copia,descripcion);
    return copia;
}

void Producto::SetCodigo(char* codigo) {
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

char* Producto::GetCodigo() const {
    char *copia=new char[strlen(codigo)+1];
    strcpy(copia,codigo);
    return copia;
}

bool operator>>(ifstream &arch,Producto &producto){
    int stock;
    char *codigo,*descripcion,c;
    double precio;
    
    codigo=leeCadena(arch,',');
    if(arch.eof())return false;
    descripcion=leeCadena(arch,',');
    arch>>precio>>c>>stock;
    arch.get();
    
    producto.SetCodigo(codigo);
    producto.SetDescripcion(descripcion);
    producto.SetPrecio(precio);
    producto.SetStock(stock);
    
    return true;
}

bool Producto::operator+=(Pedido &pedido){
    int n;
    pedido.SetPrecio_producto(precio);
    if(stock>0){
        n=cantidad_clientes_servidos;
        clientes_servidos[n]=pedido.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    }else{
        n=cantidad_clientes_no_servidos;
        clientes_no_servidos[n]=pedido.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }    
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

int *Producto::GetClientes_no_servidos(){
    return clientes_no_servidos;
}

int *Producto::GetClientes_servidos(){
    return clientes_servidos;
}

void operator<<(ofstream &arch,Producto producto){
    arch<<left<<setw(8)<<producto.GetCodigo()<<setw(50)<<producto.GetDescripcion()<<
            right<<setw(10)<<producto.GetPrecio()<<setw(5)<<producto.GetStock()<<endl;
    
    arch<<left<<setw(24)<<"Clientes altendidos:";
    if(producto.GetCantidad_clientes_servidos()==0){
        arch<<"NO SE ATENDIERON PEDIDOS";
    }else{
        int *cli_atend=producto.GetClientes_servidos();
        for(int i=0;i<producto.GetCantidad_clientes_servidos();i++)
            arch<<left<<setw(10)<<cli_atend[i];
    }
    arch<<endl;
    arch<<left<<setw(24)<<"Clientes no altendidos: ";
    if(producto.GetCantidad_clientes_no_servidos()==0){
        arch<<"NO HAY CLIENTES SIN ATENDER";
    }else{
        int *cli_no_atend=producto.GetClientes_no_servidos();
        for(int i=0;i<producto.GetCantidad_clientes_no_servidos();i++)
            arch<<left<<setw(10)<<cli_no_atend[i];
    }
}