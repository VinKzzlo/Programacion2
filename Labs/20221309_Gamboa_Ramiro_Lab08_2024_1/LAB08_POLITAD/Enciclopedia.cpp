/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:25
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
    vigencia = 1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
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
    
    Libro::lee(archLib);    //ENCICLOPEDIA SALVAT,2000,12,
    archLib>>sku>>c>>anho;
    archLib.get();
}

void Enciclopedia::actualiza(){
    if(anho<=2020) SetVigencia(0);
}

void Enciclopedia::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<left<<"SKU:"<<setw(9)<<sku<<"Anho:"<<setw(9)<<anho<<"Vigencia: "
           <<vigencia<<endl;
}