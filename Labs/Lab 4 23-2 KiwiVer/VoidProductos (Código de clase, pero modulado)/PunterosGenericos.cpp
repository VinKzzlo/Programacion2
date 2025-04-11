/* 
 * File:   PunterosGenericos.cpp
 * Author: cueva.r
 * 
 * Created on 17 de septiembre de 2024, 10:15 AM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#define MAX 200

using namespace std;

void cargaclientes(void *&clientes){
    int i=0;
    void *buffer[200],**lclientes;
    ifstream arch("Clientes2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de clientes";
        exit(1);
    }
    while(1){
        buffer[i]=leecliente(arch);
        if(arch.eof()) break;
        i++;
    }
    lclientes=new void*[i+1];
    for(int j=0;j<=i;j++)
        lclientes[j]=buffer[j];
    clientes = lclientes;
}
/*
79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000*/
void *leecliente(ifstream &arch){
    int dni,*pdni,telefono;
    char *nombre,c;
    double *linea;
    void **registro;
    
    arch >> dni;
    if(arch.eof()) return nullptr;
    pdni = new int;
    *pdni = dni;
    arch.get();
    nombre = leercadena(arch,200,',');
    linea = new double;
    arch >> telefono >> c >> *linea;
    registro = new void*[4];
    registro[0] = pdni;
    registro[1] = nombre;
    registro[2] = nullptr;
    registro[3] = linea;
    
    return registro;
}


void cargaproductos(void *&productos){
    int i=0;
    void *buffer[200],**lproductos;
    ifstream arch("Productos2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de productos";
        exit(1);
    }
    while(1){
        buffer[i]=leeproducto(arch);
        if(arch.eof()) break;
        i++;
    }
    lproductos=new void*[i+1];
    for(int j=0;j<=i;j++)
        lproductos[j]=buffer[j];
    productos = lproductos;
    imprimeproducto(productos);
}
/*
NMV-644,Lavadora Automatica,3272.48,S
MLE-193,Cocina a gas Ingenious,2779.41,S*/
void *leeproducto(ifstream &arch){
    char *codigo,*nombre,c,*tipo;
    double *precio;
    void  ** registro;
    codigo=leercadena(arch,10,',');
    if(arch.eof()) return nullptr;
    nombre=leercadena(arch,200,',');
    precio = new double;
    tipo = new char;
    arch >> *precio >> c >> *tipo;
    arch.get();
    
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = precio;
    registro[3] = tipo;    
    return registro;
}

char *leercadena(ifstream &arch,int max,char carsep){
    char buff[MAX],*cad;
    
    arch.getline(buff,max,carsep);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeproducto(void *producto){
    void **laux=(void**)producto;
    
    ofstream arch("RepProducto.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el reporte de productos";
        exit(1);
    }
    for(int i=0;laux[i]!=nullptr;i++){
        imprimereg(arch,laux[i]);
    }
}

void imprimereg(ofstream &arch,void*registro){
    void **laux=(void**)registro;
    char *codigo,*nombre,*tipo;
    double *precio;
    
    codigo = (char*)laux[0];
    nombre = (char*)laux[1];
    precio = (double*)laux[2];
    tipo = (char*)laux[3];
    
    arch << codigo <<" "<< nombre << " " << *precio <<endl; 
   
}
/*
JXD-139,50375303,6
CRU-009,50375303,5
 */
void cargapedidos(void *productos,void *clientes){
    void **lclientes=(void**)clientes;
    char *codigo,c,estado;
    int *dni,*cantidad,posicion,numped[200]{0};
    double precio,linea;
    
    ifstream arch("Pedidos2.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de pedidos";
        exit(1);
    }
    while(1){
        codigo=leercadena(arch,10,',');
        if(arch.eof())break;
        dni=new int;
        cantidad = new int;
        arch >> *dni >> c >> *cantidad;
        arch.get();
        precio=buscaprecio(codigo,productos,estado);
        posicion=buscacliente(*dni,clientes,linea);
        if(linea-precio*(*cantidad)>=0 or estado=='N'){
            void**reg=(void**)lclientes[posicion];
            if(numped[posicion]==0){
                reg[2]=new void*[100];
            }
            insertapedido(reg[2],numped[posicion],codigo,cantidad,precio);
            if(estado=='S'){
                double *cred=(double*)reg[3];
                *cred-=precio*(*cantidad);
            }
        }
    }
    imprimeclientes(clientes);
}

void insertapedido(void *pedidos,int &pos,char *codigo,
        int *cantidad,double precio){
    void **lpedidos=(void**)pedidos;
    void **registro;
    double *total;
    
    registro=new void*[3];
    registro[0] = codigo;
    registro[1] = cantidad;
    total = new double;
    *total=(*cantidad)*precio;
    registro[2] = total;
    lpedidos[pos]=registro;
    pos++;
}

int buscacliente(int dni,void *clientes,double &linea){
    void **lclientes=(void**)clientes;
    int *cod;
    double *cred;
    
    for(int i=0;lclientes[i]!=nullptr;i++){
        void **reg=(void**)lclientes[i];
        cod = (int*)reg[0];
        cred = (double*)reg[3];
        if(*cod==dni){
            linea = *cred;
            return i;
        }
    }
}


double buscaprecio(char *codigo,void *productos,
        char &estado){
    char *cad,*tipo;
    double *precio;
    void **lproductos=(void**)productos;
    
    for(int i=0;lproductos[i]!=nullptr;i++){
        void **reg=(void**)lproductos[i];
        cad = (char*)reg[0];
        if(strcmp(cad,codigo)==0){
            precio = (double*)reg[2];
            tipo = (char*)reg[3];
            estado = *tipo;
            return *precio;
        }
    }
    
}