/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:47 PM
 */

#include "Furgon.h"

Furgon::Furgon() {
    filas=0;
    puertas=0;
}

Furgon::~Furgon() {
}

void Furgon::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    char c;
    arch>>filas>>c>>puertas;
}

void Furgon::imprime(ofstream& arch) {
    arch<<right<<setw(20+15)<<"Codigo Cliente:"<<setw(9)<<GetCliente()<<endl;
    arch<<right<<setw(20+6)<<"Placa:"<<setw(15)<<GetPlaca()<<endl;
    arch<<right<<setw(20+13)<<"Carga Maxima:"<<setw(8)<<fixed<<setprecision(2)
            <<GetMaxcarga()<<setprecision(0)<<endl;
    arch<<right<<setw(20+13)<<"Carga Actual:"<<setw(8)<<fixed<<setprecision(2)
            <<GetActcarga()<<setprecision(0)<<endl;
    arch<<right<<setw(20+7)<<"#filas:"<<setw(14)<<filas<<endl;
    arch<<right<<setw(20+9)<<"#puertas:"<<setw(12)<<puertas<<endl;
    Vehiculo::imprime(arch);
}