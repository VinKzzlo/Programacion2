/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:10
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void SetPeso(double peso);
    double GetPeso() const;
    void insertar(class Nodo*);
    void vigenciaNodos();
    void imprimeLibros(ofstream &);
private:
    double peso;
    Nodo *ini;
};

#endif /* LISTA_H */

