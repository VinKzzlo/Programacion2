/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  23 de septiembre de 2024, 23:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "AperturaDeArchivos.h"
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *clientes, *reserva;
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes,reserva);
    reportefinal(reserva);
    return 0;
}

