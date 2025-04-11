/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 29 de julio de 2024, 10:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
int main(int argc, char** argv) {
    
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
                      pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,
                              pedidosLibros,pedidosAtendidos);
    
    return 0;
}

