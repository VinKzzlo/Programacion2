/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:15
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Arbol.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void muestra();
    void prueba(double);
private:
    Arbol AEstante;
};

#endif /* BIBLIOTECA_H */

