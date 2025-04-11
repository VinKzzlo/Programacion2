/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 5 de abril de 2024, 23:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
int main(int argc, char** argv) {
    
    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,
                             dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,
                            precios,fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",productos,stock,
                               precios);
    return 0;
}

