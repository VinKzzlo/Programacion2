/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Bleak
 *
 * Created on September 12, 2024, 9:21 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "MetodoExactoDeMemoria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    lecturaDeLibros ("Libros.csv",libros, stock);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosInicial.txt" ,libros, stock);
    atencionDePedidos ("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosFinal.txt", libros, stock);
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedisos.txt", pedidosClientes, pedidosLibros,
    pedidosAtendidos);
    return 0;
    return 0;
}

