/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:09
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela:public Libro {
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(char *cad);
    void GetAutor(char *cad) const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    char *autor;
};

#endif /* NOVELA_H */

