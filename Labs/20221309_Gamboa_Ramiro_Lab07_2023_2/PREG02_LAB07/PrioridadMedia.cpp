/* 
 * File:   PrioridadMedia.cpp
 * Author: ramir
 * 
 * Created on 6 de junio de 2024, 08:22 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadMedia.h"

PrioridadMedia::PrioridadMedia() {
    descripcion = nullptr;
    nueva_fecha_entrega = 0;
}

PrioridadMedia::PrioridadMedia(const PrioridadMedia& orig) {
}

PrioridadMedia::~PrioridadMedia() {
    if(descripcion) delete descripcion;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(char *cad){
    if(descripcion) delete descripcion;
    descripcion = new char[strlen(cad)+1];
    strcpy(descripcion,cad);
}
    
void PrioridadMedia::GetDescripcion(char *cad) const{
    if(descripcion) strcpy(cad,descripcion);
}
//CRU-009,50375303,49.38,2023-11-26,1
void PrioridadMedia::lee(ifstream &archPed){
    int codDescripcion;
    
    Pedido::lee(archPed);
    archPed>>codDescripcion;
    archPed.get();
    
    if(codDescripcion==0) SetDescripcion("Inactivo");
    if(codDescripcion==1) SetDescripcion("Activo");
}

void PrioridadMedia::imprime(ofstream &archRep){
    int dd = nueva_fecha_entrega%100;
    int mm = (nueva_fecha_entrega/100)%100;
    int aa = nueva_fecha_entrega/10000;
    
    Pedido::imprime(archRep);
    archRep<<left<<setw(11)<<' '<<setw(14)<<descripcion<<setw(15)<<' ';
    archRep<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'
           <<setfill(' ')<<left<<setw(6)<<aa;
    archRep<<right<<setw(10)<<Pedido::GetTotal()<<endl;
}

void PrioridadMedia::actualiza(){
    Pedido::SetTotal(GetSubtotal());
    nueva_fecha_entrega = GetFecha()+1;
    SetEstado(descripcion);
}