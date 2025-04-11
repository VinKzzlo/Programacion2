/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Repartidor.h
 * Author: gabri
 *
 * Created on October 26, 2024, 12:09 PM
 */

#ifndef REPARTIDOR_H
#define REPARTIDOR_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"


class Repartidor {
public:
    Repartidor();
    Repartidor(const Repartidor& orig);
    virtual ~Repartidor();
    void SetCodigo(char *);
    void GetCodigo(char *);
    void SetNombre(char *);
    void GetNombre(char *);
    void SetTipo(char *);
    void GetTipo(char *);
    void operator+=(Pedido &);
    void imprimecliente(ofstream &);
    void SetNumero(int numero);
    int GetNumero() const;
    void actualizarDatos(Cliente *, Plato *);
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetTotal(double total);
    double GetTotal() const;
    void operator!();
private:
    int numero; //ESTE ATRIBUTO CREO QUE YA NO LO USO, SOLO QUE TENDRIA QUE BORRARLO DE MUCHOS SITIOS Y MUCHA VAINA
    char *codigo;
    char *nombre;
    char *tipo;
    double total;
    int cantidad;
    Cliente lcliente[20];
    int buscarcliente(int);
};

ifstream &operator>>(ifstream &, Repartidor &);
ofstream &operator>>(ofstream &, Repartidor &);

#endif /* REPARTIDOR_H */

