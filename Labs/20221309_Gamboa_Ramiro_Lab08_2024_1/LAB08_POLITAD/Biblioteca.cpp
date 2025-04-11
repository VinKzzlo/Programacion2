/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 10:13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"
#define MAX_LINEA 70

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga(){
    ifstream archEst("Estantes2.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes2.csv"<<endl;
        exit(1);
    }
    char tipo;
    Estante est;
    int i=0;
    while(1){
        archEst>>tipo;
        if(archEst.eof()) break;
        archEst.get();
        est.SetClase(tipo);
        est.leerDatos(archEst);
        AEstante[i] = est;
        i++;
    }
}
/*
N,Diamantes y pedernales,120,0.4,Jose Maria Arguedas
E,ENCICLOPEDIA SALVAT,2000,12,78323,2015
R,Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
*/
void Biblioteca::llena(){
    ifstream archLib("Libros3.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros3.csv"<<endl;
        exit(1);
    }
    char tipo;
    Nodo *nuevo;
    while(1){
        archLib>>tipo;
        if(archLib.eof()) break;
        archLib.get();
        nuevo = new Nodo;
        nuevo->asignaMemoria(tipo);
        nuevo->plibro->lee(archLib);
        agregar(nuevo);
    }
}

void Biblioteca::agregar(class Nodo *nuevo){
    for(int i=0;AEstante[i].GetId()!=0;i++){
        if(AEstante[i].verificaCapacidad(nuevo->plibro->GetPeso())){
            AEstante[i].agregaLibro(nuevo,nuevo->plibro->GetPeso());
            return;
        }
    }
    nuevo->SetNull();
}

void Biblioteca::baja(){
    for(int i=0;AEstante[i].GetId()!=0;i++){
        AEstante[i].verificaVigencia();
    }
}

void Biblioteca::muestra(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archRep<<"Estantes:"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<endl;
    for(int i=0;AEstante[i].GetId()!=0;i++)
        AEstante[i].muestraEstantes(archRep);
}

void Biblioteca::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}