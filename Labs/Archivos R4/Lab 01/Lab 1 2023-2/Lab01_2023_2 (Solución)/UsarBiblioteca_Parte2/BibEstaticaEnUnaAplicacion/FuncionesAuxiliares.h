/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 4 de abril de 2024, 17:04
 */
#include <fstream>
using namespace std;
#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

//Parte A
void leerClientes(struct Cliente *arrCli,const char *nombArch);
//Parte B
void leerProductos(struct Producto *arrProd,const char *nombArch);
//Parte C
void completarPedidos(struct Cliente *arrCli,struct Producto *arrProd,
                      const char *nombArch);
double agregarPrecios(struct Pedido &ped,struct Producto *arrProd);
//Parte D
void imprimirReporte(struct Cliente *arrCli,struct Producto *arrProd,
                     const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */
