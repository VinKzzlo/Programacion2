/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: n421
 *
 * Created on 12 de abril de 2024, 01:08 PM
 */

#include <iostream>
#include <cstdlib>
#include "AperturaDeArchivos.h"
#include "metodoExacto.h"
using namespace std;

/*
 * nombre: Jefferson Robles Cervantes
 * codigo: 20185878
 */
int main(int argc, char** argv) {
    char ***libros;
    int **stock;
    int **PedidosClientes;
    char ***PedidosLibros;
    bool **PedidoEstado;
    leerLibros("Libros.csv",libros,stock);
    pruebaLecturaLibros("reporteLibros.txt",libros,stock);
    
    leerPedidos("Pedidos.txt",libros,stock,PedidosClientes,PedidosLibros,PedidoEstado);
    imprimirReporte("reporteFinal.txt",libros,stock,PedidosClientes,PedidosLibros,PedidoEstado);
    
    //pruebaLecturaLibros("reporteLibros2.txt",libros,stock);
    return 0;
}

