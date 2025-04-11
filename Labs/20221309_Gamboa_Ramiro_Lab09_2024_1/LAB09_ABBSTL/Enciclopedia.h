/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:08
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia:public Libro {
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int sku;
    int anho;
};

#endif /* ENCICLOPEDIA_H */

