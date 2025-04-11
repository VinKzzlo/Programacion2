/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Rectangulo.h
 * Author: asant
 *
 * Created on 2 de octubre de 2024, 8:40
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
private:
    double base;
    double altura;
public:
    void asignarBase(double b);
    void asignarAltura(double h);
    double entregaBase();
    double entregaAltura();
    void imprimirDatos();
    void imprimirResultados();
    double area();
    double perimetro();
};

#endif /* RECTANGULO_H */

