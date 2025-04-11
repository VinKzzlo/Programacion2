/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:09
 */

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
}

PlatoFondo::PlatoFondo(const PlatoFondo& orig) {
}

PlatoFondo::~PlatoFondo() {
}

void PlatoFondo::lee(ifstream &arch){
    Producto::lee(arch);
    for(int i=0; i<4; i++){
        arch>>proteina[i];;
        arch.get();
    }
}

void PlatoFondo::imprime(ofstream &arch){
    Producto::imprime(arch);
    arch<<"Proteinas: ";
    
    for(int i=0; i<4; i++){
        if(proteina[i]==1){
            if(i==0)
                arch<<"POLLO ";
            if(i==1)
                arch<<"CARNE ";
            if(i==2)
                arch<<"PESCADO ";
            if(i==3)
                arch<<"LACTEOS ";
        }
    }
    arch<<endl;
}

bool PlatoFondo::contiene(int eliminar){
    if(proteina[eliminar]==1)
        return true;
    else
        return false;
}

int PlatoFondo::GetTiempoPrep(){
    return 20;
}
