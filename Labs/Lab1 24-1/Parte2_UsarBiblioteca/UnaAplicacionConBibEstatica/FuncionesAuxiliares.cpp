/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 18:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Sobrecargas.h"

void cargarLibros(const char *nombArch,struct Libro *arrLibros){
    ifstream archLib;
    int cantLib=0;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLib,nombArch);
    
    while(archLib>>arrLibros[cantLib])
        cantLib++;
    strcpy(arrLibros[cantLib].codigo,"FIN");
    
}

void cargarClientes(const char *nombArch,struct Cliente *arrClientes){
    ifstream archCli;
    int cantCli=0;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nombArch);
    while(archCli>>arrClientes[cantCli])
        cantCli++;
    arrClientes[cantCli].dni = 0; //identificador para
                                  //controlar la lectura del arreglo
}

void leerPedidos(const char *nombArch,
                 struct Libro *arrLibros,struct Cliente *arrClientes){
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    struct LibroSolicitado libroPed;
    int numPed, dni;
    char codLibro[8], c;
    while(true){
        archPed>>numPed;
        if(archPed.eof())break;
        archPed>>c>>dni>>c;
        libroPed.numeroDePedido = numPed;
        while(true){
            archPed>>codLibro;
            strcpy(libroPed.codigoDelLibro,codLibro);
            if(libroPed>>arrLibros){
                for(int i=0;arrClientes[i].dni!=0;i++){
                    if(arrClientes[i].dni==dni){
                        arrClientes[i]<<libroPed;
                        break;
                    }
                }
            }
            if(archPed.get()=='\n') break;
        }
    }
    
}
void imprimirReporte(const char *nombArch, const struct Libro *arrLibros,
                     const struct Cliente *arrClientes){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE LIBROS - STOCK FINAL"<<endl;
    for(int i=0;strcmp(arrLibros[i].codigo,"FIN")!=0;i++)
        archRep<<arrLibros[i];
    archRep<<endl<<"REPORTE DE CLIENTES"<<endl;
    for(int i=0;arrClientes[i].dni!=0;i++)
        archRep<<arrClientes[i];
}