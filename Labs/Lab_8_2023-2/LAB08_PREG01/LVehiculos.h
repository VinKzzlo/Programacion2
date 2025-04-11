/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:50 PM
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include "NodoLista.h"


class LVehiculos {
public:
    LVehiculos();
    ~LVehiculos();
    
    void leerArchivoVehiculos(ifstream &arch);
    void insertarAlFinal(NodoLista *&nuevoNodo);
    void imprimirReporte(ofstream &arch);
private:
    NodoLista *lini;
    NodoLista *lfin;
};

#endif /* LVEHICULOS_H */

