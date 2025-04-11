/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"
#define MAX_LINEA 70

Estante::Estante() {
    id = 0;
    capacidad = 0.0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}
/*
1,20
2,10
*/
void Estante::leerDatos(ifstream &archEst){
    char c;
    
    archEst>>id>>c>>capacidad;
    archEst.get();
}

bool Estante::verificaCapacidad(double pesoLib){
    if(capacidad > (Llibros.GetPeso() + pesoLib)) return true;
    return false;
}

void Estante::agregaLibro(class Nodo *nuevo,double peso){
    Llibros.insertar(nuevo);
}

void Estante::verificaVigencia(){
    Llibros.vigenciaNodos();
}

void Estante::muestraEstantes(ofstream &archRep){
    archRep<<"Id: "<<id<<endl;
    archRep<<"Tipo: ";
    switch(clase){
        case 'H':
            archRep<<"Horizontal"<<endl;
            break;
        case 'V':
            archRep<<"Vertical"<<endl;
            break;
    }
    archRep<<"Capacidad: "<<capacidad<<endl;
    archRep<<"Libros Contenidos:"<<endl;
    imprimirLinea(archRep,'=');
    Llibros.imprimeLibros(archRep);
    imprimirLinea(archRep,'=');
}

void Estante::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}