/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:01
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <fstream>
using namespace std;

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
    double ObtenPrecio();
    virtual bool contiene(int)=0;
    virtual int GetTiempoPrep()=0;
private:
    double precio;
    string nombre;
};

#endif /* PRODUCTO_H */

