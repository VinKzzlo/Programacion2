/* 
 * Archivo:   Almacen.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:47
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Almacen.h"
#include "Cliente.h"
#include "Funciones.h"

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::~Almacen() {
}

void Almacen::cargar_clientes() {
    ifstream arch("Clientes.csv",ios::in);
    while(true){
        if(arch>>arreglo_clientes[cantidad_clientes]==false) break;
        cantidad_clientes++;
    }
}

void Almacen::cargar_productos() {
    ifstream arch("Productos.csv",ios::in);
    while(true){
        if(arch>>arreglo_productos[cantidad_productos]==false) break;
        cantidad_productos++;
    }
}

void Almacen::cargar_pedidos() {
    ifstream arch("Pedidos.csv",ios::in);
    class Pedido ped;
    int indiceCli, indicePro;
    while(true){
        if(arch>>ped==false) break;
        indiceCli = buscarCliente(ped.GetDni_cliente());
        indicePro = buscarProducto(ped.GetCodigo());
        if(indiceCli!=-1 and indicePro!=-1){
            arreglo_productos[indicePro] += ped;
            arreglo_clientes[indiceCli] += ped;
        }
    }
}

int Almacen::buscarCliente(int dni) {
    for(int i=0;i<cantidad_clientes;i++)
        if(arreglo_clientes[i].GetDni()==dni) return i;
    return -1;
}

int Almacen::buscarProducto(char* codigo) {
    for(int i=0;i<cantidad_productos;i++)
        if(strcmp(arreglo_productos[i].GetCodigo(),codigo)==0) return i;
    return -1;
}

void Almacen::mostrar_datos() {
    ofstream arch("ReporteFinal.txt",ios::out);
    arch.precision(2);
    arch<<fixed;
    
    arch<<"LISTA DE CLIENTES: "<<endl;
    imprimeLinea(arch,'-',195);
    arch<<left<<setw(12)<<"DNI"<<setw(55)<<"NOMBRES Y APELLIDOS"
        <<setw(12)<<"TELEFONO"<<setw(10)<<"MONTO"
        <<setw(65)<<"LISTA DE PRODUCTOS:"<<endl;
    imprimeLinea(arch,'-',195);
    for(int i=0;i<cantidad_clientes;i++){
        arch<<arreglo_clientes[i];
        arch<<endl;
    }
    imprimeLinea(arch,'=',130);
    arch<<"LISTA DE PRODUCTOS: "<<endl;
    imprimeLinea(arch,'-',130);
    arch<<left<<setw(8)<<"Codigo"<<setw(50)<<"Descripcion"<<
            right<<setw(10)<<"Precio"<<setw(5)<<"Stock"<<endl;
    imprimeLinea(arch,'-',130);
    for(int i=0;i<cantidad_productos;i++)
        arch<<arreglo_productos[i];
    arch<<endl;
    
}
