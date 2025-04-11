/* 
 * Archivo:   Camion.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:53 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::cargadeposito(NPedido& nped) {
    int pos;
    if(dentroMaxPeso(nped.GetPeso()) and mdeposito.size()<5){
        pos = mdeposito.size();
        mdeposito[pos] = nped;
        SetActcarga(GetActcarga() + nped.GetPeso());
    }
    
}

bool Camion::dentroMaxPeso(double peso) {
    return peso <= (GetMaxcarga() - GetActcarga());
}


void Camion::imprime(ofstream& arch) {
    Vehiculo::imprime(arch);
    arch<<"#Ejes: "<<ejes<<endl;
    arch<<"#Llantas: "<<llantas<<endl;
    arch<<"Lista de Pedidos:"<<endl;
    if(not mdeposito.empty()){
        for(int i=0;i<mdeposito.size();i++){
            class NPedido nped;
            nped = mdeposito[i];
            nped.imprimePedido(i+1,arch);
        }
    }
}
