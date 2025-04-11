/* 
 * Archivo:   Flota.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:18
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Flota.h"
#include "NodoLista.h"
#include "LVehiculos.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota() {
    ifstream arch("Vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo vehiculos"<<endl;
        exit(1);
    }
    
    lista.leeVehiculos(arch);
    
}

void Flota::muestracarga() {
    ofstream arch("ReporteCarga.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo reporte"<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    lista.imprimirReporte(arch);
    
}

void Flota::cargapedidos() {
    ifstream arch("Pedidos3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo vehiculos"<<endl;
        exit(1);
    }
    
    lista.cargaPedidos(arch);
}
