/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlatoFondo.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:09
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include <fstream>
using namespace std;
#include "Producto.h"

class PlatoFondo:public Producto {
public:
    PlatoFondo();
    PlatoFondo(const PlatoFondo& orig);
    virtual ~PlatoFondo();
    void lee(ifstream &);
    void imprime(ofstream &);
    bool contiene(int);
    int GetTiempoPrep();
private:
    int proteina[4];
};

#endif /* PLATOFONDO_H */

