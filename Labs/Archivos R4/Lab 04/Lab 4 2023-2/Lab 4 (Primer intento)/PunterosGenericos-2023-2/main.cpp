/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 21 de abril de 2024, 01:21
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
int main(int argc, char** argv) {
    
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    /*
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
    */
    return 0;
}

