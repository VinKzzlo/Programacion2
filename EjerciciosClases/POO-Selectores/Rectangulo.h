/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Rectangulo.h
 * Author: asant
 *
 * Created on 2 de octubre de 2024, 9:26
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
private:
    double base;
    double altura;
public:
    void SetAltura(double altura);
    double GetAltura() const;
    void SetBase(double base);
    double GetBase() const;

};

#endif /* RECTANGULO_H */

