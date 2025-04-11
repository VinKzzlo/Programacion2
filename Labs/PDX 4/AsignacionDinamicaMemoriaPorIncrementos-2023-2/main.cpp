
/*/ 
 * Projecto:  AsignacionDinamicaMemoriaPorIncrementos-2023-2
 * Nombre del Archivo:  main.cpp
 * Autor: XxGatitaDinamica69xX
/*/

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

// Modulo Principal
int main(int argc, char** argv) {
    // Declaracion de Variables
    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;
    // Proceso de Carga de Datos de Producto || Prueba de Carga de Datos de Productos
    lecturaDeProducto("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    // Proceso de Carga de Datos de Pedidos || Prueba de Carga de Datos de Pedidos
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,dniCantPedidos);
    // Emision de Reporte de Envio de Pedidos
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
                            fechaPedidos,codigoPedidos,dniCantPedidos);
    // Emision de Estado Final de Productos [Se Reutiliza la funcion de prueba de lectura]
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",productos,stock,precios);

    return 0;
}
