/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetAutor(char *cad){
    if(autor) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor,cad);
}

void Novela::GetAutor(char *cad) const{
    if(autor) strcpy(cad,autor);
    else cad[0] = '\0';
}
//Diamantes y pedernales,120,0.7,Jose Maria Arguedas
void Novela::lee(ifstream &archLib){
    char aut[40];
    
    Libro::lee(archLib);    //Diamantes y pedernales,120,0.7,
    archLib.getline(aut,40);
    SetAutor(aut);
}

void Novela::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<"Autor: "<<autor<<endl;
}