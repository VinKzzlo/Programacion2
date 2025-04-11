/* 
 * File:   main.cpp
 * Author: Juan Zavala
 * Codigo: 20226608
 *
 * Created on 9 de septiembre de 2024, 01:07 AM
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
    
    struct Plato arrPlatos[150];
    struct Repartidor arrRepartidores[50];
    //Parte A
    leerPlatos("PlatosOfrecidos.csv",arrPlatos);
    //Parte B
    leerRepartidores("RepartidoresContratados.csv",arrRepartidores);
    //Parte C
    leerPedidos("OrdenesDeCompra.txt",arrPlatos,arrRepartidores);
    //Parte D
    imprimirReporte("Reporte.txt",arrPlatos,arrRepartidores);
    
    return 0;
}

