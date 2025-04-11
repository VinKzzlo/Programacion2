/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   Sobrecargas.h
 * Autor: VinKzzlo
 *
 * Creado el on 21 de agosto de 2024, 9:09
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <ostream>


void operator *=(struct Persona &, double);
//void operator <<(ostream &,const struct Persona &);
ostream & operator <<(ostream &,const struct Persona &);
#endif /* SOBRECARGAS_H */

