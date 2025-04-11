/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 10 de abril de 2024, 02:10
 */
#include <fstream>
using namespace std;
#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
//Parte A
void leerLibros(const char *nombArch,struct Libro *arrLib);
//Parte B
void leerClientes(const char *nombArch,struct Cliente *arrCli);
//Parte C
void leerPedidos(const char *nombArch,struct Libro *arrLib,
                 struct Cliente *arrCli);
//Parte D
void imprimirReporte(const char *nombArch,const struct Libro *arrLib,
                     const struct Cliente *arrCli);
#endif /* FUNCIONESAUXILIARES_H */
