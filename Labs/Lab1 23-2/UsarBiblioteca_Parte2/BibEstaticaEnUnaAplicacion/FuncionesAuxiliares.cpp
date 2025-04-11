/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 23:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"
#include "FuncionesAuxiliares.h"
#define NOT_FOUND -1

void cargarClientes(const char *nombArch,struct Cliente *arrClientes){
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nombArch);
    int cantCli=0;
    
    while(archCli>>arrClientes[cantCli]) cantCli++;
    arrClientes[cantCli].dni = 0;
}

void cargarProductos(const char *nombArch,struct Producto *arrProductos){
    ifstream archProd;
    AperturaDeUnArchivoDeTextosParaLeer(archProd,nombArch);
    int cantProd=0;
    
    while(archProd>>arrProductos[cantProd]) cantProd++;
    strcpy(arrProductos[cantProd].codigo,"XXXXXXX");
}

void actualizarPedidos(const char *nombArch,struct Cliente *arrClientes,
                       struct Producto *arrProductos){
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    
    struct Pedido pedido;
    while(archPed>>pedido){
        pedido.precioProducto = agregarPrecios(pedido,arrProductos);
        if(pedido.precioProducto != NOT_FOUND){
            arrClientes += pedido;
            arrProductos += pedido;
        }
        
    }
    
}

double agregarPrecios(struct Pedido &pedido,struct Producto *arrProductos){
    for(int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProductos[i].codigo,pedido.CodigoProducto)==0)
            return arrProductos[i].precio;
    return NOT_FOUND;
}


void imprimirReporte(const char *nombArch, struct Cliente *arrClientes,
                      struct Producto *arrProductos){
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE CLIENTES"<<endl;
    for(int i=0;arrClientes[i].dni!=0;i++)
        archRep<<arrClientes[i];
    archRep<<endl<<"REPORTE DE PRODUCTOS"<<endl;
    for(int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX")!=0;i++)
        archRep<<arrProductos[i];
}