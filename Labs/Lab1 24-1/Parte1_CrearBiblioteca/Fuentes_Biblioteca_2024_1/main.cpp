/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 3 de septiembre de 2024, 17:09
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
    struct Libro libros[300];
    struct Cliente clientes[100];
    struct LibroSolicitado libPedido;
    int numLib = 0, numCli=0;
    ifstream archLib, archCli, archPed;
    ofstream archRepLib, archRepCli;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLib,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepLib,"ReporteLibros.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli,"ReporteClientes.txt");
          
    //carga Libros
    while(archLib>>libros[numLib]) numLib++;
    strcpy(libros[numLib].codigo,"FIN");
    
    //carga Clientes
    while(archCli>>clientes[numCli]) numCli++;
    clientes[numCli].dni = 0;
    
    // asumimos datos para visualizar si se agrega de forma correcta en el reporte
    libPedido.numeroDePedido = 1;
    strcpy(libPedido.codigoDelLibro,"CRY6839");
    libPedido>>libros;
    clientes[0]<<libPedido;
    ++clientes[0];
    for(int i=0;strcmp(libros[i].codigo,"FIN")!=0;i++)
        archRepLib<<libros[i];
    for(int i=0;clientes[i].dni;i++)
        archRepCli<<clientes[i];
    
    return 0;
}

