/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaDuplas1.h
 * Author: ISA
 *
 * Created on 29 de abril de 2024, 08:55 PM
 */

#ifndef BIBLIOTECADUPLAS1_H
#define BIBLIOTECADUPLAS1_H
#include <fstream>
using namespace std;

void* almacenarDupla1(const char* codigo,const char* nombre);
void* copiaDupla1(void* dupla1);
void eliminarDupla1(void *dupla);

bool dupla1CodigosIguales(void* duplaI,void* duplaK);
int comparardupla1Codigos(void* duplaI,void* duplaK);
bool dupla1NombresIguales(void* duplaI,void* duplaK);
int comparardupla1Nombres(void* duplaI,void* duplaK);

void mostrarDupla1(void *dupla);
void incrementarCantidadDuplas1(void *&cantidad,void *dupla);
void decrementarCantidadDuplas1(void *&cantidad,void *dupla);

void UnirCantidadDuplas1(void *cantidadP,void *&cantidadS);
void eliminarCantidadDuplas1(void *&cantidad);
void mostrarInformacionCantidadDuplas1(void *cantidad);
#endif /* BIBLIOTECADUPLAS1_H */
