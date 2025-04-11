/* 
 * File:   OrdenVenta.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:25 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OrdenVenta.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
#include "PrioridadBaja.h"

OrdenVenta::OrdenVenta() {
    ptr_orden = nullptr;
}

OrdenVenta::OrdenVenta(const OrdenVenta& orig) {
}

OrdenVenta::~OrdenVenta() {
    if(ptr_orden) delete ptr_orden;
}
/*
B,JXD-139,50375303,64.82,2023-12-01,5
M,CRU-009,50375303,49.38,2023-11-26,1
A,YYK-309,22777006,69.37,2023-11-11,7
*/
void OrdenVenta::leepedidos(ifstream &archPed){
    char tipo;
    
    archPed>>tipo;
    if(archPed.eof()) return;
    archPed.get();
    switch(tipo){
        case 'A':
            ptr_orden = new PrioridadAlta;
            break;
        case 'M':
            ptr_orden = new PrioridadMedia;
            break;
        case 'B':
            ptr_orden = new PrioridadBaja;
            break;
    }
    ptr_orden->lee(archPed);
}

void OrdenVenta::imprimeordenes(ofstream &archRep){
    ptr_orden->imprime(archRep);
}