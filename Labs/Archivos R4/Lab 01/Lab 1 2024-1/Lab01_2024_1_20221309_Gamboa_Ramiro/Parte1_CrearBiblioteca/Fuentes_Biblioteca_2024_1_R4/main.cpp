/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 10 de abril de 2024, 00:16
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
    
    ifstream archLib,archCli,archPed;
    ofstream archRepLib,archRepCli;
    
    AperturaDeUnArchivoDeTextosParaLeer(archLib,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepLib,"ReporteLibros.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli,"ReporteClientes.txt");
    
    struct Libro arrLib[300],lib;
    struct Cliente arrCli[100],cli;
    struct LibroSolicitado libPed;
    
    for(int i=0;i<300;i++){
        if(!(archLib>>lib)){
            strcpy(arrLib[i].codigo,"FIN");
            break;
        }
        arrLib[i] = lib;
    }
    for(int i=0;i<100;i++){
        if(!(archCli>>cli)){
            arrCli[i].dni = 0;
            break;
        }
        arrCli[i] = cli;
    }
    /*
    000001,34460612,  CRY6839    VYG3594
    000006,69200503,  CPE5718  KGO1734  IUG2294   ILG7766
    */
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
    
    for(int i=0;strcmp(arrLib[i].codigo,"FIN")!=0;i++)
        archRepLib<<arrLib[i];
    for(int i=0;arrCli[i].dni!=0;i++)
        archRepCli<<arrCli[i];
    
    return 0;
}