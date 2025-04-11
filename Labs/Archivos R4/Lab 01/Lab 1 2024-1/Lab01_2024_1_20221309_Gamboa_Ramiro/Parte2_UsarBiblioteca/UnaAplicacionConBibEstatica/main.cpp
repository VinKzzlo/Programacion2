/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 10 de abril de 2024, 00:16
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
    
    struct Libro arrLib[300];
    struct Cliente arrCli[100];
    //Parte A
    leerLibros("Libros.csv",arrLib);
    //Parte B
    leerClientes("Cientes.csv",arrCli);
    //Parte C
    leerPedidos("Pedidos.txt",arrLib,arrCli);
    //Parte D
    imprimirReporte("Reporte.txt",arrLib,arrCli);
    
    return 0;
}

