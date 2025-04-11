/* 
 * File:   PrioridadBaja.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:24 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja() {
    dias_espera = 0;
    nueva_fecha_entrega = 0;
}

PrioridadBaja::PrioridadBaja(const PrioridadBaja& orig) {
}

PrioridadBaja::~PrioridadBaja() {
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}
//JXD-139,50375303,64.82,2023-12-01,5
void PrioridadBaja::lee(ifstream &archPed){
    Pedido::lee(archPed);
    archPed>>dias_espera;
    archPed.get();
}

void PrioridadBaja::imprime(ofstream &archRep){
    int dd = nueva_fecha_entrega%100;
    int mm = (nueva_fecha_entrega/100)%100;
    int aa = nueva_fecha_entrega/10000;
    
    archRep<<fixed<<setprecision(2);
    Pedido::imprime(archRep);
    archRep<<left<<setw(30)<<' '<<setw(10)<<dias_espera;
    archRep<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'
           <<setfill(' ')<<left<<setw(6)<<aa;
    archRep<<right<<setw(10)<<Pedido::GetTotal()<<endl;
}

void PrioridadBaja::actualiza(){
    Pedido::SetTotal(GetSubtotal());
    nueva_fecha_entrega = GetFecha()+dias_espera;
}