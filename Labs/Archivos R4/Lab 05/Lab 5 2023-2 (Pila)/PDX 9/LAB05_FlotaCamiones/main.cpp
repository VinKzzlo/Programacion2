
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  main.cpp
 * Autor: Redbull te da aaaaalas.jpg
/*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

int main(int argc, char** argv) {
    int numcamiones;
    double pesomaximo;
    void *flota;
    
    numcamiones = 5; pesomaximo = 10;
    cargaCamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt");
    qsort(flota,numcamiones,sizeof(void *),cmpnumero);
    muestraCamiones(flota,numcamiones,imprimenumero,"reportenum.txt");
    
    numcamiones = 100; pesomaximo = 400;
    cargaCamiones(flota,numcamiones,pesomaximo,leeregistro,calcularegistro,"pedidos3.csv");
    qsort(flota,numcamiones,sizeof(void *),cmpregistro);
    muestraCamiones(flota,numcamiones,imprimeregistro,"reporteregistro.txt");

    return 0;
}
