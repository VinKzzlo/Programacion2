/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * Archivo:   Rectangulo.cpp
 * Autor:     VinKzzlo
 * 
 * Created on 2 de octubre de 2024, 9:26
 */
#include <iostream>
#include <iomanip>
#include "Rectangulo.h"


void Rectangulo::SetAltura(double altura) {
    this->altura = altura;
}

double Rectangulo::GetAltura() const {
    return altura;
}

void Rectangulo::SetBase(double base) {
    this->base = base;
}

double Rectangulo::GetBase() const {
    return base;
}

