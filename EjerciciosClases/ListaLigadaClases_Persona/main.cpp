/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  5 de noviembre de 2024, 8:28
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Lista.h"

/*
 * 
 */
int main(int argc, char** argv) {
    class Lista listaLigada;
    listaLigada.crear("datos.txt");
    listaLigada.imprimir("reporteDeEnteros.txt");
    listaLigada.imprimeRecursivo("reporteRecursivo.txt");
//    listaLigada.elimina();
//    
//    listaLigada.crear("datos2.txt");
//    listaLigada.imprimir("reporteDeEnteros2.txt");
    
    return 0;
}

