/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Revista.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:11
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"

class Revista:public Libro {
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int ISSN;
    int anho;
    int numero;
};

#endif /* REVISTA_H */

