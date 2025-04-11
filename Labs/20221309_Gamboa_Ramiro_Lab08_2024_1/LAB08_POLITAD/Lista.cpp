/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:10
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    peso = 0.0;
    ini = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    if(ini) delete ini;
}

void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

void Lista::insertar(class Nodo *nuevo){
    Nodo *p = ini;
    if(ini==nullptr){
        ini = nuevo;
    }else{
        while(p->sig) p = p->sig;
        p->sig = nuevo;
    }
    peso += nuevo->plibro->GetPeso();
}

void Lista::vigenciaNodos(){
    Nodo *p = ini;
    while(p){
        p->plibro->actualiza();
        p = p->sig;
    }
}

void Lista::imprimeLibros(ofstream &archRep){
    Nodo *p = ini;
    while(p){
        p->plibro->imprime(archRep);
        archRep<<endl;
        p = p->sig;
    }
}

