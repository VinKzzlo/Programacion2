/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 15:15
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Almacen.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    return 0;
}

