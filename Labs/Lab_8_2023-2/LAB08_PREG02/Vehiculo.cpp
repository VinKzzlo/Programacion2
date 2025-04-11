/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:30 PM
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    actcarga=0;
    cliente=0;
    maxcarga=0;
    ped=nullptr;
    placa=nullptr;
}

Vehiculo::~Vehiculo() {
    if(placa)delete[] placa;
}

void Vehiculo::SetPed(NPedido* ped) {
    this->ped = ped;
}

NPedido* Vehiculo::GetPed() const {
    return ped;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* placa) {
    this->placa =new char [strlen(placa)+1];
    strcpy(this->placa,placa);
}

char* Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream& arch) {
    char c,_placa[10];
    arch>>cliente>>c;
    arch.getline(_placa,10,',');
    SetPlaca(_placa);
    arch>>maxcarga>>c;
}
//15 + 9 = 21 ancho total

void Vehiculo::imprime(ofstream& arch) {
    arch<<right<<setw(20+8)<<"Pedidos:"<<endl;
    if(not pilavacia()){
        imprimePila(arch);
    }else
        arch<<right<<setw(20+3+30)<<"No hay pedidos para el cliente"<<endl;
    
    arch<<endl;
}

void Vehiculo::push(NPedido& nodoAux) {
    NPedido *nuevoNodo=new NPedido(nodoAux);
    
    nuevoNodo->sig=ped;
    ped=nuevoNodo;
}

bool Vehiculo::pilavacia() {
    return ped==nullptr;
}

void Vehiculo::imprimePila(ofstream& arch) {
    NPedido *temp=ped;
    
    while(temp){
        temp->imprimeRegistro(arch);
        temp=temp->sig;
    }
}
