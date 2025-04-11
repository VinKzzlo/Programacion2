/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:09
 */

#ifndef NODO_H
#define NODO_H

#include "Nodo.h"
#include "Libro.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Biblioteca;
    friend class Lista;
    void asignaMemoria(char);
    void SetNull();
private:
    Libro *plibro;
    Nodo *sig;
};

#endif /* NODO_H */

