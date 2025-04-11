/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 23:25
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarClientes(const char *nombArch,struct Cliente *arrClientes);
void cargarProductos(const char *nombArch,struct Producto *arrProductos);
void actualizarPedidos(const char *nombArch,struct Cliente *arrClientes,
                       struct Producto *arrProductos);
double agregarPrecios(struct Pedido &pedido,struct Producto *arrProductos);
void imprimirReporte(const char *nombArch, struct Cliente *arrClientes,
                      struct Producto *arrProductos);
#endif /* FUNCIONESAUXILIARES_H */

