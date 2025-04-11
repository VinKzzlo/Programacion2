/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:11
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
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
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
//Educacion,48,0.2,10199403,2024,6
void Revista::lee(ifstream &archLib){
    char c;
    
    Libro::lee(archLib);    //Educacion,48,0.2,
    archLib>>ISSN>>c>>anho>>c>>numero;
    archLib.get();
}

void Revista::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<"ISSN:"<<left<<setw(15)<<ISSN<<"Anho: "<<anho<<endl;
}