/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:44 PM
 */

#include "Camion.h"

Camion::Camion() {
    ejes=0;
    llantas=0;
}

Camion::~Camion() {
}

void Camion::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    char c;
    arch>>ejes>>c>>llantas;
}

void Camion::imprime(ofstream& arch) {
    arch<<right<<setw(20+15)<<"Codigo Cliente:"<<setw(9)<<GetCliente()<<endl;
    arch<<right<<setw(20+6)<<"Placa:"<<setw(15)<<GetPlaca()<<endl;
    arch<<right<<setw(20+13)<<"Carga Maxima:"<<setw(8)<<fixed<<setprecision(2)
            <<GetMaxcarga()<<setprecision(0)<<endl;
    arch<<right<<setw(20+13)<<"Carga Actual:"<<setw(8)<<fixed<<setprecision(2)
            <<GetActcarga()<<setprecision(0)<<endl;
    arch<<right<<setw(20+6)<<"#Ejes:"<<setw(15)<<ejes<<endl;
    arch<<right<<setw(20+9)<<"#Llantas:"<<setw(12)<<llantas<<endl;
    Vehiculo::imprime(arch);
}
