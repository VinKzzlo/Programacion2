/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bebida.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:08
 */
#include<cstring>
#include <iomanip>
#include<fstream>
using namespace std;
#include "Bebida.h"

Bebida::Bebida() {
}

Bebida::Bebida(const Bebida& orig) {
}

Bebida::~Bebida() {
}

void Bebida::SetTamanho(string tamanho) {
    this->tamanho = tamanho;
}

string Bebida::GetTamanho() const {
    return tamanho;
}

void Bebida::lee(ifstream &arch){
    Producto::lee(arch);
    getline(arch, tamanho);
}

void Bebida::imprime(ofstream &arch){
    Producto::imprime(arch);
    arch<<"Tamano: "<<setw(50)<<left<<tamanho<<right<<endl;
}

int Bebida::GetTiempoPrep(){
    return 10;
}
