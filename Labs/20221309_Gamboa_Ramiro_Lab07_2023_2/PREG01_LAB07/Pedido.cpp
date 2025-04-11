/* 
 * File:   Pedido.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:17 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    subtotal = 0.0;
    fecha = 0;
    estado = nullptr;
    total = 0.0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(codigo) delete codigo;
    if(estado) delete estado;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char *cad){
    if(codigo) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}
    
void Pedido::GetCodigo(char *cad) const{
    if(codigo) strcpy(cad,codigo);
    else cad[0] = '\0';
}
    
void Pedido::SetEstado(char *cad){
    if(estado) delete estado;
    estado = new char[strlen(cad)+1];
    strcpy(estado,cad);
}
    
void Pedido::GetEstado(char *cad) const{
    if(estado) strcpy(cad,estado);
    else cad[0] = '\0';
}
//JXD-139,50375303,64.82,2023-12-01,
void Pedido::lee(ifstream &archPed){
    int dd,mm,aa;
    char cod[8],c;
    
    archPed.getline(cod,8,',');
    SetCodigo(cod);
    archPed>>dni_cliente>>c>>subtotal>>c>>aa>>c>>mm>>c>>dd>>c;
    fecha = aa*10000+mm*100+dd;
}

void Pedido::imprime(ofstream &archRep){
    int dd = fecha%100;
    int mm = (fecha/100)%100;
    int aa = fecha/10000;
    
    archRep<<left<<setw(10)<<codigo<<setw(10)<<dni_cliente;
    if(estado) archRep<<left<<setw(12)<<estado;
    else archRep<<setw(12)<<' ';
    archRep<<left<<setw(11)<<subtotal;
    archRep<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'
           <<setfill(' ')<<left<<setw(12)<<aa;
}