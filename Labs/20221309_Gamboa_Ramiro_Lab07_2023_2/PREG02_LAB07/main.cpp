/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 7 de junio de 2024, 01:56 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Almacen.h"
int main(int argc, char** argv) {
    
    Almacen almacen;
    
    almacen.cargar_pedidos();
    almacen.actualizar_pedidos();
    almacen.imprimir_ordenes_venta();
    
    return 0;
}

