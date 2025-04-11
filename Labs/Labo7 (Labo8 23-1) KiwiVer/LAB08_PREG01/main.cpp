/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:52
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Tesoreria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Tesoreria caja;
    caja.cargaescalas("Escalas.csv");
    caja.cargaalumnos("Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("ReporteDePagos.txt");
    return 0;
}

