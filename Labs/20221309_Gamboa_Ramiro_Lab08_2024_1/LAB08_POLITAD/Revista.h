/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Revista.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 10:08
 */

#ifndef REVISTA_H
#define REVISTA_H

#include <fstream>
using namespace std;
#include "Libro.h"

class Revista:public Libro {
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &);
    void actualiza();
    void imprime(ofstream &);
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

