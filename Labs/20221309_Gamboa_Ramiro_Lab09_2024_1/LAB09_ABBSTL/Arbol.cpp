/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:14
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::crea(ifstream &archEst){
    ifstream archLib("Libros31.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros31.csv"<<endl;
        exit(1);
    }
    int id;
    double capacidad;
    NEstante *nuevo;
    while(1){
        archEst>>id;
        if(archEst.eof()) break;
        archEst.get();
        archEst>>capacidad;
        nuevo = new NEstante;
        nuevo->SetId(id);
        nuevo->SetCapacidad(capacidad);
        nuevo->SetDisponible(capacidad);
        nuevo->leerLibros(archLib);
        insertarR(raiz,nuevo);
    }
}

void Arbol::insertarR(class NEstante *&arbol,class NEstante *nuevo){
    if(arbol==nullptr){
        arbol = nuevo;
        return;
    }
    if(arbol->GetDisponible() > nuevo->GetDisponible()){
        insertarR(arbol->izq,nuevo);
    }else{
        insertarR(arbol->der,nuevo);
    }
    
}

void Arbol::muestraEstantes(ofstream &archRep){
    imprimeEstantes(archRep,raiz);
}

void Arbol::imprimeEstantes(ofstream &archRep,class NEstante *arbol){
    
    if(arbol==nullptr) return;
    
    imprimeEstantes(archRep,arbol->izq);
    arbol->muestra(archRep);
    imprimeEstantes(archRep,arbol->der);
}

void Arbol::verificaSiEntra(ofstream &archPrueba,double pesoLib){
    imprimePrueba(archPrueba,raiz,pesoLib);
}

void Arbol::imprimePrueba(ofstream &archPrueba,class NEstante *arbol,
                          double pesoLib){
    
    if(arbol==nullptr) return;
    
    imprimePrueba(archPrueba,arbol->izq,pesoLib);
    if(arbol->GetDisponible() <= pesoLib) archPrueba<<"Si hay espacio"<<endl;
    else archPrueba<<"No es posible colocar el libro"<<endl;
    arbol->muestra(archPrueba);
    imprimePrueba(archPrueba,arbol->der,pesoLib);
}