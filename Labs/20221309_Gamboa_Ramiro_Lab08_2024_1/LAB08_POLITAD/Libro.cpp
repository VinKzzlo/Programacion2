/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:04
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
    paginas = 0;
    peso = 0.0;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(nombre) delete nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(char *cad){
    if(nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
    
void Libro::GetNombre(char *cad) const{
    if(nombre) strcpy(cad,nombre);
    else cad[0] = '\0';
}
//Diamantes y pedernales,120,0.4,
void Libro::lee(ifstream &archLib){
    char tit[60],c;
    
    archLib.getline(tit,60,',');
    SetNombre(tit);
    archLib>>paginas>>c>>peso>>c;
}

void Libro::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    archRep<<"Titulo:"<<nombre<<endl;
    archRep<<"Peso: "<<peso<<endl;
}