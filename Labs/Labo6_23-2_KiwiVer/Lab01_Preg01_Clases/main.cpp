/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:18
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Producto.h"

void pruebaClis(class Cliente *arrClis,int &cantCli){

    ifstream archIn("Clientes.csv",ios::in);
    ofstream archOut("ReporteClis.txt",ios::out);
    while(archIn>>arrClis[cantCli]){
        archOut<<arrClis[cantCli];
        cantCli++;
    }
    
}

void pruebaProds(class Producto *arrProds,int &cantPro){
    ifstream archIn("Productos.csv",ios::in);
    ofstream archOut("ReporteProds.txt",ios::out);
    while(archIn>>arrProds[cantPro]){
        archOut<<arrProds[cantPro];
        cantPro++;
    }
}

int main(int argc, char** argv) {
    class Cliente arrClis[150]{};
    class Producto arrProds[180]{};
    int cantCli=0, cantPro=0;
    pruebaClis(arrClis,cantCli);
    pruebaProds(arrProds, cantPro);
    return 0;
}

