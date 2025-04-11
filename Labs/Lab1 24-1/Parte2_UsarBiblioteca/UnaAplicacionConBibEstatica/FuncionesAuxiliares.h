/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 18:15
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarLibros(const char *nombArch,struct Libro *arrLibros);
void cargarClientes(const char *nombArch,struct Cliente *arrClientes);
void leerPedidos(const char *nombArch,
                 struct Libro *arrLibros,struct Cliente *arrClientes);
void imprimirReporte(const char *nombArch, const struct Libro *arrLibros,
                     const struct Cliente *arrClientes);
#endif /* FUNCIONESAUXILIARES_H */

