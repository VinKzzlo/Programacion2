/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 25 de abril de 2024, 23:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
int main(int argc, char** argv) {
    
    void *clientes,*libros;
    
    cargaclientes(clientes);
    /*
    cargalibros(libros);
    cargapedidos(clientes,libros);
    */
    return 0;
}

