/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: Usuario
 * 
 * Created on 22 de mayo de 2024, 02:56 PM
 */

#include <valarray>

#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::~Almacen() {
}

void Almacen::cargar_clientes(){
    ifstream arch("Clientes.csv");
    int cant=cantidad_clientes;
    
    while(true){
        if(arch>>arreglo_clientes[cant]==false)break;
        cant++;
    }
    
    cantidad_clientes=cant;
}

void Almacen::cargar_productos(){
    ifstream arch("Productos.csv");
    int cant=cantidad_productos;
    
    while(true){
        if(arch>>arreglo_productos[cant]==false)break;
        cant++;
    }
    
    cantidad_productos=cant;
}

void Almacen::cargar_pedidos(){
    ifstream arch("Pedidos.csv");
    
    int indiceCli,indiceProd;
    Pedido ped;
    while(true){
        if(arch>>ped==false)break;
        indiceCli=buscarCliente(ped.GetDni_cliente());
        indiceProd=buscarPredido(ped.GetCodigo());
        
        if(indiceCli!=NO_ENCONTRADO and indiceProd!=NO_ENCONTRADO){
            arreglo_productos[indiceProd]+=ped;
            arreglo_clientes[indiceCli]+=ped;
        }
    }
}

int Almacen::buscarCliente(int dniCli){
    for(int i=0;i<cantidad_clientes;i++)
        if(arreglo_clientes[i].GetDni()==dniCli)return i;
    
    return NO_ENCONTRADO;
}

int Almacen::buscarPredido(char *codProd){
    for(int i=0;i<cantidad_productos;i++)
        if(strcmp(arreglo_productos[i].GetCodigo(),codProd)==0)return i;
    
    return NO_ENCONTRADO;
}

void Almacen::mostrar_datos(){
    ofstream arch("Reporte.txt");
    
    arch<<left<<setw(19)<<"LISTADO DE CLIENTES"<<endl;
    arch<<left<<setw(10)<<"DNI"<<setw(60)<<"Nombre"<<right<<
            setw(10)<<"Telefono"<<setw(10)<<"Monto"<<endl;
    for(int i=0;i<cantidad_clientes;i++){
        arch<<arreglo_clientes[i];
        arch<<endl;
    }
    arch<<endl<<endl;
    arch<<left<<setw(20)<<"LISTADO DE PRODUCTOS"<<endl;
    arch<<left<<setw(8)<<"Codigo"<<setw(50)<<"Descripcion"<<
            right<<setw(10)<<"Precio"<<setw(5)<<"Stock"<<endl;
    for(int i=0;i<cantidad_productos;i++){
        arch<<arreglo_productos[i];
        arch<<endl;
    }
}