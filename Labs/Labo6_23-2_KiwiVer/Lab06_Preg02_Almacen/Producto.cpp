/* 
 * Archivo:   Producto.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:44
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Producto.h"
#include "Funciones.h"
#include "Pedido.h"

Producto::Producto() {
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos = 0;
    codigo = nullptr;
    descripcion = nullptr;
    stock = 0;
    precio = 0.0;
}


Producto::~Producto() {
    if(codigo!= nullptr) delete []codigo;
    if(descripcion!= nullptr) delete[] descripcion;
}


int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}


int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}


int *Producto::GetClientes_no_servidos() {
    return clientes_no_servidos;
}


int *Producto::GetClientes_servidos() {
    return clientes_servidos;
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

void Producto::SetDescripcion(char* desc) {
    if(descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(desc)+1];
    strcpy(descripcion,desc);
}

char *Producto::GetDescripcion() const {
    char *copia = new char[strlen(descripcion)+1];
    strcpy(copia,descripcion);
    return copia;
}

void Producto::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

char *Producto::GetCodigo() const {
    char *copia = new char[strlen(codigo)+1];
    strcpy(copia,codigo);
    return copia;
}

bool Producto::operator+=(Pedido& ped) {
    int n;
    ped.SetPrecio_producto(precio);
    if(stock>0){
        n = cantidad_clientes_servidos;
        clientes_servidos[n] = ped.GetDni_cliente();
        stock--;
        cantidad_clientes_servidos++;
        return true;
    }else{
        n= cantidad_clientes_no_servidos;
        clientes_no_servidos[n] = ped.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}


bool operator>>(ifstream &arch,class Producto &prod){
    char *codigo, *descripcion;
    double precio;
    int stock;
    
    codigo = leeCadena(arch,8,',');
    if(arch.eof()) return false;
    descripcion = leeCadena(arch,100,',');
    arch>>precio;
    arch.get();
    arch>>stock;
    arch.get(); //Sacamos salto de linea
    
    prod.SetCodigo(codigo);
    prod.SetDescripcion(descripcion);
    prod.SetPrecio(precio);
    prod.SetStock(stock);
    
    return true;
    
}

void operator<<(ofstream &arch, class Producto &prod){
    arch.precision(2);
    arch<<fixed;
    
    arch<<left<<setw(10)<<prod.GetCodigo()<<setw(65)<<prod.GetDescripcion()
        <<right<<setw(10)<<prod.GetPrecio()<<setw(7)<<prod.GetStock()<<endl;
    arch<<"Clientes atendidos: ";
    if(prod.GetCantidad_clientes_servidos()==0){
        arch<<"NO TIENE CLIENTES ATENDIDOS";
    }else{
        int *cliServ = prod.GetClientes_servidos();
        for(int i=0;i<prod.GetCantidad_clientes_servidos();i++)
            arch<<setw(10)<<cliServ[i];
    }
    arch<<endl;
    arch<<"Clientes no atendidos: ";
    if(prod.GetCantidad_clientes_no_servidos()==0){
        arch<<"NO TIENE CLIENTES ATENDIDOS";
    }else{
        int *cliNoServ = prod.GetClientes_no_servidos();
        for(int i=0;i<prod.GetCantidad_clientes_no_servidos();i++)
            arch<<setw(10)<<cliNoServ[i];
    }
    arch<<endl;
}