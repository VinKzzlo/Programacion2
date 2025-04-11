/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 1 de mayo de 2024, 23:48
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"
int main(int argc, char** argv) {
    
    int numcamiones;
    double pesomaximo;
    void *flota;
    
    numcamiones = 5,pesomaximo = 10;
    cargacamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,
                  "numeros.txt");
    qsort(flota,numcamiones,sizeof(void*),cmpnumero);
    muestracamiones(flota,numcamiones,imprimenumero,"reportenum.txt");
    
    return 0;
}

