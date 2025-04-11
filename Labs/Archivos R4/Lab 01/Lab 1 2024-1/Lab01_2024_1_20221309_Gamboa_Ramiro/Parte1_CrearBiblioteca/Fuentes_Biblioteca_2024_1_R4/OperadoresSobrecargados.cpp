/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 10 de abril de 2024, 00:18
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
//Lectura
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
bool operator >>(ifstream &archLib,struct Libro &lib){
    //archLib>>lib;
    char c;
    archLib.getline(lib.codigo,8,',');
    if(archLib.eof()) return false;
    archLib.getline(lib.tiltulo,80,',');
    archLib.getline(lib.autor,60,',');
    archLib>>lib.stock>>c>>lib.precio;
    archLib.get();
    return true;
}
/*
54393647,Reyes Tang Edward 
67066631,Arca Amezquita Edric Ronald
*/
bool operator >>(ifstream &archCli,struct Cliente &cli){
    //archCli>>cli;
    archCli>>cli.dni;
    if(archCli.eof()) return false;
    archCli.get();
    archCli.getline(cli.nombre,60);
    cli.cantDeLibros = 0;
    cli.pagoTotal = 0.0;
    return true;
}
//Agregacion
bool operator >>(struct LibroSolicitado &libPed,struct Libro *arrLib){
    //libPed>>arrLib;
    for(int i=0;strcmp(arrLib[i].codigo,"FIN")!=0;i++){
        if(strcmp(arrLib[i].codigo,libPed.codigoDelLibro)==0){
            if(arrLib[i].stock>0){
                libPed.atendido = true;
                libPed.precio = arrLib[i].precio;
                arrLib[i].stock--;
                return true;
            }else{
                libPed.atendido = false;
                return false;
            }
        }
    }
    return false;
}

bool operator <<(struct Cliente &cli,const struct LibroSolicitado libPed){
    //cli<<libPed;
    int cantLib;
    if(cli.cantDeLibros<30){
        cantLib = cli.cantDeLibros;
        cli.librosSolicitados[cantLib] = libPed;
        cli.cantDeLibros++;
        return true;
    }else{
        return false;
    }
}

void operator ++(struct Cliente &cli){
    for(int i=0;i<cli.cantDeLibros;i++)
        cli.pagoTotal += cli.librosSolicitados[i].precio;
}
//Impresion
void operator <<(ofstream &archRepLib,const struct Libro lib){
    //archRepLib<<lib;
    archRepLib<<fixed<<setprecision(2);
    archRepLib<<left<<setw(10)<<lib.codigo<<setw(60)<<lib.tiltulo<<setw(40)
            <<lib.autor<<right<<setw(5)<<lib.stock<<setw(10)<<lib.precio<<endl;
}

void operator <<(ofstream &archRepCli,const struct Cliente cli){
    //archRepCli<<cli;
    archRepCli<<fixed<<setprecision(2);
    archRepCli<<left<<setw(10)<<cli.dni<<setw(60)<<cli.nombre<<endl;
    archRepCli<<"Libros entregados:"<<endl;
    archRepCli<<right<<setw(20)<<"Pedido No."<<setw(10)<<"Codigo"<<setw(10)
            <<"Precio"<<endl;
    for(int i=0;i<cli.cantDeLibros;i++){
        if(cli.librosSolicitados[i].atendido){
            archRepCli<<setw(12)<<" "<<setfill('0')<<right<<setw(5)
                    <<cli.librosSolicitados[i].numeroDePedido<<setfill(' ')
                    <<setw(14)<<cli.librosSolicitados[i].codigoDelLibro
                    <<setw(9)<<cli.librosSolicitados[i].precio<<endl;
        }
    }
    archRepCli<<left<<"Total a pagar: "<<cli.pagoTotal<<endl;
    archRepCli<<"Libros no entregados por falta de stock:"<<endl;
    archRepCli<<right<<setw(20)<<"Pedido No."<<setw(10)<<"Codigo"<<endl;
    for(int i=0;i<cli.cantDeLibros;i++){
        if(not cli.librosSolicitados[i].atendido){
            archRepCli<<setw(12)<<" "<<setfill('0')<<right<<setw(5)
                    <<cli.librosSolicitados[i].numeroDePedido<<setfill(' ')
                    <<setw(14)<<cli.librosSolicitados[i].codigoDelLibro<<endl;
        }
    }
}