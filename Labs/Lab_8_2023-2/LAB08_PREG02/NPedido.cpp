/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:27 PM
 */
#include "NPedido.h"

NPedido::NPedido() {
    cantidad=0;
    codigo=nullptr;
    peso=0;
    sig=nullptr;
}

NPedido::NPedido(const NPedido &_orig) {
    cantidad=_orig.cantidad;
    SetCodigo(_orig.codigo);
    peso=_orig.peso;
    sig=nullptr;
}


NPedido::~NPedido() {
    if(codigo)delete[] codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void NPedido::SetCodigo(char* codigo) {
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::imprimeRegistro(ofstream& arch) {
    arch<<right<<setw(20+3+7)<<codigo<<setw(4)<<cantidad<<fixed<<setprecision(2)<<
            setw(7)<<peso<<setprecision(0)<<endl;
}
