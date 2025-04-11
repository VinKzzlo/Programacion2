/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 9 de septiembre de 2024, 01:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
int main(int argc, char** argv) {
    
    ifstream archPla,archRpt,archPed;
    ofstream archRepPla,archRepRpt;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPla,"PlatosOfrecidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archRpt,"RepartidoresContratados.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"OrdenesDeCompra.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepPla,"ReportePlatos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepRpt,"ReporteRepartidores.txt");
    
    struct Plato arrPlatos[150]{},plato;
    struct Repartidor arrRepartidores[50]{},repar;
    struct Pedido ped;
    
    for(int i=0;i<150;i++){
        archPla>>arrPlatos[i];
        if(archPla.eof()){
            strcpy(arrPlatos[i].codigo,"FIN");
            break;
        }
    }
    
    for(int i=0;i<50;i++){
        archRpt>>arrRepartidores[i];
        if(archRpt.eof()){
            strcpy(arrRepartidores[i].codigo,"FIN");
            break;
        }
    }
    
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
    
    for(int i=0;strcmp(arrPlatos[i].codigo,"FIN")!=0;i++)
        archRepPla<<arrPlatos[i];
    for(int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++)
        archRepRpt<<arrRepartidores[i];
    
    return 0;
}

