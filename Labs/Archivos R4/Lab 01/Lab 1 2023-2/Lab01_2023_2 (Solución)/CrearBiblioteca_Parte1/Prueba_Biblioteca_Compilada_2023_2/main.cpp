/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de abril de 2024, 16:56
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
    for(int i=0;i<200;i++){
        if(!(archProd>>prod)){
            strcpy(arrProd[i].codigo,"XXXXXXX");
            break;
        }
        arrProd[i] = prod;
    }
    while(1){
        if(!(archPed>>ped)) break;
        arrProd += ped;
        arrCli += ped;
    }
    for(int i=0;arrCli[i].dni!=0;i++)
        archRepCli<<arrCli[i];
    for(int i=0;strcmp(arrProd[i].codigo,"XXXXXXX")!=0;i++)
        archRepProd<<arrProd[i];
    
    return 0;
}
