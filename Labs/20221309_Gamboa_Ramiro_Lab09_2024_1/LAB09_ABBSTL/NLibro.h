/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:12
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"

class NLibro {
public:
    NLibro();
    NLibro(const NLibro& orig);
    virtual ~NLibro();
    void asignaMemoria(char);
    void cargaLibro(ifstream &);
    double GetPeso() const;
    void imprimeLibro(ofstream &);
private:
    Libro *plibro;
};

#endif /* NLIBRO_H */

