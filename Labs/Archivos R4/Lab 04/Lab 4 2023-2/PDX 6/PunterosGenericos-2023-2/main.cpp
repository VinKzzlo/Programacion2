
/*/ 
 * Projecto:  PunterosGenericos-2023-2
 * Nombre del Archivo:  main.cpp
 * Autor: void *heart = nullptr;
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "PunterosGenericos.h"
//#include "MuestraPunteros.h"

// Modulo Principal
int main(int argc, char** argv) {
    // Declaracion de Variables
    void *productos,*clientes;
    // Proceso de Carga de Registros de Productos
    cargarproductos(productos);
    // Proceso de Carga de Registros de Clientes
    cargarclientes(clientes);
    // Proceso de Atencion de Pedidos Realizados por Clientes
    cargarpedidos(productos,clientes);
    // Emision de Reporte de Pedidos de Clientes
    imprimereporte(clientes);
    
    return 0;
}
