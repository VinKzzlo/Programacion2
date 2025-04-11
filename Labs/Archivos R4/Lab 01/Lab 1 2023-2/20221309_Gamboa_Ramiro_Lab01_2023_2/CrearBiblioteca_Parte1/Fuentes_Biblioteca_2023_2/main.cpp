/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 26 de marzo de 2024, 13:53
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
int main(int argc, char** argv) {

    ifstream archCli,archProd,archPed;
    ofstream archRepCli,archRepProd;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProd,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli,"ReporteClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepProd,"ReporteProductos.txt");
    
    struct Cliente arrCli[150],cli;
    struct Producto arrProd[200],prod;
    struct Pedido ped;
    for(int i=0;i<150;i++){
        if(!(archCli>>cli)){
            arrCli[i].dni = 0;
            break;
        }
        arrCli[i] = cli;
    }
    for(int j=0;j<200;j++){
        if(!(archProd>>prod)){
            strcpy(arrProd[j].codigo,"XXXXXXX");
            break;
        }
        arrProd[j] = prod;
    }
    while(1){
        if(!(archPed>>ped)) break;
        arrProd += ped;
        
        arrCli += ped;
    }
    
    for(int i=0;arrCli[i].dni!=0;i++)
        archRepCli<<arrCli[i];
    for(int j=0;strcmp(arrProd[j].codigo,"XXXXXXX")!=0;j++)
        archRepProd<<arrProd[j];
    
    return 0;
}

