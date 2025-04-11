/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:27 PM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include "bibliotecas.h"

class NPedido {
public:
    NPedido();
    NPedido(const NPedido &_orig);
    ~NPedido();
    void SetPeso(double peso);
    void SetCantidad(int cantidad);
    void SetCodigo(char* codigo);
    double GetPeso() const;
    friend class Vehiculo;
    
    void imprimeRegistro(ofstream &arch);
private:
    char *codigo;
    int cantidad;
    double peso;
    NPedido *sig;
};

#endif /* NPEDIDO_H */

