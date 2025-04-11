/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ramir
 * 
 * Created on 1 de abril de 2024, 22:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
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
void leerPedidosYCompletar(struct Cliente *arrCli,struct Producto *arrProd,
                           const char *nombArch){
    ifstream archPed;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    
    struct Pedido ped;
    
    while(1){
        if(!(archPed>>ped)) break;
        ped.precioProducto = retornarPrecio(arrProd,ped.CodigoProducto);
        arrCli += ped;
        arrProd += ped;
    }
}
double retornarPrecio(struct Producto *arrProd,char *codigo){
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        if(strcmp(arrProd[i].codigo,codigo)==0) 
            return arrProd[i].precio;
}
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