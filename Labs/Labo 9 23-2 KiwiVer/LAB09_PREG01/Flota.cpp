/* 
 * Archivo:   Flota.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 11:04 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include <vector>
#include "Flota.h"
#include "NVehiculo.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota() {
    ifstream arch("Vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"NO Se pudo abrir el archivo Vehiculos "<<endl;
        exit(1);
    }
    ofstream archAD("ReporteFlota11.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO Se pudo abrir el archivo ReporteFlota "<<endl;
        exit(1);
    }
    class NVehiculo auxVeh;
    
    while(true){
        auxVeh.leeTipoVehiculo(arch);
        if(arch.eof())break;
        vflota.push_back(auxVeh);
    }
    
}

void Flota::muestraflota() {
    ofstream arch("ReporteFlota.txt",ios::out);
    if(not arch.is_open()){
        cout<<"NO Se pudo abrir el archivo ReporteFlota "<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<"REPORTE DE FLOTA "<<endl;
    for(int i=0;i<60;i++) arch.put('=');
    arch<<endl;
    for(int i=0; i<vflota.size();i++){
        vflota[i].imprimeVehiculo(arch);
    }
}
