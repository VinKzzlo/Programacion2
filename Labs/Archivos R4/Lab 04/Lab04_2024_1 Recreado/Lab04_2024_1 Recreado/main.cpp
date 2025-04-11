/* 
 * File:   main.cpp
 * Author: n422
 *
 * Created on 23 de abril de 2024, 01:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
int main(int argc, char** argv) {
    
    void *clientes,*libros;
    
    cargaClientes(clientes);
    cargaLibros(libros);
    cargaPedidos(clientes,libros);
    imprimeReporte(clientes);
    
    return 0;
}

