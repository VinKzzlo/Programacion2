/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 18:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //Item A)
    struct Libro arrLibros[300];
    cargarLibros("Libros.csv",arrLibros);
    
    //Item B)
    struct Cliente arrClientes[100];
    cargarClientes("Clientes.csv",arrClientes);
    
    //Item C)
    leerPedidos("Pedidos.txt",arrLibros,arrClientes);
    
    //Item D)
    imprimirReporte("ReporteFinal.txt",arrLibros,arrClientes);
    
    return 0;
}

