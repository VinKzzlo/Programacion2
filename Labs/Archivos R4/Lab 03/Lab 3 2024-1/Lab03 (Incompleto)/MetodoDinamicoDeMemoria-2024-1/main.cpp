/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 20 de abril de 2024, 03:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoDeMemoria.h"
int main(int argc, char** argv) {
    
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    //Lectura de Libros
    lecturaDeLibros("Libros.csv",libros,stock);
    //Prueba de Lectura de Libros Inicial
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    //Atencion de Pedidos
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
                      pedidosAtendidos);
    //Prueba de Lectura de Libros Final
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    //Ordenamiento
    ordenar(pedidosClientes);
    //Reporte de Entrega de Pedidos
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,
                              pedidosLibros,pedidosAtendidos);
    return 0;
}

