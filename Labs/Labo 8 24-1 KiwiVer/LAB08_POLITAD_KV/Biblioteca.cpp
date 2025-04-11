/* 
 * Archivo:   Biblioteca.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:41
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    char tipo;
    int id;
    double capacidad;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        arch>>id;
        arch.get();
        arch>>capacidad;
        arch.get();
        AEstantes[id-1].SetClase(tipo);
        AEstantes[id-1].SetId(id);
        AEstantes[id-1].SetCapacidad(capacidad);
    }
}

void Biblioteca::llena(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char tipo;
    Nodo *nuevo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        nuevo = new Nodo;
        nuevo->asignaMemoria(tipo);
        nuevo->plibro->lee(arch);
        agregar(nuevo);
    }
}

void Biblioteca::agregar(Nodo* nuevo) {
    for(int i=0;AEstantes[i].GetId()!=0;i++){
        if(AEstantes[i].verificaCapacidad(nuevo->plibro->GetPeso())){
            AEstantes[i].agregaLibro(nuevo);
            return;
        }
    }
    nuevo->plibro = nullptr;
}

void Biblioteca::baja() {
    for(int i=0;AEstantes[i].GetId()!=0;i++){
        AEstantes[i].actualizaVigencia();
    }
}

void Biblioteca::muestra(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    
    arch<<"Estantes:"<<endl;
    imprimeLinea(arch,'=');
    for(int i=0;AEstantes[i].GetId()!=0;i++){
        AEstantes[i].muestraEstantes(arch);
    }
}

void Biblioteca::imprimeLinea(ofstream& arch, char c) {
    for(int i=0;i<80;i++)
        arch.put(c);
    arch<<endl;
}
