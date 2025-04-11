/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Comanda.h
 * Author: gabri
 *
 * Created on 28 de noviembre de 2024, 09:10
 */

#ifndef COMANDA_H
#define COMANDA_H

#include <fstream>
#include <string>
using namespace std;

class Comanda {
public:
    Comanda();
    Comanda(const Comanda& orig);
    virtual ~Comanda();
    void SetFecha_servicio(int fecha_servicio);
    int GetFecha_servicio() const;
    void SetFecha_atencion(int fecha_atencion);
    int GetFecha_atencion() const;
    void SetId(string id);
    string GetId() const;
    bool operator<(const Comanda &)const;
    void imprime(ofstream &)const;
    void lee(ifstream &);
    void SetObservacion(string observacion);
    string GetObservacion() const;
    void SetTotal(double total);
    double GetTotal() const;
    void VerificarTardanza();
    void SetTiempo_preparacion(int tiempo_preparacion);
    int GetTiempo_preparacion() const;
private:
    string id;
    int fecha_atencion;
    int fecha_servicio;
    string observacion;
    double total;
    int tiempo_preparacion;
};

ifstream &operator>>(ifstream &, Comanda &);

#endif /* COMANDA_H */

