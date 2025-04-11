/* 
 * File:   PunterosGenericos.cpp
 * Author: ramir
 * 
 * Created on 25 de abril de 2024, 23:12
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
//Carga de clientes
void cargaclientes(void *&clientes){
    void *buff[100],**lclientes;
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
    int i=0;
    while(1){
        buff[i] = leerClientes(archCli);
        if(archCli.eof()) break;
        i++;
    }
    int n=i;
    lclientes = new void*[n+1];
    for(i=0;i<n;i++) lclientes[i] = buff[i];
    lclientes[n] = nullptr;
    clientes = lclientes;
}
/*
54393647,Reyes Tang Edward 
67066631,Arca Amezquita Edric Ronald
*/
void *leerClientes(ifstream &archCli){
    void **registro;
    int *dni,*numLib;
    char *nombre;
    
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    nombre = LeeCadenaExacta(archCli,60,'\n');
    numLib = new int;
    *numLib = 0;
    
    registro = new void*[4];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = nullptr;
    registro[3] = numLib;
    return registro;
}

char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
//Carga de libros
void cargalibros(void *&libros){
    void *buff[300],**loslibros;
    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib,"Libros.csv");
    int i=0;
    while(1){
        buff[i] = leerLibros(archLib);
        if(archLib.eof()) break;
        i++;
    }
    int n=i;
    loslibros = new void*[n+1];
    for(i=0;i<n;i++) loslibros[i] = buff[i];
    loslibros[n] = nullptr;
    libros = loslibros;
}
/*
IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
*/
void *leerLibros(ifstream &archLib){
    void **registro;
    int stock;
    char *codigo,*nombre,*autor,c;
    double precio;
    
    codigo = LeeCadenaExacta(archLib,8,',');
    if(archLib.eof()) return nullptr;
    nombre = LeeCadenaExacta(archLib,100,',');
    autor = LeeCadenaExacta(archLib,60,',');
    archLib>>stock>>c>>precio;
    archLib.get();
    
    registro = new void*[3];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = autor;
    return registro;
}
//Carga de pedidos
/*
000001,34460612,  CRY6839
000001,34460612,  VYG3594
*/
void cargapedidos(void *clientes,void *libros){
    void **lclientes = (void**)clientes,**loslibros = (void**)libros;
    int posCli,posLib;
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    while(1){
        
    }
}