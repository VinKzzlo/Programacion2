/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 23:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Flota.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Flota transporte;
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();
    
    
    
    return 0;
}

