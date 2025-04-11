/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:51 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"


class Flota {
public:
    Flota();
    ~Flota();
    
    void cargaflota();
    void muestracarga();
private:
    LVehiculos lista;
};

#endif /* FLOTA_H */

