/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Dato.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:14
 */

#include "Dato.h"
#include "Entrada.h"
#include "Bebida.h"
#include "PlatoFondo.h"

Dato::Dato() {
    pedidos=nullptr;
}

Dato::Dato(const Dato& orig) {
//    pedidos=nullptr;
    *this=orig;
}

Dato::~Dato() {
}

string Dato::generarMemoria(string busca, string id){
    int pos=busca.find(id);
    string tipo;
    if(pos!=id.npos){
        tipo=busca.substr(pos+id.size()+1, 1);
        if(tipo.compare("B")==0)
            pedidos=new Bebida;
        if(tipo.compare("E")==0)
            pedidos=new Entrada;
        if(tipo.compare("P")==0)
            pedidos=new PlatoFondo;
        busca.erase(pos, id.size()+3);                   
    }
    return busca;    
}

void Dato::lee(ifstream &arch){
    if(pedidos!=nullptr)
        pedidos->lee(arch);
}

void Dato::operator=(const Dato &f){
    pedidos=f.pedidos;
}

void Dato::imprime(ofstream &arch){
    pedidos->imprime(arch);
}

double Dato::ObtenPrecio(){
    return pedidos->ObtenPrecio();
}

bool Dato::contiene(int elimina){
    return pedidos->contiene(elimina);
}

int Dato::tiempoPrep(){
    return pedidos->GetTiempoPrep();
}


