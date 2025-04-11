/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: gabri
 * 
 * Created on October 26, 2024, 1:16 PM
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigoplato=nullptr;
    codigorepartidor=nullptr;
    dni=0;
    cant=0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetCant(int cant) {
    this->cant = cant;
}

int Pedido::GetCant() const {
    return cant;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCodigorepartidor(char *cad){
    if(codigorepartidor!=nullptr) delete codigorepartidor;
    codigorepartidor=new char[strlen(cad)+1];
    strcpy(codigorepartidor, cad);
}

void Pedido::GetCodigorepartidor(char *cad){
    if(codigorepartidor!=nullptr) 
        strcpy(cad, codigorepartidor);
}

void Pedido::SetCodigoplato(char *cad){
    if(codigoplato!=nullptr) delete codigoplato;
    codigoplato=new char[strlen(cad)+1];
    strcpy(codigoplato, cad);
}

void Pedido::GetCodigoplato(char *cad){
    if(codigoplato!=nullptr) 
        strcpy(cad, codigoplato);
}

void Pedido::SetDistancia(double distancia) {
    this->distancia = distancia;
}

double Pedido::GetDistancia() const {
    return distancia;
}

ifstream &operator>>(ifstream &arch, Pedido &p){
    int dni, cant;
    char a[10], c;
    double distancia;
    
    arch>>dni;
    if(!arch.eof()){
        p.SetDni(dni);
        arch>>a;
        //arch.getline(a, 10, ',');
        p.SetCodigoplato(a);
        
        arch>>cant;
        p.SetCant(cant);
        
        arch>>a;
        //arch.getline(a, 10, '\n');
        p.SetCodigorepartidor(a);
        arch>>distancia;
        
        p.SetDistancia(distancia);
    }
    return arch;
}
