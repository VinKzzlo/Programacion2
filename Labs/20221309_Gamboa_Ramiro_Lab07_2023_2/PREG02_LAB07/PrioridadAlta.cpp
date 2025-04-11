/* 
 * File:   PrioridadAlta.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:21 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadAlta.h"

PrioridadAlta::PrioridadAlta() {
    recargo = 0.0;
    total = 0.0;
}

PrioridadAlta::PrioridadAlta(const PrioridadAlta& orig) {
}

PrioridadAlta::~PrioridadAlta() {
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}
//YYK-309,22777006,69.37,2023-11-11,7
void PrioridadAlta::lee(ifstream &archPed){
    Pedido::lee(archPed);
    archPed>>recargo;
    archPed.get();
}

void PrioridadAlta::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    Pedido::imprime(archRep);
    archRep<<left<<setw(52)<<recargo<<right<<setw(10)<<Pedido::GetTotal()<<endl;
}

void PrioridadAlta::actualiza(){
    total = GetSubtotal()*recargo/100;
    Pedido::SetTotal(GetSubtotal()+total);
}