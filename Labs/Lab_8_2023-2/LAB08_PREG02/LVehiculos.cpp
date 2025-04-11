/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.cpp
 * Author: Usuario
 * 
 * Created on 11 de junio de 2024, 09:50 PM
 */

#include "LVehiculos.h"

LVehiculos::LVehiculos() {
    lfin=nullptr;
    lini=nullptr;
}

LVehiculos::~LVehiculos() {
}

/*
F,16552775,S7E-946,300,2,3
C,20864087,O5L-856,1000,2,6
 */

void LVehiculos::leerArchivoVehiculos(ifstream& arch){
    char tipo;
    NodoLista *nuevoNodo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        
        switch(tipo){
            case 'F':
                nuevoNodo=new NodoLista(tipo);
                break;
            case 'C':
                nuevoNodo=new NodoLista(tipo);
                break;
            default:
                while(arch.get()!='\n');
                cout<<"Tipo incorrecto de vehuiculo"<<endl;
                break;
        }
        
        nuevoNodo->leeRegistroVehiculo(arch);
        insertarAlFinal(nuevoNodo);
    }
}

void LVehiculos::insertarAlFinal(NodoLista* &nuevoNodo) {
    if(lini==nullptr){
        lini=nuevoNodo;
        lfin=nuevoNodo;
    }else{
        lfin->sig=nuevoNodo;
        lfin=nuevoNodo;
    }
}

void LVehiculos::imprimirReporte(ofstream& arch) {
    NodoLista *temp=lini;
    
    arch<<right<<setw(30)<<"REPORTE DE FLOTA"<<endl;
    for(int i=0;i<50;i++)arch<<'=';
    arch<<endl<<endl;
    
    while(temp){
        temp->imprimirRegistro(arch);
        temp=temp->sig;
    }
}
//50375303,JXD.139,6,120
void LVehiculos::cargaArchivoPedidos(ifstream& arch) {
    NPedido nodoAux;
    
    int cliente,cant;
    char cod[10],c;
    double peso;
    while(true){
        arch>>cliente;
        if(arch.eof())break;
        arch.get();
        arch.getline(cod,10,',');
        arch>>cant>>c>>peso;
        
        nodoAux.SetCantidad(cant);
        nodoAux.SetCodigo(cod);
        nodoAux.SetPeso(peso);
        
        insertarPedido(cliente,nodoAux);
    }
}

void LVehiculos::insertarPedido(int cliente, NPedido& nodoAux) {
    NodoLista *temp=lini;
    
    double pesoActual;
    while(temp){
        pesoActual=temp->unidad->GetActcarga();
        if(temp->unidad->GetCliente()==cliente and 
                pesoActual+nodoAux.GetPeso()<=temp->unidad->GetMaxcarga()){
            temp->insertarPedidoEnPila(nodoAux);
            pesoActual+=nodoAux.GetPeso();
            temp->unidad->SetActcarga(pesoActual);
        }
            
        temp=temp->sig;
    }
}
