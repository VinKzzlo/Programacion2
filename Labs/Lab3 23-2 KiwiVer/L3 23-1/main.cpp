/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 20:17
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",
                             fechaPedidos,codigoPedidos,dniCantPedidos);
    
    return 0;
}

