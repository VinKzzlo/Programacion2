/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: gabri
 *
 * Created on October 26, 2024, 12:09 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Plato.h"
#include "Pedido.h"


class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(char *);
    void GetNombre(char *);
    void SetDistrito(char *);
    void GetDistrito(char *);
    void operator+=(Pedido &);
    void operator&(Cliente &);
    void operator&(Plato &);
    int buscarcliente(Cliente *);
    int buscarplato(Plato *);
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetDistancia(double distancia);
    double GetDistancia() const;
    void imprimirplatos(ofstream &);
    void SetTotal(double total);
    double GetTotal() const;
    void operator!();
private:
    int dni;
    double total;
    double distancia;
    int cantidad;
    char *nombre;
    char *distrito;
    int telefono;
    Plato lplato[20];
    
};

ifstream &operator>>(ifstream &, Cliente &);

#endif /* CLIENTE_H */

