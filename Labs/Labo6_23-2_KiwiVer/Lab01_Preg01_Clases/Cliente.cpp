/* 
 * Archivo:   Cliente.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Cliente.h"
#include "Funciones.h"

Cliente::Cliente() {
    nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0.0;
}

Cliente::~Cliente() {
    if(nombre != nullptr)
        delete [] nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

ProductoEntregado *Cliente::GetProductos_entregados() {
    return productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char* Cliente::GetNombre() const {
    char *copiaNom=new char[strlen(nombre)+1];
    strcpy(copiaNom,nombre);
    return copiaNom;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator>>(ifstream &arch,class Cliente &cli){
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394
    int dni, telefono;
    char *nombre;
    
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    nombre = leeCadena(arch,60,',');
    arch>>telefono;
    
    cli.SetDni(dni);
    cli.SetNombre(nombre);
    cli.SetTelefono(telefono);
    return true;
}

void Cliente::operator+=(Pedido& ped) {
    ProductoEntregado prod;
    prod.SetCodigo(ped.GetCodigo());
    prod.SetPrecio(ped.GetPrecio_producto());
    
    int n = cantidad_productos_entregados;
    productos_entregados[n] = prod;
    cantidad_productos_entregados++;
    monto_total += ped.GetPrecio_producto();
}

//
void operator<<(ofstream &arch,class Cliente &cli){
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<cli.GetDni()<<setw(3)<<' '<<setw(50)<<cli.GetNombre()
        <<right<<setw(12)<<cli.GetTelefono()<<setw(10)<<cli.GetMonto_total();
    if(cli.GetCantidad_productos_entregados()==0){
        arch<<"  NO SE LE ENTREGARON PRODUCTOS"<<endl;
    }else{
        class ProductoEntregado *prods = cli.GetProductos_entregados(); 
       for(int i=0;i<cli.GetCantidad_productos_entregados();i++){
            arch<<"  "<<left<<setw(10)<<prods[i].GetCodigo();
        }
    }
}