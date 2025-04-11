/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaEnteros.h
 * Author: ISA
 *
 * Created on 27 de abril de 2024, 05:22 PM
 */

#ifndef BIBLIOTECAENTEROS_H
#define BIBLIOTECAENTEROS_H
#include <fstream>
using namespace std;
int* almacenaEntero(int entero);
void* copiaEntero(void* entero);
void eliminarEntero(void *entero);
void mostrarEntero(void *entero);
void ImprimirEntero(ofstream &arch,int pos,void *entero);

bool enterosIguales(void* EnteroI,void* EnteroK);
int compararEnteros(void* EnteroI,void* EnteroK);

void incrementarCantidadEnteros(void *&cantidad,void *entero);
void decrementarCantidadEnteros(void *&cantidad,void *entero);

void UnirCantidadEnteros(void *cantidadP,void *&cantidadS);
void eliminarCantidadEnteros(void *&cantidad);

void mostrarInformacionCantidad(void *cantidad);
void ImprimirInformacionCantidad(ofstream &arch,void *cantidad);

void incrementarSumaEnteros(void *&registro,void *entero);
void decrementarSumaEnteros(void *&registro,void *entero);

void UnirCantidadSumaEnteros(void *registroP,void *&registroS);
void eliminarSumaEnteros(void *&registro);

void mostrarInformacionSuma(void *registro);
void ImprimirInformacionSuma(ofstream &arch,void *registro);

#endif /* BIBLIOTECAENTEROS_H */
