/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 9 de septiembre de 2024, 01:13 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
//Parte A
void leerPlatos(const char *nombArch,struct Plato *arrPlatos);
//Parte B
void leerRepartidores(const char *nombArch,struct Repartidor *arrRepartidores);
//Parte C
void leerPedidos(const char *nombArch,struct Plato *arrPlatos,
                                            struct Repartidor *arrRepartidores);
//Parte D
void imprimirReporte(const char *nombArch,const struct Plato *arrPlatos,
                                      const struct Repartidor *arrRepartidores);
#endif /* FUNCIONESAUXILIARES_H */
