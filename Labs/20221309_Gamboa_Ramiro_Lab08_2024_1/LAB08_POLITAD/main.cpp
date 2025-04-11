/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 14 de junio de 2024, 10:03
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
    bli.llena();
    bli.baja();
    bli.muestra();
    
    return 0;
}

