/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de abril de 2024, 16:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"
int main(int argc, char** argv) {

    struct Cliente arrCli[150];
    struct Producto arrProd[200];
    //Parte A
    leerClientes(arrCli,"Clientes.csv");
    //Parte B
    leerProductos(arrProd,"Productos.csv");
    //Parte C
    completarPedidos(arrCli,arrProd,"Pedidos.csv");
    //Parte D
    imprimirReporte(arrCli,arrProd,"Reporte.txt");

    return 0;
}

