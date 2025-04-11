/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 26 de marzo de 2024, 10:39
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
int main(int argc, char** argv) {

    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDeProductos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
  /*pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,
            dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,
            precios,fechaPedidos,codigoPedidos,dniCantPedidos);
    
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",productos,stock,
            precios);
    */
    return 0;
}

