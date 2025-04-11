/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Biblioteca.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Biblioteca bli;
    bli.carga("Estantes2.csv");
    bli.llena("Libros3.csv");
    bli.baja();
    bli.muestra("ReporteDeBiblioteca.txt");
    
    return 0;
}

