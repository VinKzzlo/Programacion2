/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Revista.h"

Revista::Revista() {
    ISSN = 0;
    anho = 0;
    numero = 0;
    vigencia = 1;
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}
//Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
void Revista::lee(ifstream &archLib){
    char c;
    
    Libro::lee(archLib);    //Boletin de Arqueologia PUCP,40,0.25,
    archLib>>ISSN>>c>>anho>>c>>numero;
    archLib.get();
}

void Revista::actualiza(){
    if(anho<=2020) SetVigencia(0);
}

void Revista::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<left<<"ISSN:"<<setw(9)<<ISSN<<"Anho:"<<setw(9)<<anho<<"Vigencia: "
           <<vigencia<<endl;
    archRep<<"Numero: "<<numero<<endl;
}