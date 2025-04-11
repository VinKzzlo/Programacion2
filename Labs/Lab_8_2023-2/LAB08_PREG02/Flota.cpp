/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:51 PM
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv");
    if(not arch.is_open()){
        cout<<"Error, no se pudo abrir el archivo Vehiculos.csv"<<endl;
        exit(1);
    }
    
    lista.leerArchivoVehiculos(arch);
}

void Flota::muestracarga() {
    ofstream arch("Reporte de flota.txt");
    
    lista.imprimirReporte(arch);
}

void Flota::cargapedidos() {
    ifstream arch("Pedidos3.csv");
    if(not arch.is_open()){
        cout<<"Error, no se pudo abrir el archivo Pedidos3.csv"<<endl;
        exit(1);
    }
    
    lista.cargaArchivoPedidos(arch);
}
