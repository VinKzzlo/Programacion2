/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:09
 */

#include "Nodo.h"
#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"

Nodo::Nodo() {
    plibro = nullptr;
    sig = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    plibro = nullptr;
}

void Nodo::asignaMemoria(char tipo){
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

void Nodo::SetNull(){
    plibro = nullptr;
}