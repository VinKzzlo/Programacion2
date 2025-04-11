/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Restaurante.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:15
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <map>
#include <vector>
using namespace std;
#include "Comanda.h"
#include "Dato.h"

class Restaurante {
public:
    Restaurante();
    Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void carga();
    void setLineaBusqueda(string lineaBusqueda);
    string getLineaBusqueda() const;
    void cargaPlato(string);
    void muestra();
    void actualiza(int);
private:
    map<Comanda, vector<Dato>> mcomandas;
    string lineaBusqueda;
};

#endif /* RESTAURANTE_H */

