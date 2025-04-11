/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: gabri
 *
 * Created on October 26, 2024, 1:16 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetCant(int cant);
    int GetCant() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCodigorepartidor(char *cad);
    void GetCodigorepartidor(char *cad);
    void SetCodigoplato(char *cad);
    void GetCodigoplato(char *cad);
    void SetDistancia(double distancia);
    double GetDistancia() const;
private:
    int dni;
    int cant;
    char *codigoplato;
    char *codigorepartidor;
    double distancia;
};

ifstream &operator>>(ifstream &, Pedido &);

#endif /* PEDIDO_H */

