/* 
 * Archivo:   LVehiculos.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  22 de noviembre de 2024, 0:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "LVehiculos.h"
#include "NodoLista.h"

LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
}

LVehiculos::~LVehiculos() {
}

void LVehiculos::leeVehiculos(ifstream& arch) {
    char tipo;
    NodoLista *nuevo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        nuevo = new NodoLista(tipo);
        nuevo->leeRegistroVehiculo(arch);
        insertar(nuevo);
    }
}

void LVehiculos::insertar(NodoLista* &nuevo) {
    if(lini==nullptr){
        lini = nuevo;
        lfin = nuevo;
    }
    else{
        lfin->sig = nuevo;
        lfin = nuevo;
    }
}

void LVehiculos::imprimirReporte(ofstream& arch) {
    NodoLista *ptr = lini;
    arch<<"REPORTE DE FLOTA"<<endl;
    
    for(int i=0;i<50;i++) arch<<'=';
    arch<<endl<<endl;
    while(ptr){
        ptr->imprimeRegistro(arch);
        ptr = ptr->sig;
    }
}

void LVehiculos::cargaPedidos(ifstream& arch) {
    NPedido nodoAux;
    
    int cliente, cant;
    char codigo[8];
    double peso;
    
    while(true){
        arch>>cliente;
        if(arch.eof())break;
        arch.get();
        arch.getline(codigo,8,',');
        arch>>cant;
        arch.get();
        arch>>peso;
        
        nodoAux.SetCantidad(cant);
        nodoAux.SetCodigo(codigo);
        nodoAux.SetPeso(peso);
        
        insertarPedido(nodoAux,cliente);
    }
}

void LVehiculos::insertarPedido(NPedido &nodoAux, int codCli) {
    NodoLista *ptr = lini;
    double pesoActual;
    while(ptr){
        pesoActual = ptr->unidad->GetActcarga();
        if(ptr->unidad->GetCliente()==codCli and 
                pesoActual+nodoAux.GetPeso() <=ptr->unidad->GetMaxcarga()){
            ptr->insertaEnPila(nodoAux);
            pesoActual += nodoAux.GetPeso();
            ptr->unidad->SetActcarga(pesoActual);
        }
        ptr = ptr->sig;
    }
}
