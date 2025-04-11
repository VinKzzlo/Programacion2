/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 18:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Restaurante.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Restaurante restaurante;
    
    restaurante < "Clientes.csv";
    restaurante <= "PlatosOfrecidos.csv";
    restaurante <<= "Pedidos.csv";
    restaurante>>"ReporteDeVentasDelDia.txt";
    return 0;
}

