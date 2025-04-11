/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Rectangulo.cpp
 * Author: asant
 * 
 * Created on 2 de octubre de 2024, 8:40
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Rectangulo.h"

void Rectangulo::asignarBase(double b){
    base = b;
}

void Rectangulo::asignarAltura(double h){
    altura = h;
}

double Rectangulo::entregaBase(){
    return base;
}

double Rectangulo::entregaAltura(){
    return altura;
}

double Rectangulo::area(){
    return base*altura;
}

double Rectangulo::perimetro(){
    return 2*(base+altura);
}

void Rectangulo::imprimirDatos(){
    cout.precision(2);
    cout<<fixed;
    cout<<"Base = "<<setw(10)<<base<<endl;
    cout<<"Altura = "<<setw(10)<<altura<<endl;
    
} 
void Rectangulo::imprimirResultados(){
    imprimirDatos();
    cout<<"Area = "<<setw(10)<<area()<<endl;
    cout<<"Perimetro = "<<setw(10)<<perimetro()<<endl;
}