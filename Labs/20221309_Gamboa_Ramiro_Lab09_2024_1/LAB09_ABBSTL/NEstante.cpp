/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NEstante.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:23
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NEstante.h"
#include "NLibro.h"
#define MAX_LINEA 70
NEstante::NEstante() {
    id = 0;
    capacidad = 0.0;
    disponible = 0.0;
    izq = nullptr;
    der = nullptr;
}

NEstante::NEstante(const NEstante& orig) {
}

NEstante::~NEstante() {
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}
/*
N,Diamantes y pedernales,120,0.7,Jose Maria Arguedas
E,ENCICLOPEDIA SALVAT,2000,12,78323,2015
R,Educacion,48,0.2,10199403,2024,6
*/
void NEstante::leerLibros(ifstream &archLib){
    char tipo,c;
    NLibro nuevo;
    for(int i=0;i<10;i++){
        archLib>>tipo>>c;
        nuevo.asignaMemoria(tipo);
        nuevo.cargaLibro(archLib);
        if(disponible >= nuevo.GetPeso()){
            vlibros.push_back(nuevo);
            disponible -= nuevo.GetPeso();
        }
    }
}

void NEstante::muestra(ofstream &archRep){
    archRep<<"Estante: "<<id<<endl;
    archRep<<"Capacidad: "<<left<<setw(8)<<capacidad<<"Disponible: "<<disponible
           <<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;i<vlibros.size();i++){
        vlibros[i].imprimeLibro(archRep);
    }
}

void NEstante::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}