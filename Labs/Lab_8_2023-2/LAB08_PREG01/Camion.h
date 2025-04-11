/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:44 PM
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"

class Camion : public Vehiculo{
public:
    Camion();
    ~Camion();
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int ejes;
    int llantas;
};

#endif /* CAMION_H */

