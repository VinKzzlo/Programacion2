/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 26 de abril de 2024, 08:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
int main(int argc, char** argv) {
    
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    
    return 0;
}

