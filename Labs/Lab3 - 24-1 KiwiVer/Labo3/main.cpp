/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 18:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "MetodoPorIncrementos.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    return 0;
}

