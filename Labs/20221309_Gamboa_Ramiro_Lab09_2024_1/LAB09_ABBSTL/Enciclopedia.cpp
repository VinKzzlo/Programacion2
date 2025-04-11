/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    sku = 0;
    anho = 0;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}
//ENCICLOPEDIA SALVAT,2000,12,78323,2015
void Enciclopedia::lee(ifstream &archLib){
    char c;
    
    Libro::lee(archLib);    //ENCICLOPEDIA SALVAT,2000,12,78323,
    archLib>>sku>>c>>anho;
    archLib.get();
}

void Enciclopedia::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<"SKU:"<<left<<setw(15)<<sku<<"Anho: "<<anho<<endl;
}