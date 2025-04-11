/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: ramir
 *
 * Created on 26 de marzo de 2024, 10:57
 */
#include <fstream>
using namespace std;
#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios);
char **leeProductos(ifstream &arch);
char *leeCadena(ifstream &arch,int max,char delim);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios);
void lecturaDeProductos(const char *nombArch,int *&fechaPedidos,
                        char ***&codigoPedidos,int ***&dniCantPedidos);
int buscaFecha(int fecha,int *buffFecha,int i);
void agregarFecha(int *buffFecha,char ***buffCodPed,int ***buffCantPed,
                  int fecha,int *numped,int &ind,int &n);
void agregarPedido(char **buffcod,int **buffdni,int &n,int dni,int cant,
                   char *codigo);
void cargaArreglos(int *&fechaPedidos,char ***&codigoPedidos,
                   int ***&dniCantPedidos,int *buffFecha,char ***buffCodPed,
                   int ***buffCantPed,int n);
void cargaNivelInterno(char **&codigoped,int **&dnicantped,char **buffCodPe,
                       int **buffCantPe,int cantped);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
