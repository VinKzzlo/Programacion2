/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Repartidor.cpp
 * Author: gabri
 * 
 * Created on October 26, 2024, 12:09 PM
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Repartidor.h"

Repartidor::Repartidor() {
    codigo=nullptr;
    nombre=nullptr;
    tipo=nullptr;
    cantidad=0;
    numero=0;
    total=0;
}

Repartidor::Repartidor(const Repartidor& orig) {
}

Repartidor::~Repartidor() {
}

void Repartidor::SetCodigo(char *cad){
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Repartidor::GetCodigo(char *cad){
    if(codigo!=nullptr) 
        strcpy(cad, codigo);
}

void Repartidor::SetNombre(char *cad){
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Repartidor::GetNombre(char *cad){
    if(nombre!=nullptr) 
        strcpy(cad, nombre);
}

void Repartidor::SetTipo(char *cad){
    if(tipo!=nullptr) delete tipo;
    tipo=new char[strlen(cad)+1];
    strcpy(tipo, cad);
}

void Repartidor::GetTipo(char *cad){
    if(tipo!=nullptr) 
        strcpy(cad, tipo);
}

void Repartidor::operator+=(Pedido &ped){
    int i; 
    int posCli=buscarcliente(ped.GetDni());  //BUSCAS EL CLIENTE DENTRO DEL REPARTIDOR
     if(posCli!=-1)         //SI LO ENCUENTRA AGREGAS EL PEDIDO EN ESA POSICION
         lcliente[posCli]+=ped;
     else{                              //SI NO ENCUENTRAN EL FOR ENCUENTRA LA SIGUIENTE POS A AGREGAR Y SE HACE EXACTAMENTE LA MISMA SBRECARGA
         for(i=0; lcliente[i].GetDni(); i++);
         lcliente[i]+=ped;
         cantidad++;        //ACTUALIZAS LA CANTIDAD DE CLIENTES QUE TIENE EL REPARTIDOR
     }
}

int Repartidor::buscarcliente(int dni){
    for(int i=0; lcliente[i].GetDni(); i++)
        if(lcliente[i].GetDni()==dni) 
            return i;
    return -1;
}

void Repartidor::actualizarDatos(Cliente *c, Plato *p){
    for(int i=0; lcliente[i].GetDni(); i++){
        if(!lcliente[i].GetTelefono()){ //PUSE ESTE CONDICIONAL YA QUE EL FOR RECORRE TODOS LOS CLIENTES AGREGADOS AL REPARTIDOR Y CON ESTE IF SI ALGUN CLIENTE NO TIENE SUS DATOS COMPLETOS
                                                        //DEVUELVE TRUE PARA PODER ACTUALIZAR ESS DATOS RESTANTES
            int pos=lcliente[i].buscarcliente(c); //BUSQUEDA NORMAL DE TODA LA VIDA DE TP
            if(pos!=-1)
                lcliente[i]&c[pos];     //CUANDO ENCUENTRA EL DNI DEL PEDIDO EN EL ARREGLO DE CLIENTES SE LO AGREGAS AL ARREGLO CLIENTES DENTRO DE LA CLASE REPARTIDOR CON LA SOBRECARGA &
        }
        int posplato=lcliente[i].buscarplato(p); //BUSQUEDA NORMAL DE TODA LA VIDA DE TP
        if(posplato!=-1)
            lcliente[i]&p[posplato];    //YA QUE UN PLATO PUEDE SER AGREGAD A UN CLIENTE CON DATOS COMPLETOS, SE PONE FUERA DEL CONDICIONAL DE EXISTENCIA DEL TELEFONO Y CON LA SOBRECARGA SE L AGREGAS AL CLIENTE
    }
}

void Repartidor::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Repartidor::GetCantidad() const {
    return cantidad;
}

void Repartidor::SetTotal(double total) {
    this->total = total;
}

double Repartidor::GetTotal() const {
    return total;
}

void Repartidor::SetNumero(int numero) {
    this->numero = numero;
}

int Repartidor::GetNumero() const {
    return numero;
}

void Repartidor::operator!(){
    for(int i=0; lcliente[i].GetDistancia(); i++){                                      //EL OPERADOR QUE TANTO TEMIAN EN ESTE CASO ESTAS TOMANDO UN SOLO REPARTIDOR DEL ARREGLO Y LE CAMBIAS EL TOTAL POR ENVIOS CON LOS CONDICIONALES
        if(lcliente[i].GetDistancia()<8)
            total+=10.5;
        if(lcliente[i].GetDistancia()>=8 && lcliente[i].GetDistancia()<12)
            total+=14.8;
        if(lcliente[i].GetDistancia()>=12 && lcliente[i].GetDistancia()<20)
            total+=23.6;
        if(lcliente[i].GetDistancia()>=20)
            total+=31.7;
        !lcliente[i];  //POR CADA CLIENTE DENTRO DEL REPARTIDOR ACTUALIZAS LS TOTALES NADA MAS
    }
}

void Repartidor::imprimecliente(ofstream &arch){
    char a[100];
    for(int i=0; lcliente[i].GetDni(); i++){
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        lcliente[i].GetNombre(a);
        arch<<"DNI: "<<lcliente[i].GetDni()<<setw(5)<<" "<<"NOMBRE: "<<setw(44)<<left<<a<<right<<"TELEFONO"<<setw(10)<<lcliente[i].GetTelefono()<<endl;
        lcliente[i].GetDistrito(a);
        arch<<"DISTRITO: "<<left<<setw(30)<<a<<right<<setw(30)<<" "<<"DISTANCIA:"<<setw(5)<<setprecision(2)<<fixed<<lcliente[i].GetDistancia()<<" km"<<endl;
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        arch<<setw(2)<<lcliente[i].GetCantidad()<<" PLATOS SOLICITADOS: ";
        arch<<setw(52)<<" "<<"TOTAL:"<<setw(7)<<lcliente[i].GetTotal();
        arch<<endl;
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        lcliente[i].imprimirplatos(arch);
    }
}

//JNV387,Justino Norabuena Virginia Karina,Motocicleta
//PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
//SYI157,Sam Yallico Ines ,Motocicleta

ifstream &operator>>(ifstream &arch, Repartidor &r){
    char a[100];
    
    arch.getline(a, 100, ',');
    if(!arch.eof()){
        r.SetCodigo(a);
        arch.getline(a, 100, ',');
        r.SetNombre(a);
        arch.getline(a, 100, '\n');
        r.SetTipo(a);
        r.SetNumero(r.GetNumero()+1); //AGREGUE ESTE DATO PORQUE HACER EL FOR HASTA QUE NO EXISTA UN CHAR NO FUNCIONABA Y CUANDO EMPECE EL REPARTIDR SOL TENIA TRES CHARS ENTONCES XD 
                                                                //PERO YA NO LO NECESITO CREO PERO SI LO VEN ES POR ESO
    }
    return arch;
}

ofstream &operator>>(ofstream &arch, Repartidor &r){
    char a[10], nom[100], t[100];
    r.GetCodigo(a);
    r.GetNombre(nom);
    r.GetTipo(t);
    arch<<left<<setw(10)<<a<<right<<setw(50)<<left<<nom<<right<<setw(15)<<left<<t<<right<<"TOTAL:"<<setw(7)<<setprecision(2)<<fixed<<r.GetTotal()<<endl;
    arch<<setw(100)<<setfill('=')<<" "<<setfill(' ')<<endl;
    arch<<"TIENE "<<r.GetCantidad()<<" PEDIDO(S): ";
    if(r.GetCantidad()==0)
            arch<<"NINGUN PEDIDO";
    arch<<endl;
    r.imprimecliente(arch);
}