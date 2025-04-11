/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 23:22
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {

    //Item A)
    struct Cliente arrClientes[150];
    cargarClientes("Clientes.csv",arrClientes);
    
    //Item B)
    struct Producto arrProductos[200];
    cargarProductos("Productos.csv",arrProductos);
    
    //Item C)
    actualizarPedidos("Pedidos.csv",arrClientes,arrProductos);
    
    //Item D)
    imprimirReporte("ReporteFinal.txt",arrClientes,arrProductos);
    
    return 0;
}

