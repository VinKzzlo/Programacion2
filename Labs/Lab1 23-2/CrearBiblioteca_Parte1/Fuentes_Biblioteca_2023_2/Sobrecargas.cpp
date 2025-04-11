/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   Sobrecargas.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 21:45
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Estructuras.h"
#include "Sobrecargas.h"

//Sobrecargas de Lectura
bool operator >>(ifstream &archCli, struct Cliente &cliente){
    archCli>>cliente.dni;
    if(archCli.eof())return false;
    archCli.get();
    archCli.getline(cliente.nombre,60,',');
    archCli>>cliente.telefono;
    cliente.cantidadProductosEntrgados = 0;
    cliente.montoTotal = 0.0;
    return true;
}

bool operator >>(ifstream &archPro, struct Producto &producto){
    archPro.getline(producto.codigo,8,',');
    if(archPro.eof())return false;
    archPro.getline(producto.descripcion,60,',');
    archPro>>producto.precio;
    archPro.get();
    archPro>>producto.stock;
    archPro.get();
    
    producto.cantidadClientesServidos = 0;
    producto.cantidadClientesNoServidos = 0;
    return true;
}

bool operator >>(ifstream &archPed, struct Pedido &pedido){
    archPed.getline(pedido.CodigoProducto,8,',');
    if(archPed.eof()) return false;
    archPed>>pedido.dniCliente;
    archPed.get();
    pedido.precioProducto = 0.0;
    return true;
}

//Sobrecargas de Agregación
void operator +=(struct Cliente *arrClientes, struct Pedido &pedido){
    int n;
    for(int i=0;arrClientes[i].dni!=0;i++){
        if(pedido.dniCliente==arrClientes[i].dni){
            n = arrClientes[i].cantidadProductosEntrgados;
            strcpy(arrClientes[i].productosEntregados[n].codigo,
                   pedido.CodigoProducto);
            arrClientes[i].productosEntregados[n].precio = pedido.precioProducto;
            arrClientes[i].montoTotal += pedido.precioProducto;
            arrClientes[i].cantidadProductosEntrgados++;
            return;
        }
    }
}

bool operator +=(struct Producto *arrProd, struct Pedido &pedido){
    int ss, ns; //SiServidos, NoServidos
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++){
        if(strcmp(pedido.CodigoProducto,arrProd[i].codigo)==0){
            if(arrProd[i].stock>0){
                ss = arrProd[i].cantidadClientesServidos;
                arrProd[i].stock--;
                arrProd[i].clientesServidos[ss] = pedido.dniCliente;
                arrProd[i].cantidadClientesServidos++;
                return true;
            }
            else{
                ns = arrProd[i].cantidadClientesNoServidos;
                arrProd[i].clientesNoServidos[ns] = pedido.dniCliente;
                arrProd[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    }
    return false;
}

//Sobrecargas de Impresion
void operator <<(ofstream &archRep, const struct Cliente cliente){
    archRep.precision(2);
    archRep<<fixed;
    archRep<<right<<setw(10)<<cliente.dni<<setw(2)<<' '<<left
           <<setw(60)<<cliente.nombre<<right<<setw(11)<<cliente.telefono
           <<setw(12)<<cliente.montoTotal<<left<<"  Productos entregados: ";
    if(cliente.cantidadProductosEntrgados>0){
        for(int i=0;i<cliente.cantidadProductosEntrgados;i++){
            archRep<<setw(10)<<cliente.productosEntregados[i].codigo;
        }
        archRep<<endl;
    }
    else{
        archRep<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
    }
}

void operator <<(ofstream &archRep, const struct Producto producto){
    archRep.precision(2);
    archRep<<fixed;
    archRep<<left<<setw(10)<<producto.codigo<<setw(60)<<producto.descripcion
           <<right<<setw(4)<<' '<<setw(13)<<producto.precio
           <<setw(6)<<producto.stock<<endl;
    
    archRep<<left<<"Clientes atendidos: ";
    if(producto.cantidadClientesServidos>0){
        for(int i = 0 ; i<producto.cantidadClientesServidos ; i++)
            archRep<<right<<setw(10)<<producto.clientesServidos[i];
    }else archRep<<left<<"NO SE ATENDIERON PEDIDOS";
    archRep<<endl;
    
    archRep<<left<<"Clientes no atendidos: ";
    if(producto.cantidadClientesNoServidos>0){
        for(int i = 0 ; i<producto.cantidadClientesNoServidos ; i++)
            archRep<<right<<setw(10)<<producto.clientesNoServidos[i];
    }else archRep<<left<<"NO HAY CLIENTES SIN ATENDER";
    archRep<<endl;
    archRep<<endl;
}