/* 
 * Archivo:   Plato.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 20:36
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Plato.h"
#include "FuncionesAux.h"
#include "Cliente.h"

Plato::Plato() {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    atendidos = 0;
    noAtendidos = 0;
    totalEsperado = 0.0;
    totalBruto = 0.0;
    totalNeto = 0.0;
}

Plato::Plato(const Plato& orig) {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    *this = orig;
}

Plato::~Plato() {
    if(codigo!=nullptr) delete codigo;
    if(nombre!=nullptr) delete nombre;
    if(categoria!=nullptr) delete categoria;
}

void Plato::SetTotalNeto(double totalNeto) {
    this->totalNeto = totalNeto;
}

double Plato::GetTotalNeto() const {
    return totalNeto;
}

void Plato::SetTotalBruto(double totalBruto) {
    this->totalBruto = totalBruto;
}

double Plato::GetTotalBruto() const {
    return totalBruto;
}

void Plato::SetTotalEsperado(double totalEsperado) {
    this->totalEsperado = totalEsperado;
}

double Plato::GetTotalEsperado() const {
    return totalEsperado;
}

void Plato::SetNoAtendidos(int noAtendidos) {
    this->noAtendidos = noAtendidos;
}

int Plato::GetNoAtendidos() const {
    return noAtendidos;
}

void Plato::SetAtendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::GetAtendidos() const {
    return atendidos;
}

void Plato::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Plato::GetDescuento() const {
    return descuento;
}

void Plato::SetPreparados(int preparados) {
    this->preparados = preparados;
}

int Plato::GetPreparados() const {
    return preparados;
}

void Plato::SetCategoria(char* cat) {
    if(categoria != nullptr) delete categoria;
    categoria = new char[strlen(cat)+1];
    strcpy(categoria,cat);
}

void Plato::GetCategoria(char *cad) const {
    if(categoria==nullptr) cad[0] = 0;
    strcpy(cad,categoria);
}

void Plato::SetPrecio(double prec) {
    this->precio = prec;
}

double Plato::GetPrecio() const {
    return precio;
}

void Plato::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Plato::GetNombre(char* cad) const {
    if(nombre==nullptr) cad[0] = 0;
    strcpy(cad,nombre);
}

void Plato::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Plato::GetCodigo(char* cad) const {
    if(codigo==nullptr) cad[0] = 0;
    strcpy(cad,codigo);
}


//    double precio;
//    int preparados;
//    double descuento;
//    int atendidos;
//    int noAtendidos;
//    double totalEsperado;
//    double totalBruto;
//    double totalNeto;
void Plato::operator=(const class Plato &plat) {
    preparados = plat.GetPreparados();
    atendidos = plat.GetAtendidos();
    noAtendidos = plat.GetNoAtendidos();
    descuento = plat.GetDescuento();
    precio = plat.GetPrecio();
    char cod[8], nomb[60], cat[20];
    plat.GetCodigo(cod);
    plat.GetNombre(nomb);
    plat.GetCategoria(cat);
    SetCodigo(cod);
    SetNombre(nomb);
    SetCategoria(cat);
}
//BR15142,1/2 POLLO BBQ/HOT A LO BRAVO,52.90,BRASA,72,7.47%
//BR15142,1/2 POLLO BBQ/HOT A LO BRAVO,52.90,BRASA,72
bool operator >>(ifstream &arch,class Plato &plat){
    
    char *cod, *nomb, *cat;
    int cantPreparados;
    double precio, desc=0.0;
    
    cod = leeCadenaExacta(arch,8,',');
    if(arch.eof()) return false;
    nomb = leeCadenaExacta(arch,60,',');
    arch>>precio;
    arch.get();
    cat = leeCadenaExacta(arch,20,',');
    arch>>cantPreparados;
    if(arch.get()!='\n'){
        desc = arch.get();
        while(arch.get()!='\n');
    }
    
    plat.SetCodigo(cod);
    plat.SetNombre(nomb);
    plat.SetCategoria(cat);
    plat.SetPreparados(cantPreparados);
    plat.SetPrecio(precio);
    plat.SetDescuento(desc);    
    return true;
}

void Plato::actualiza(int cantidad, class Cliente &cli) {
    double desCli, desPla, costoPed, monto;
    SetTotalEsperado(preparados*precio);
    desCli = cli.GetDescuento();
    desPla = GetDescuento();
    
    if(preparados-atendidos-cantidad>=0){
        monto = cantidad*precio;
        totalBruto +=monto;
        atendidos += cantidad;
        costoPed = (monto) - (monto*desCli/100) - (monto*desPla/100);
        totalNeto += costoPed;
        cli.SetTotalPagado(costoPed);
    }
    else{
        noAtendidos += cantidad;
    }
    
}


void operator <<(ofstream &arch,class Plato &plat){
    char cod[8], nomb[60], cat[20];
    plat.GetCodigo(cod);
    plat.GetNombre(nomb);
    plat.GetCategoria(cat);
    
    arch<<left<<setw(10)<<cod<<setw(60)<<nomb<<right<<setw(10)<<plat.GetPrecio()
        <<setw(15)<<cat<<setw(10)<<plat.GetDescuento()<<'%'<<setw(10)<<plat.GetPreparados()
        <<setw(10)<<plat.GetAtendidos()<<setw(10)<<plat.GetNoAtendidos()
        <<setw(10)<<plat.GetTotalEsperado()
        <<setw(10)<<plat.GetTotalBruto()<<setw(10)<<plat.GetTotalNeto()<<endl;
    
}