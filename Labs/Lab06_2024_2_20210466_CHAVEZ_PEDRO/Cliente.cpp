/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: gabri
 * 
 * Created on October 26, 2024, 12:09 PM
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"

Cliente::Cliente() {
}

Cliente::Cliente(const Cliente& orig) {
    nombre=nullptr;
    distrito=nullptr;
    distancia=0;
    dni=0;
    telefono=0;
    cantidad=0;
    total=0;
}

Cliente::~Cliente() {
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetNombre(char *cad){
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad){
    if(nombre!=nullptr) 
        strcpy(cad, nombre);
}

void Cliente::SetDistrito(char *cad){
    if(distrito!=nullptr) delete distrito;
    distrito=new char[strlen(cad)+1];
    strcpy(distrito, cad);
}

void Cliente::GetDistrito(char *cad){
    if(distrito!=nullptr) 
        strcpy(cad, distrito);
}

void Cliente::operator+=(Pedido &ped){
    int i=0;
    char a[10];                                                         //EL PEDIDO SOLO TRAE CODIGO PLATO, REPARTIDOR Y CANTIDAD DE UN PLATO
    SetDni(ped.GetDni());               //ESTE AGREGA EL DNI DEL CLIENTE QUE HIZO EL PEDIDO CON ESE REPARTIDOR
    ped.GetCodigoplato(a);                                      //POR TANTO SON LOS UNICOS ATRIBUTOS QUE SE PODRAN LLENAR DENTRO DEL ARREGLO CLIENTES DENTRO DEL REPARTIDOR
    lplato[cantidad].SetCodigo(a);                                          //Y ESTO AGREGA EL PLATO QUE PIDIO ESE CLIENTE DENTRO DEL ARREGLO PLATOS DEL CLIENTE
    lplato[cantidad].SetCantidad(ped.GetCant());
    SetDistancia(ped.GetDistancia());   //LA DISTANCIA TAMBIEN ESTA EN EL ARCHIVO
    cantidad++;         //AUMENTA LA CANTIDAD DE TIPOS DE PLATOS PEDIDOS POR CLIENTE 
}

int Cliente::buscarcliente(Cliente *c){
    for(int i=0; c[i].GetDni(); i++)
        if(this->dni==c[i].GetDni())
            return i;
    return -1;
}

int Cliente::buscarplato(Plato *p){
    char a[10], b[10];
    lplato[cantidad-1].GetCodigo(b); //YA QUE ESTA HECHO PARA QUE LOS DATS SE COMPLETEN CON CADA INSERCION DE PEDIDO SOLO NECESITAS EL ULTIMO PLATO AGREGADO OSEA CANTIDAD-1
    for(int i=0; p[i].GetPrecio(); i++){
        p[i].GetCodigo(a);
        if(strcmp(a, b)==0)
            return i;
    }
    return -1;
}

void Cliente::operator&(Cliente &c){  //COPIAR LOS DATOS, RECONTRA FACIL AUN QUEDA UNA SEMANA SI ES QUE NO ENTIENDES TIENES TIEMPO 
    SetTelefono(c.GetTelefono());
    char a[100];                                //c VIENE DE LA POS EN EL ARREGLO DE CLIENTES DEL MAIN SI ES QUE NO ENTIENDES Y EL OTRO CLIENTE IMPLICITO EN Cliente:: VIENE DE LA POS ARREGLO DE CLIENTES DENTRO DEL ARREGLO DE REPARTIDORES
    c.GetNombre(a);
    SetNombre(a);
    c.GetDistrito(a);
    SetDistrito(a);
}

void Cliente::operator&(Plato &p){
    lplato[cantidad-1].SetPrecio(p.GetPrecio());    //COMO AGREGAS SOLO UN PLATO POR PEDIDO, CON LA CANTIDAD DE PLATOS EN UN CLIENTE CONSIGUES LA POSICION PARA AGREGARLO
    char a[100];
    p.GetNombre(a);
    lplato[cantidad-1].SetNombre(a);    //p VIENE DE LA POS EN EL ARREGLO DE PLATOS DEL MAIN
    p.GetCodigo(a);
    lplato[cantidad-1].SetCodigo(a);
    p.GetTipo(a);
    lplato[cantidad-1].SetTipo(a);
}

void Cliente::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Cliente::GetCantidad() const {
    return cantidad;
}

void Cliente::SetDistancia(double distancia) {
    this->distancia = distancia;
}

double Cliente::GetDistancia() const {
    return distancia;
}

void Cliente::operator!(){              //SOLO ACTUALIZA EL TOTAL
    int i;
    for(i=0; lplato[i].GetCantidad(); i++)
        total+=(lplato[i].GetPrecio()*lplato[i].GetCantidad());
}

void Cliente::imprimirplatos(ofstream &arch){
    char a[100];
    for(int i=0; lplato[i].GetPrecio(); i++){
        lplato[i].GetCodigo(a);
        arch<<setw(5)<<"+"<<setw(10)<<left<<a<<right;
        lplato[i].GetNombre(a);
        arch<<setw(50)<<left<<a<<right<<setw(5)<<lplato[i].GetCantidad()<<setprecision(2)<<fixed<<setw(10)<<lplato[i].GetPrecio()<<"|"<<setw(7)<<lplato[i].GetCantidad()*lplato[i].GetPrecio()<<endl; //ACA MULTIPLIQUE YA ME DABA PEREZA AGREGAR TRO ATRIBUTO MAS, 
                                                                                                                                                                                                                                                                                                                                 //LO PUEDEN HACER Y LO ACTUALIZAN EN LA SOBRECARGA !
    }
}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

//90367684,CORONEL CHUMPITAZ HELI ,Villa Maria del Triunfo,977518179
//99774549,HENRIQUEZ ESPINO BEATRIZ ,San Borja,982400218
//63640178,CABRERA CANALES GUILLERMO EDRIC,Magdalena del Mar,979548883
//66039166,LAURA WONG MELVIN HENRRY,Rimac,996785878

ifstream &operator>>(ifstream &arch, Cliente &c){
   int dni, telefono;
   char a[100], d;
    
   arch>>dni;
    if(!arch.eof()){
        arch>>d;
        c.SetDni(dni);
        arch.getline(a, 100, ',');
        c.SetNombre(a);
        arch.getline(a, 100, ',');
        c.SetDistrito(a);
        arch>>telefono;
        c.SetTelefono(telefono);
    }
    return arch;
}