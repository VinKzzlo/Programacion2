/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 09:30 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include "NPedido.h"
#include "bibliotecas.h"

class Vehiculo {
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetPed(NPedido* ped);
    NPedido* GetPed() const;
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* placa);
    char* GetPlaca() const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    
    void push(NPedido &nodoAux);
    bool pilavacia();
    void imprimePila(ofstream &arch);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
};

#endif /* VEHICULO_H */

