/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 27 de abril de 2024, 21:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
int main(int argc, char** argv) {
    
    void *cola;
    creacola(cola,leenumero,prioridadnumero,"numeros.txt");
    imprimirnum(cola,"Reporte.txt");
    /*
    descargarcola(cola,muestranumero,"Orden.txt");
    
    creacola(cola,leepedido,prioridadpedido,"Pedidos.csv");
    imprimirped(cola,"Reppedidos.txt");
    descargarcola(cola,muestrapedido,"Ordenpedidos.txt");
    */
    return 0;
}

