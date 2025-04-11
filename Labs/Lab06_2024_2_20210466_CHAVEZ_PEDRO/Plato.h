/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Plato.h
 * Author: gabri
 *
 * Created on October 26, 2024, 12:09 PM
 */

#ifndef PLATO_H
#define PLATO_H

class Plato {
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char *);
    void GetCodigo(char *);
    void SetNombre(char *);
    void GetNombre(char *);
    void SetTipo(char *);
    void GetTipo(char *);
    void SetCantidad(int cantidad);
    int GetCantidad() const;
private:
    char *codigo;
    char *nombre;
    double precio;
    char *tipo;
    int cantidad;
};

ifstream &operator>>(ifstream &, Plato &);

#endif /* PLATO_H */

