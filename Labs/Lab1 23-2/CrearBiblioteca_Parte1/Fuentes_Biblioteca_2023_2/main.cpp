/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 21:06
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCli, archPro, archPed;
    ofstream archRepCli,archRepPro;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPro,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli,"ReporteClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepPro,"ReporteProds.txt");
    
    
    struct Cliente arrClientes[150];
    struct Producto arrProds[200];
    struct Pedido pedido;
    int numCli=0, numPro=0;
    //carga Clientes
    while(archCli>>arrClientes[numCli])
        numCli++;
    arrClientes[numCli].dni = 0;
    
    //carga Prods
    while(archPro>>arrProds[numPro])
        numPro++;
    strcpy(arrProds[numPro].codigo,"XXXXXXX");
    
    archPed>>pedido;
    arrClientes += pedido;
    arrProds += pedido;
    
    for(int i=0;arrClientes[i].dni!=0;i++)
        archRepCli<<arrClientes[i];
    
    for(int i=0;strcmp(arrProds[i].codigo,"XXXXXXX")!=0;i++)
        archRepPro<<arrProds[i];
    
    return 0;
}

