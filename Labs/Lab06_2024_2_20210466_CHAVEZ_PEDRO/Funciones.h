/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: gabri
 *
 * Created on October 25, 2024, 11:01 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Repartidor.h"


void cargarepartidores(Repartidor *r);
void  cargaclientes(Cliente *c);
void  cargaplatos(Plato *p);
void actualizar(Repartidor *r, Cliente *c, Plato *p);
int buscarepartidor(Repartidor *r, char *b);
void imprimir(Repartidor *r);
void agregartotales(Repartidor *r);

#endif /* FUNCIONES_H */
