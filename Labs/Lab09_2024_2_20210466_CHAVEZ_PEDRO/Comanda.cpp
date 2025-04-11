/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Comanda.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:10
 */
#include <iomanip>
#include <iostream>
using namespace std;
#include "Comanda.h"

Comanda::Comanda() {
    id=" ";
    fecha_atencion=0;
    fecha_servicio=0;
    total=0;
    tiempo_preparacion=0;
}

Comanda::Comanda(const Comanda& orig) {
    id=orig.id;
    fecha_atencion=orig.fecha_atencion;
    fecha_servicio=orig.fecha_servicio;
    total=orig.total;
    tiempo_preparacion=orig.tiempo_preparacion;
    observacion=orig.observacion;
    
}

Comanda::~Comanda() {
}

void Comanda::SetFecha_servicio(int fecha_servicio) {
    this->fecha_servicio = fecha_servicio;
}

int Comanda::GetFecha_servicio() const {
    return fecha_servicio;
}

void Comanda::SetFecha_atencion(int fecha_atencion) {
    this->fecha_atencion = fecha_atencion;
}

int Comanda::GetFecha_atencion() const {
    return fecha_atencion;
}

void Comanda::SetId(string id) {
    this->id = id;
}

string Comanda::GetId() const {
    return id;
}

bool Comanda::operator<(const Comanda &aux)const{
    cout << "Comparando " << id << " con " << aux.GetId() << endl;
    return id<aux.id;
}

void Comanda::imprime(ofstream &arch)const{
    arch<<setw(4)<<id<<endl;
    arch<<"Hora de Atencion: "<<setw(2)<<setfill('0')<<fecha_atencion/100<<':'<<setw(2)<<fecha_atencion%100<<setfill(' ')<<endl;
    arch<<"Hora de Servicio: "<<setw(2)<<setfill('0')<<fecha_servicio/100<<':'<<setw(2)<<fecha_servicio%100<<setfill(' ')<<endl;
    arch<<"Total: "<<setprecision(2)<<fixed<<total<<endl;
    arch<<observacion<<endl;
    arch<<endl;
}

void Comanda::lee(ifstream &arch){
    char id[5];
    string xd;
    int hh, mm, hora;
    char c;
    arch.getline(id, 4, ',');
    if(!arch.eof()){
        xd=id;
        SetId(xd);
        arch>>hh>>c>>mm>>c;
        hora=hh*100 + mm;
        SetFecha_atencion(hora);
        arch>>hh>>c>>mm;
        hora=hh*100 + mm;
        SetFecha_servicio(hora);
        arch.get();
    }
    return;
}

void Comanda::SetObservacion(string observacion) {
    this->observacion = observacion;
}

string Comanda::GetObservacion() const {
    return observacion;
}

void Comanda::SetTotal(double total) {
    this->total = total;
}

double Comanda::GetTotal() const {
    return total;
}

void Comanda::VerificarTardanza(){
    if(((fecha_atencion/100)*60) + (fecha_atencion%100) + tiempo_preparacion <= ((fecha_servicio/100)*60) + (fecha_servicio%100))
        SetObservacion("ATENDIDO A TIEMPO");
    else
        SetObservacion("ATENDIDO CON TARDANZA");
}

void Comanda::SetTiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

int Comanda::GetTiempo_preparacion() const {
    return tiempo_preparacion;
}

ifstream &operator>>(ifstream &arch, Comanda &f){
    char id[5];
    string xd;
    int hh, mm, hora;
    char c;
    arch.getline(id, 4, ',');
    if(!arch.eof()){
        xd=id;
        f.SetId(xd);
        arch>>hh>>c>>mm>>c;
        hora=hh*100 + mm;
        f.SetFecha_atencion(hora);
        arch>>hh>>c>>mm;
        hora=hh*100 + mm;
        f.SetFecha_servicio(hora);
        arch.get();
    }
    return arch;
}




