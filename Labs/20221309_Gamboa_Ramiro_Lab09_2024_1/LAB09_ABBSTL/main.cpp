/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * codigo: 20221309
 *
 * Created on 21 de junio de 2024, 10:05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
int main(int argc, char** argv) {
    
    Biblioteca bli;
    
    bli.carga();
    bli.muestra();
    bli.prueba(8);
    
    return 0;
}

