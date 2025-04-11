/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Dato.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:14
 */

#ifndef DATO_H
#define DATO_H

#include <fstream>
using namespace std;
#include "Producto.h"

class Dato {
public:
    Dato();
    Dato(const Dato& orig);
    virtual ~Dato();
    string generarMemoria(string, string);
    void lee(ifstream &);
    void imprime(ofstream &);
    void operator=(const Dato &);
    double ObtenPrecio();
    bool contiene(int);
    int tiempoPrep();
private:
    Producto *pedidos;
};

#endif /* DATO_H */

