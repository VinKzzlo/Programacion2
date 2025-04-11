/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:01
 */

#include <iomanip>
#include "Producto.h"

Producto::Producto() {
    precio = 0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Producto::GetNombre() const {
    return nombre;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::lee(ifstream &arch){
    getline(arch, nombre, ',');
    arch>>precio;
    arch.get();
}

void Producto::imprime(ofstream &arch){
    arch<<"Nombre: "<<setw(50)<<left<<nombre<<right<<endl;
    arch<<"Precio: "<<setw(5)<<setprecision(2)<<fixed<<precio<<endl;
}

double Producto::ObtenPrecio(){
    return precio;
}

