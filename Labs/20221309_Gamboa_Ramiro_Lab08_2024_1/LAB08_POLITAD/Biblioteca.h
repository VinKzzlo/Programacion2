/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:13
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void baja();
    void muestra();
private:
    Estante AEstante[10];
    void agregar(class Nodo*);
    void imprimirLinea(ofstream &,char);
};

#endif /* BIBLIOTECA_H */

