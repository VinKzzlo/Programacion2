/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 4 de abril de 2024, 15:51
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
//Lectura
/*
99842319,MARTINEZ MARTINEZ CARMELA,5042430
98140264,ALAMO ZEGARRA ISRAEL GUSTAVO,990418360
*/
bool operator >>(ifstream &archCli,struct Cliente &cli){
    //archCli>>cli;
    archCli>>cli.dni;
    if(archCli.eof()) return false;
    archCli.get();
    archCli.getline(cli.nombre,60,',');
    archCli>>cli.telefono;
    cli.cantidadProductosEntrgados = 0;
    cli.montoTotal = 0.0;
    return true;
}
/*
BIT-434,Campana Extractora modelo Glass,375.09,10
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,3
*/
bool operator >>(ifstream &archProd,struct Producto &prod){
    //archProd>>prod;
    char c;
    archProd.getline(prod.codigo,8,',');
    if(archProd.eof()) return false;
    archProd.getline(prod.descripcion,60,',');
    archProd>>prod.precio>>c>>prod.stock;
    archProd.get();
    prod.cantidadClientesNoServidos = 0;
    prod.cantidadClientesServidos = 0;
    return true;
}
/*
JXD-139,50375303
CRU-009,50375303
*/
bool operator >>(ifstream &archPed,struct Pedido &ped){
    //archPed>>ped;
    archPed.getline(ped.CodigoProducto,8,',');
    if(archPed.eof()) return false;
    archPed>>ped.dniCliente;
    archPed.get();
    ped.precioProducto = 0.0;
    return true;
}
//Agregacion
void operator +=(struct Cliente *arrCli,const struct Pedido ped){
    //arrCli += ped;
    int cantProd;
    struct ProductoEntregado aux;
    for(int i=0;arrCli[i].dni!=0;i++)
        if(arrCli[i].dni==ped.dniCliente){
            cantProd = arrCli[i].cantidadProductosEntrgados;
            strcpy(aux.codigo,ped.CodigoProducto);
            aux.precio = ped.precioProducto;
            arrCli[i].productosEntregados[cantProd] = aux;
            arrCli[i].montoTotal += ped.precioProducto;
            arrCli[i].cantidadProductosEntrgados++;
        }
}

bool operator +=(struct Producto *arrProd,struct Pedido &ped){
    //arrProd += ped;
    int cantServ,cantNoServ;
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProd[i].codigo,ped.CodigoProducto)==0){
            if(arrProd[i].stock>0){
                cantServ = arrProd[i].cantidadClientesServidos;
                arrProd[i].clientesServidos[cantServ] = ped.dniCliente;
                arrProd[i].cantidadClientesServidos++;
                arrProd[i].stock--;
                return true;
            }else{
                cantNoServ = arrProd[i].cantidadClientesNoServidos;
                arrProd[i].clientesNoServidos[cantNoServ] = ped.dniCliente;
                arrProd[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    return false;
}
//Impresion
void operator <<(ofstream &archRepCli,const struct Cliente cli){
    archRepCli<<fixed<<setprecision(2);
    archRepCli<<right<<cli.dni<<setw(40)<<cli.nombre<<setw(10)<<cli.telefono
            <<setw(10)<<cli.montoTotal<<" Productos entregados: ";
    if(cli.cantidadProductosEntrgados>0){
        for(int i=0;i<cli.cantidadProductosEntrgados;i++)
            archRepCli<<left<<setw(10)<<cli.productosEntregados[i].codigo;
    }else archRepCli<<"NO SE LE ENTREGARON PRODUCTOS";
    archRepCli<<endl;
}

void operator <<(ofstream &archRepProd,const struct Producto prod){
    archRepProd<<fixed<<setprecision(2);
    archRepProd<<left<<prod.codigo<<" "<<setw(60)<<prod.descripcion<<setw(10)
            <<prod.precio<<setw(10)<<prod.stock<<endl;
    archRepProd<<left<<setw(25)<<"Clientes atendidos:";
    if(prod.cantidadClientesServidos>0){
        for(int i=0;i<prod.cantidadClientesServidos;i++)
            archRepProd<<left<<setw(11)<<prod.clientesServidos[i];
    }else archRepProd<<"NO SE ATENDIERON PEDIDOS";
    archRepProd<<endl;
    archRepProd<<left<<setw(25)<<"Clientes no atendidos:";
    if(prod.cantidadClientesNoServidos>0){
        for(int i=0;i<prod.cantidadClientesNoServidos;i++)
            archRepProd<<left<<setw(11)<<prod.clientesNoServidos[i];
    }else archRepProd<<"NO HAY CLIENTES SIN ATENDER";
    archRepProd<<endl;
}