/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 07:13 PM
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
    Flota Unidades;
    Unidades.cargaflota();
    Unidades.cargapedidos();
    
    Unidades.muestraflota();
    
    
    return 0;
}

