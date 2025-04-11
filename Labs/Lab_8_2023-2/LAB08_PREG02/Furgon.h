/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:47 PM
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"

class Furgon : public Vehiculo{
public:
    Furgon();
    ~Furgon();
    
    void lee(ifstream &arch);
    void imprime(ofstream& arch);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_H */

