/* 
 * Archivo:   Restaurante.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 21:28
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Restaurante.h"
#include "FuncionesAux.h"
#define NOT_FOUND -1

Restaurante::Restaurante() {
    clientes = nullptr;
    platos = nullptr;
    cantidadDeClientes=0;
    cantidadDePlatos=0;
}

Restaurante::~Restaurante() {
    if(clientes != nullptr) delete [] clientes;
    if(platos != nullptr) delete [] platos;
}

void Restaurante::operator<(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    class Cliente buffClientes[120];
    while(arch>>buffClientes[cantidadDeClientes])
        cantidadDeClientes++;
    clientes = new class Cliente[cantidadDeClientes+1];
    for(int i=0;i<cantidadDeClientes;i++){
        clientes[i] = buffClientes[i];
    }
}

void Restaurante::operator<=(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    class Plato buffPlatos[120];
    while(arch>>buffPlatos[cantidadDePlatos])
        cantidadDePlatos++;
    platos = new class Plato[cantidadDePlatos+1];
    for(int i=0;i<cantidadDePlatos;i++){
        platos[i] = buffPlatos[i];
    }
}

void Restaurante::operator<<=(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int numPed, dniCli, cant, posCli, posPla;
    char codPla[8];
    
    while(true){
        arch>>numPed;
        if(arch.eof())break;
        arch.get();
        arch>>dniCli;
        while(true){
            if(arch.get()=='\n')break;
            arch.getline(codPla,8,',');
            arch>>cant;
            posCli = buscaCliente(dniCli);
            posPla = buscaPlato(codPla);
            if(posCli != NOT_FOUND and posPla != NOT_FOUND){
                platos[posPla].actualiza(cant,clientes[posCli]);
//                platos[posPla] += clientes[posCli];
            }
        }
    }
    
    
}

int Restaurante::buscaCliente(int dniCli) {
    for(int i=0;i<cantidadDeClientes;i++)
        if(clientes[i].GetDni()==dniCli) return i;
    return NOT_FOUND;
}

int Restaurante::buscaPlato(char* codPla) {
    char cod[8];
    for(int i=0;i<cantidadDePlatos;i++){
        platos[i].GetCodigo(cod);
        if(strcmp(cod,codPla)==0) return i;
    }
    return NOT_FOUND;
}

void Restaurante::operator>>(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    
    arch<<setw(92)<<"RESTAURANTE 1INF25"<<endl;
    arch<<setw(90)<<"VENTAS DEL DIA"<<endl;
    imprimeLinea(arch,166,'=');
    arch<<setw(96)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimeLinea(arch,166,'-');
    arch<<left<<setw(10)<<"CODIGO"<<setw(64)<<"NOMBRE"<<setw(11)<<"PRECIO"
        <<setw(14)<<"CATEGORIA"<<setw(10)<<"DESCUENTO"<<setw(12)<<"PREPARADOS"
        <<setw(10)<<"ATENDIDOS"<<setw(8)<<"NOATEN"<<setw(10)<<"ESPERADO"
        <<setw(10)<<"BRUTO"<<"NETO"<<endl;
    imprimeLinea(arch,166,'-');
    for(int i=0;i<cantidadDePlatos;i++)
        arch<<platos[i];
    imprimeLinea(arch,166,'=');
    arch<<setw(97)<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    arch<<left<<setw(10)<<"CODIGO"<<setw(50)<<"NOMBRE"<<setw(40)<<"DISTRITO"
        <<setw(11)<<"DESCUENTO"<<"TOTAL PAGADO"<<endl;
    imprimeLinea(arch,166,'-');
    for(int i=0;i<cantidadDeClientes;i++)
        arch<<clientes[i];
    arch<<endl;
    
    
}
