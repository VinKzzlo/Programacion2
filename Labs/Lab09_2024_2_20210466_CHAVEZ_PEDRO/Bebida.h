/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bebida.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:08
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include <fstream>
using namespace std;
#include "Producto.h"

class Bebida:public Producto {
public:
    Bebida();
    Bebida(const Bebida& orig);
    virtual ~Bebida();
    void SetTamanho(string tamanho);
    string GetTamanho() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    bool contiene(int){};
    int GetTiempoPrep();
private:
    string tamanho;
};

#endif /* BEBIDA_H */

