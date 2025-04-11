/* 
 * File:   PunterosGenericos.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 21 de abril de 2024, 01:23
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
//Carga de productos
void cargaproductos(void *&productos){
    //El buff es para el segundo nivel, el lproductos es para el tercero
    void *buff[200],**lproductos;
    ifstream archProd("Productos2.csv",ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos2.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        buff[i] = LeerProductos(archProd);
        if(archProd.eof()) break;
        i++;
    }
    int n=i;
    lproductos = new void*[n+1];
    for(i=0;i<n;i++) lproductos[i] = buff[i];
    lproductos[n] = nullptr;
    productos = lproductos;
    
    imprimeproductos(productos);
}
/*
BIT-434,Campana Extractora modelo Glass,375.09,S
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
*/
void *LeerProductos(ifstream &archProd){
    void **registro;    //Se crea un void** para almacenar los tipos de datos
    char *codigo,*descripcion,*tipo,c;
    double *precio;
    
    codigo = LeeCadenaExacta(archProd,8,',');
    if(archProd.eof()) return nullptr;
    descripcion = LeeCadenaExacta(archProd,60,',');
    precio = new double;
    tipo = new char;
    archProd>>*precio>>c>>*tipo;
    archProd.get();
    
    //Se crea espacio de memoria para un arreglo de void*
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = tipo;
    return registro;
}
//Lectura de cadena al primer nivel del puntero
char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
//Carga de clientes
void cargaclientes(void *&clientes){
    void *buff[150],**lclientes;
    ifstream archCli("Clientes2.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes2.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        buff[i] = LeerClientes(archCli);
        if(archCli.eof()) break;
        i++;
    }
    int n=i;
    lclientes = new void*[n+1];
    for(i=0;i<n;i++) lclientes[i] = buff[i];
    lclientes[n] = nullptr;
    clientes = lclientes;
    
    imprimeclientes(clientes);
}
/*
79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
*/
void *LeerClientes(ifstream &archCli){
    void **registro;
    int *dni,*linea,telefono;
    char *nombre,c;
    
    dni = new int;
    archCli>>*dni;
    if(archCli.eof()) return nullptr;
    archCli.get();
    nombre = LeeCadenaExacta(archCli,60,',');
    linea = new int;
    archCli>>telefono>>c>>*linea;
    
    registro = new void*[4];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = nullptr;
    registro[3] = linea;
    return registro;
}
//Carga de pedidos
void cargapedidos(void *productos,void *clientes){
    ifstream archPed("Pedidos2.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos2.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        
    }
}
//Imprimir reporte
void imprimereporte(void *clientes);