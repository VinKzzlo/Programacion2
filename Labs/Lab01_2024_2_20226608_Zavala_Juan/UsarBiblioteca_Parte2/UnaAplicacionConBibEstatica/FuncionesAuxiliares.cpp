/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ramir
 * 
 * Created on 9 de septiembre de 2024, 01:13 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
//Parte A
void leerPlatos(const char *nombArch,struct Plato *arrPlatos){
    ifstream archPla;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPla,nombArch);
    
    for(int i=0;i<150;i++){
        archPla>>arrPlatos[i];
        if(archPla.eof()){
            strcpy(arrPlatos[i].codigo,"FIN");
            break;
        }
    }
}
//Parte B
void leerRepartidores(const char *nombArch,struct Repartidor *arrRepartidores){
    ifstream archRpt;
    
    AperturaDeUnArchivoDeTextosParaLeer(archRpt,nombArch);
    
    for(int i=0;i<50;i++){
        archRpt>>arrRepartidores[i];
        if(archRpt.eof()){
            strcpy(arrRepartidores[i].codigo,"FIN");
            break;
        }
    }
}
//Parte C
/*
15290194  BR-283    1    MCE193    11.69
    80694546     BE-987    2    SRY667    1.01
*/
void leerPedidos(const char *nombArch,struct Plato *arrPlatos,
                                            struct Repartidor *arrRepartidores){
    ifstream archPed;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombArch);
    
    struct Pedido ped;
    
    while(1){
        archPed>>ped;
        if(archPed.eof()) break;
        ped<=arrPlatos;
        arrRepartidores<=ped;
    }
    for(int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++){
        for(int j=0;j<arrRepartidores[i].cantidadDeOrdenes;j++){
            !arrRepartidores[i].ordenesDeCompra[j];
        }
        !arrRepartidores[i];
    }
}
//Parte D
void imprimirReporte(const char *nombArch,const struct Plato *arrPlatos,
                                      const struct Repartidor *arrRepartidores){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<fixed<<setprecision(2);
    
    for(int i=0;strcmp(arrPlatos[i].codigo,"FIN")!=0;i++)
        archRep<<arrPlatos[i];
    for(int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++)
        archRep<<arrRepartidores[i];
}