/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Entrada.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:08
 */

#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}

Entrada::Entrada(const Entrada& orig) {
}

Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

void Entrada::lee(ifstream &arch){
    string pica;
    Producto::lee(arch);
    getline(arch, pica);
    
    if(pica.compare("picante")==0)
        picante=true;
}

void Entrada::imprime(ofstream &arch){
    Producto::imprime(arch);
    arch<<"Picante: ";
    if(picante)
        arch<<"Si";
    else
        arch<<"No";
    arch<<endl;
}

int Entrada::GetTiempoPrep(){
    return 15;
}



