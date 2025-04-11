/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:48 PM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Vehiculo.h"

class NodoLista {
public:
    NodoLista();
    NodoLista(char tipo);
    ~NodoLista();
    friend class LVehiculos;
    
    void leeRegistroVehiculo(ifstream &arch);
    void imprimirRegistro(ofstream &arch);
    
    void insertarPedidoEnPila(NPedido &nodoAux);
private:
    Vehiculo *unidad;
    NodoLista *sig;
};

#endif /* NODOLISTA_H */

