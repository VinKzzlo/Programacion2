/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  26 de septiembre de 2024, 12:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *productos, *clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    
    ordenarClientesKiwi(clientes);
    imprimerepfinal(clientes);
    return 0;
}

