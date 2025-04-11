/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  27 de octubre de 2024, 21:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Cadena.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Cadena c1, c2;
    c1.SetCad("Juan ");
    c2.SetCad("Lopez");
    
    c1 + c2;
    c1.imprimeCad();
    return 0;
}

