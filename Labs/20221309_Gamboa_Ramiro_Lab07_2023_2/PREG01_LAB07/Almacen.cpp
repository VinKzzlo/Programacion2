/* 
 * File:   Almacen.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:26 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Almacen.h"
#define MAX_LINEA 125

Almacen::Almacen() {
    cantidad_ordenes = 0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_ordenes(int cantidad_ordenes) {
    this->cantidad_ordenes = cantidad_ordenes;
}

int Almacen::GetCantidad_ordenes() const {
    return cantidad_ordenes;
}

void Almacen::cargar_pedidos(){
    ifstream archPed("Pedidos.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.csv"<<endl;
        exit(1);
    }
    while(1){
        ordenes[cantidad_ordenes].leepedidos(archPed);
        if(archPed.eof()) break;
        cantidad_ordenes++;
    }
}

void Almacen::actualizar_pedidos(){
    
}

void Almacen::imprimir_ordenes_venta(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archRep<<left<<setw(10)<<"Codigo"<<setw(10)<<"DNI"<<setw(10)<<"Estado"
           <<setw(10)<<"Sub-total"<<setw(20)<<"Fecha de entrega"<<setw(10)
           <<"Recargo"<<setw(15)<<"Descripcion"<<setw(15)<<"Dias de espera"
           <<setw(18)<<"Nueva fecha"<<setw(10)<<"Total"<<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;i<cantidad_ordenes;i++)
        ordenes[i].imprimeordenes(archRep);
}

void Almacen::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}