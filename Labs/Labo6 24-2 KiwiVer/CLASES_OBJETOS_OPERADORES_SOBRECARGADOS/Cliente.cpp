/* 
 * Archivo:   Cliente.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 18:55
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Cliente.h"
#include "FuncionesAux.h"

Cliente::Cliente() {
    nombre = nullptr;
    distrito = nullptr;
    descuento = 0.0;
    totalPagado = 0.0;
}

Cliente::Cliente(const Cliente& orig) {
    nombre = nullptr;
    distrito = nullptr;
    *this = orig;
}

Cliente::~Cliente() {
    if(nombre != nullptr ) delete nombre;
    if(distrito != nullptr) delete distrito;
}

void Cliente::SetTotalPagado(double monto) {
    totalPagado += monto;
}

double Cliente::GetTotalPagado() const {
    return totalPagado;
}

void Cliente::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::GetDescuento() const {
    return descuento;
}

void Cliente::SetDistrito(char* dist) {
    if(distrito != nullptr) delete distrito;
    distrito = new char[strlen(dist)+1];
    strcpy(distrito,dist);
}

void Cliente::GetDistrito(char *cad) const {
    if(distrito==nullptr) cad[0] = 0;
    strcpy(cad,distrito);
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char *cad) const {
    if(nombre==nullptr) cad[0] = 0;
    strcpy(cad,nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator=(const class Cliente& copyC) {
    dni = copyC.GetDni();
    descuento = copyC.GetDescuento();
    totalPagado = copyC.GetTotalPagado();
    char nomb[60], dist[40];
    copyC.GetNombre(nomb);
    copyC.GetDistrito(dist);
    SetNombre(nomb);
    SetDistrito(dist);
}
//90367684,CORONEL CHUMPITAZ HELI,Villa Maria del Triunfo,S,13.04%
//66039166,LAURA WONG MELVIN HENRRY,Rimac,N
bool operator >>(ifstream &arch, class Cliente &cli){
    int dni;
    char *nomb, *dist, tieneDesc;
    double desc=0.0;
    
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    nomb = leeCadenaExacta(arch,60,',');
    dist = leeCadenaExacta(arch,40,',');
    arch>>tieneDesc;
    arch.get();
    if(tieneDesc == 'S'){
        arch>>desc;
        arch.get();
    }
    cli.SetDni(dni);
    cli.SetNombre(nomb);
    cli.SetDistrito(dist);
    cli.SetDescuento(desc);
    
    return true;
}

void operator <<(ofstream &arch, class Cliente &cli){
    char nombre[60], dist[40];
    cli.GetNombre(nombre);
    cli.GetDistrito(dist);
    arch<<left<<setw(10)<<cli.GetDni()<<setw(50)<<nombre<<setw(35)<<dist
        <<right<<setw(10)<<cli.GetDescuento()<<'%'<<setw(15)<<cli.GetTotalPagado()<<endl;
    
}