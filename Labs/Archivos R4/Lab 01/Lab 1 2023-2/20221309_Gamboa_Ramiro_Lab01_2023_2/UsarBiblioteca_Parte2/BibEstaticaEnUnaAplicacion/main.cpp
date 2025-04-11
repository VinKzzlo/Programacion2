/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 1 de abril de 2024, 22:17
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
int main(int argc, char** argv) {
    //Declarar variables
    struct Cliente arrCli[150];
    struct Producto arrProd[200];
    //Parte A
    leerClientes(arrCli,"Clientes.csv");
    //Parte B
    leerProductos(arrProd,"Productos.csv");
    //Parte C
    leerPedidosYCompletar(arrCli,arrProd,"Pedidos.csv");
    //Parte D
    imprimirReporte(arrCli,arrProd,"Reporte.txt");
    
    return 0;
}

