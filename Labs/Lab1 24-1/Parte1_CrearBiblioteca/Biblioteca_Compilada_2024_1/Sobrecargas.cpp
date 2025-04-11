/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   Sobrecargas.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 3 de septiembre de 2024, 17:37
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "Sobrecargas.h"


bool operator >>(ifstream &archLib, struct Libro &libro){
    archLib.getline(libro.codigo,8,',');
    if(archLib.eof()) return false;
    archLib.getline(libro.tiltulo,80,',');
    archLib.getline(libro.autor,60,',');
    archLib>>libro.stock;
    archLib.get();
    archLib>>libro.precio;
    archLib.get();
    return true;
}

bool operator >>(ifstream &archCli, struct Cliente &cliente){
    archCli>>cliente.dni;
    if(archCli.eof())return false;
    archCli.get();
    archCli.getline(cliente.nombre,60);
    cliente.cantDeLibros = 0;
    cliente.pagoTotal = 0.0;
    return true;
}

bool operator >>(struct LibroSolicitado &libroPedido, struct Libro *arrLib){
    for(int i=0;strcmp(arrLib[i].codigo,"FIN")!=0;i++){
        if(strcmp(libroPedido.codigoDelLibro,arrLib[i].codigo)==0){
            if(arrLib[i].stock>0){
                arrLib[i].stock--;
                libroPedido.precio = arrLib[i].precio;
                libroPedido.atendido = true;
                return true;
            }
            else{
                libroPedido.atendido = false;
                return false;
            }
        }
    }
    return false;
}

bool operator <<(struct Cliente &cli, struct LibroSolicitado libPed){
    if(cli.cantDeLibros<30){
        cli.librosSolicitados[cli.cantDeLibros] = libPed;
        cli.cantDeLibros++;
        return true;
    }
    else{
        return false;
    }
}

void operator ++(struct Cliente &cli){
    for(int i=0;i<cli.cantDeLibros;i++){
        cli.pagoTotal += cli.librosSolicitados[i].precio;
    }
}

void operator <<(ofstream &arch,const struct Libro lib){
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<lib.codigo<<setw(80)<<lib.tiltulo<<setw(60)<<lib.autor
        <<right<<setw(6)<<lib.stock<<setw(10)<<lib.precio<<endl;
}

void operator <<(ofstream &arch, const struct Cliente cliente){
    arch.precision(2);
    arch<<fixed;
    arch<<setw(10)<<cliente.dni<<setw(4)<<' '<<left<<setw(60)<<cliente.nombre<<endl;
    arch<<setw(2)<<' '<<"Libros entregados"<<endl;
    arch<<setw(10)<<' '<<setw(14)<<"Pedido No."<<setw(11)<<"Codigo"<<"Precio"<<endl;
    for(int i=0;i<cliente.cantDeLibros;i++){
        if(cliente.librosSolicitados[i].atendido){
            arch<<setw(12)<<' '<<setfill('0')<<right<<setw(5)
                <<cliente.librosSolicitados[i].numeroDePedido<<setfill(' ')
                <<setw(7)<<' '<<left<<setw(10)<<cliente.librosSolicitados[i].codigoDelLibro
                <<right<<setw(7)<<cliente.librosSolicitados[i].precio<<endl;
        }
    }
    arch<<left<<"Total a pagar: "<<cliente.pagoTotal<<endl;
    arch<<setw(2)<<' '<<"Libros no entregados por falta de stock: "<<endl;
    arch<<setw(10)<<' '<<setw(14)<<"Pedido No."<<setw(11)<<"Codigo"<<endl;
    for(int i=0;i<cliente.cantDeLibros;i++){
        if(not cliente.librosSolicitados[i].atendido){
            arch<<setw(12)<<' '<<setfill('0')<<right<<setw(5)
                <<cliente.librosSolicitados[i].numeroDePedido<<setfill(' ')
                <<setw(7)<<' '<<left
                <<setw(10)<<cliente.librosSolicitados[i].codigoDelLibro<<endl;
        }
    }
}