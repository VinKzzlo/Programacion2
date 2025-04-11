/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NLibro.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:12
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NLibro.h"
#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"

NLibro::NLibro() {
    plibro = nullptr;
}

NLibro::NLibro(const NLibro& orig) {
    this->plibro = orig.plibro;
}

NLibro::~NLibro() {
}

void NLibro::asignaMemoria(char tipo){
    switch(tipo){
        case 'E':
            plibro = new Enciclopedia;
            break;
        case 'N':
            plibro = new Novela;
            break;
        case 'R':
            plibro = new Revista;
            break;
    }
}

void NLibro::cargaLibro(ifstream &archLib){
    plibro->lee(archLib);
}

double NLibro::GetPeso() const{
    return plibro->GetPeso();
}

void NLibro::imprimeLibro(ofstream &archRep){
    plibro->imprime(archRep);
    archRep<<endl;
}