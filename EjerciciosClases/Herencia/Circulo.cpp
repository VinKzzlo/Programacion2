/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circulo.cpp
 * Author: asant
 * 
 * Created on 22 de octubre de 2024, 9:02
 */


#include <cstring>
#include "Circulo.h"

Circulo::Circulo() {
}

void Circulo::SetRadio(double radio) {
    this->radio = radio;
}

double Circulo::GetRadio() const {
    return radio;
}

void Circulo::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

char* Circulo::GetNombre() const {
    return nombre;
}

Circulo::Circulo(const Circulo& orig) {
}

Circulo::~Circulo() {
}

