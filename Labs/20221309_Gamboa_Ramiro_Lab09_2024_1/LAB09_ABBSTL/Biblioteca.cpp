/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: alulab14
 * 
 * Created on 21 de junio de 2024, 10:15
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}
/*
1,20
2,10
*/
void Biblioteca::carga(){
    ifstream archEst("Estantes3.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes3.csv"<<endl;
        exit(1);
    }
    AEstante.crea(archEst);
}

void Biblioteca::muestra(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    AEstante.muestraEstantes(archRep);
}

void Biblioteca::prueba(double pesoLib){
    ofstream archPrueba("ReportePrueba.txt",ios::out);
    if(not archPrueba.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReportePrueba.txt"<<endl;
        exit(1);
    }
    AEstante.verificaSiEntra(archPrueba,pesoLib);
}