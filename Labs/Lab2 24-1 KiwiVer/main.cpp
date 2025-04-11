/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  12 de septiembre de 2024, 15:44
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
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionDePedidos("Pedidos.txt", libros, stock,
                      pedidosClientes, pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    
    return 0;
}

