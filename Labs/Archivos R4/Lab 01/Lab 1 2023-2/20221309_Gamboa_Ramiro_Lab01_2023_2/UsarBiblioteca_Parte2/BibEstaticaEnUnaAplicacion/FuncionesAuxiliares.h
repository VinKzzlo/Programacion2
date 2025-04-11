/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 1 de abril de 2024, 22:20
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerClientes(struct Cliente *arrCli,const char *nombArch);
void leerProductos(struct Producto *arrProd,const char *nombArch);
void leerPedidosYCompletar(struct Cliente *arrCli,struct Producto *arrProd,
                                 const char *nombArch);
double retornarPrecio(struct Producto *arrProd,char *codigo);
void imprimirReporte(struct Cliente *arrCli,struct Producto *arrProd,
                     const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */
