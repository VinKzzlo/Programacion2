/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 17 de septiembre de 2024, 10:13 AM
 */

#include "PunterosGenericos.h"

using namespace std;

int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    
    return 0;
}

