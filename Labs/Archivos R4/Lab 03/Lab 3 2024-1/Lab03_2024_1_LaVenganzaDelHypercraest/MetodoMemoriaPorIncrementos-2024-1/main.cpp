/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de mayo de 2024, 16:38
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
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    /*
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
                      pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    
    ordenarPedidosClientes(pedidosClientes);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,
                              pedidosLibros,pedidosAtendidos);
    */
    return 0;
}

