/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 10 de abril de 2024, 02:10
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
//Parte A
void leerLibros(const char *nombArch,struct Libro *arrLib){
    ifstream archLib;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLib,nombArch);
    
    struct Libro lib;
    
    for(int i=0;i<300;i++){
        if(!(archLib>>lib)){
            strcpy(arrLib[i].codigo,"FIN");
            break;
        }
        arrLib[i] = lib;
    }
}
//Parte B
void leerClientes(const char *nombArch,struct Cliente *arrCli){
    ifstream archCli;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nombArch);
    
    struct Cliente cli;
    
    for(int i=0;i<100;i++){
        if(!(archCli>>cli)){
            arrCli[i].dni = 0;
            break;
        }
        arrCli[i] = cli;
    }
}
//Parte C
void leerPedidos(const char *nombArch,struct Libro *arrLib,
                 struct Cliente *arrCli){
    ifstream archPed;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    
    struct LibroSolicitado libPed;
    
    int dni,j,numPed;
    char c,codLib[8];
    while(1){
        archPed>>numPed;
        if(archPed.eof()) break;
        libPed.numeroDePedido = numPed;
        archPed>>c>>dni>>c;
        while(archPed>>codLib){
            strcpy(libPed.codigoDelLibro,codLib);
            libPed>>arrLib;
            for(j=0;arrCli[j].dni!=0;j++)
                if(arrCli[j].dni==dni){
                    arrCli[j]<<libPed;
                    break;
                }
            if(archPed.get()=='\n') break;
        }
    }
    
    for(int i=0;arrCli[i].dni!=0;i++) ++arrCli[i];
}
//Parte D
void imprimirReporte(const char *nombArch,const struct Libro *arrLib,
                     const struct Cliente *arrCli){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE LIBROS"<<endl;
    for(int i=0;strcmp(arrLib[i].codigo,"FIN")!=0;i++)
        archRep<<arrLib[i];
    archRep<<"REPORTE DE CLIENTES"<<endl;
    for(int i=0;arrCli[i].dni!=0;i++)
        archRep<<arrCli[i];
}