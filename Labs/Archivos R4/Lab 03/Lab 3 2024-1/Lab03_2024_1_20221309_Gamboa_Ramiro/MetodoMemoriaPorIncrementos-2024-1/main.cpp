/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 11 de mayo de 2024, 02:38
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicaDeMemoria.h"
int main(int argc, char** argv) {
    
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
                      pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    
    ordenarPedidosClientes(pedidosClientes);
    reporteDeEntregaDePedidos("ReporteTop5DeEntregaDePedidos.txt",
                              pedidosClientes,pedidosLibros,pedidosAtendidos);
    
    return 0;
}

