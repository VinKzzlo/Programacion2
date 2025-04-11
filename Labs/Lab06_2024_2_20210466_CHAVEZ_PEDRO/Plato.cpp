/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Plato.cpp
 * Author: gabri
 * 
 * Created on October 26, 2024, 12:09 PM
 */
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Plato.h"

Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    tipo=nullptr;
    precio=0;
    cantidad=0;
}

Plato::Plato(const Plato& orig) {
}

Plato::~Plato() {
}

void Plato::SetPrecio(double precio) {
    this->precio = precio;
}

double Plato::GetPrecio() const {
    return precio;
}

void Plato::SetCodigo(char *cad){
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Plato::GetCodigo(char *cad){
    if(codigo!=nullptr) 
        strcpy(cad, codigo);
}

void Plato::SetNombre(char *cad){
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Plato::GetNombre(char *cad){
    if(nombre!=nullptr) 
        strcpy(cad, nombre);
}

void Plato::SetTipo(char *cad){
    if(tipo!=nullptr) delete tipo;
    tipo=new char[strlen(cad)+1];
    strcpy(tipo, cad);
}

void Plato::GetTipo(char *cad){
    if(tipo!=nullptr) 
        strcpy(cad, tipo);
}

void Plato::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Plato::GetCantidad() const {
    return cantidad;
}

ifstream &operator>>(ifstream &arch, Plato &p){
    char a[100], c;
    double precio;
    arch.getline(a, 100, ',');
    if(!arch.eof()){
        p.SetCodigo(a);
        arch.getline(a, 100, ',');
        p.SetNombre(a);
        arch>>precio>>c;
        p.SetPrecio(precio);
        arch.getline(a, 100, '\n');
        p.SetTipo(a);
    }
    return arch;
}