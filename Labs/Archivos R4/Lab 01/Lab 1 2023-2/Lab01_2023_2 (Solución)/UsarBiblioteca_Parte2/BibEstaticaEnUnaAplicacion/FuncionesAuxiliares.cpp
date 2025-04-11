/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ramir
 * 
 * Created on 4 de abril de 2024, 17:04
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"
#define NO_ENCONTRADO -1
//Parte A
void leerClientes(struct Cliente *arrCli,const char *nombArch){
    ifstream archCli;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nombArch);
    
    struct Cliente cli;
    
    for(int i=0;i<150;i++){
        if(!(archCli>>cli)){
            arrCli[i].dni = 0;
            break;
        }
        arrCli[i] = cli;
    }
}
//Parte B
void leerProductos(struct Producto *arrProd,const char *nombArch){
    ifstream archProd;
    
    AperturaDeUnArchivoDeTextosParaLeer(archProd,nombArch);
    
    struct Producto prod;
    
    for(int i=0;i<200;i++){
        if(!(archProd>>prod)){
            strcpy(arrProd[i].codigo,"XXXXXXX");
            break;
        }
        arrProd[i] = prod;
    }
}
//Parte C
void completarPedidos(struct Cliente *arrCli,struct Producto *arrProd,
                      const char *nombArch){
    ifstream archPed;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    
    struct Pedido ped;
    
    while(1){
        if(!(archPed>>ped)) break;
        ped.precioProducto = agregarPrecios(ped,arrProd);
        if(ped.precioProducto!=NO_ENCONTRADO){
            arrCli += ped;
            arrProd += ped;
        }
    }
}

double agregarPrecios(struct Pedido &ped,struct Producto *arrProd){
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProd[i].codigo,ped.CodigoProducto)==0) 
            return arrProd[i].precio;
    return NO_ENCONTRADO;
}
//Parte D
void imprimirReporte(struct Cliente *arrCli,struct Producto *arrProd,
                     const char *nombArch){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE CLIENTES"<<endl;
    for(int i=0;arrCli[i].dni!=0;i++)
        archRep<<arrCli[i];
    archRep<<"REPORTE DE PRODUCTOS"<<endl;
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        archRep<<arrProd[i];
}