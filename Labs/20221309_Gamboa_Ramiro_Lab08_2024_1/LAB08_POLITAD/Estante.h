/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:11
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Lista.h"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void leerDatos(ifstream &);
    bool verificaCapacidad(double);
    void agregaLibro(class Nodo*,double);
    void verificaVigencia();
    void muestraEstantes(ofstream &);
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
    void imprimirLinea(ofstream &,char);
};

#endif /* ESTANTE_H */

