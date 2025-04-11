/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 26 de marzo de 2024, 13:54
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
79464412,PORTUGAL RAFFO ALEXANDER,3902394
16552775,YALLICO PAREDES LOURDES CARMELA,960176666
*/
bool operator >>(ifstream &archCli,struct Cliente &cli){
    //archCli>>cli;
    archCli>>cli.dni;
    if(archCli.eof()) return false;
    archCli.get();
    archCli.getline(cli.nombre,50,',');
    archCli>>cli.telefono;
    cli.cantidadProductosEntrgados = 0;
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
    ped.precioProducto = 0;
    return true;
}
/*
//Agregar precio
int retornarPrecio(struct Producto *arrProd,char *codigo){
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProd[i].codigo,codigo)==0) 
            return arrProd[i].precio;
}
*/
//Agregacion
void operator +=(struct Cliente *arrCli,const struct Pedido &ped){
    //arrCli += ped;
    int i,cantProd;
    struct ProductoEntregado aux;
    for(i=0;arrCli[i].dni!=0;i++)
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
    int cantCliServ,cantCliNoServ;
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProd[i].codigo,ped.CodigoProducto)==0){
            if(arrProd[i].stock>0){
                //Se puede servir al cliente
                cantCliServ = arrProd[i].cantidadClientesServidos;
                arrProd[i].clientesServidos[cantCliServ] = ped.dniCliente;
                arrProd[i].cantidadClientesServidos++;
                arrProd[i].stock--;
                return true;    //Hay stock disponible
            }else{
                cantCliNoServ = arrProd[i].cantidadClientesNoServidos;
                arrProd[i].clientesNoServidos[cantCliNoServ] = ped.dniCliente;
                arrProd[i].cantidadClientesNoServidos++;
                return false;   //No hay stock disponible
            }
        }
    return false;   //El producto no se encontró
}
//Impresion
void operator <<(ofstream &archRepCli,const struct Cliente cli){
    archRepCli<<fixed<<setprecision(2);
    archRepCli<<right<<setw(10)<<cli.dni<<setw(40)<<cli.nombre<<setw(12)
            <<cli.telefono<<setw(12)<<cli.montoTotal<<" Productos entregados: ";
    if(cli.cantidadProductosEntrgados>0){
        for(int i=0;i<cli.cantidadProductosEntrgados;i++)
            archRepCli<<right<<setw(8)<<cli.productosEntregados[i].codigo;
        archRepCli<<endl;
    }else archRepCli<<" NO SE LE ENTREGARON PRODUCTOS"<<endl;
}
void operator <<(ofstream &archRepProd,const struct Producto prod){
    archRepProd<<fixed<<setprecision(2);
    archRepProd<<left<<setw(40)<<prod.descripcion<<setw(12)<<prod.precio
            <<setw(5)<<prod.stock<<endl;
    archRepProd<<left<<setw(24)<<"Clientes atendidos:";
    if(prod.cantidadClientesServidos>0){
        for(int i=0;i<prod.cantidadClientesServidos;i++)
            archRepProd<<left<<setw(10)<<prod.clientesServidos[i];
        archRepProd<<endl;
    }else archRepProd<<"NO SE ATENDIERON PEDIDOS"<<endl;
    archRepProd<<left<<setw(24)<<"Clientes no atendidos:";
    if(prod.cantidadClientesNoServidos>0){
        for(int i=0;i<prod.cantidadClientesNoServidos;i++)
            archRepProd<<left<<setw(10)<<prod.clientesNoServidos[i];
        archRepProd<<endl;
    }else archRepProd<<"NO HAY CLIENTES SIN ATENDER"<<endl;
}