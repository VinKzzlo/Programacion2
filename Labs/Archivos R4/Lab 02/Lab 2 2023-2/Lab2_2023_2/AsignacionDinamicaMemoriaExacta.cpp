/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: ramir
 * 
 * Created on 26 de marzo de 2024, 10:57
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios){
    //Con ampersand porque en el main.cpp todavia no se ha creado un espacio de 
    //memoria
    char **buffprod[200],c;
    double buffprecio[200];
    int buffstock[200];
    int i=0;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(1){
        buffprod[i] = leeProductos(arch);
        if(arch.eof()) break;
        arch>>buffprecio[i]>>c>>buffstock[i];
        arch.get();
        i++;
    }
    int n=i;
    productos = new char**[n+1];
    stock = new int[n];
    precios = new double[n];
    
    for(int j=0;j<n;j++){
        productos[j] = buffprod[j];
        precios[j] = buffprecio[j];
        stock[j] = buffstock[j];
    }
    productos[n] = buffprod[n];
}
/*
BIT-434,Campana Extractora modelo Glass,375.09,10
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23
*/
char **leeProductos(ifstream &arch){
    char *cad,**dupla;
    
    cad = leeCadena(arch,8,',');
    if(arch.eof()) return nullptr;
    //Se asigna la memoria de dupla despues de verificar que leyo
    //Sino, error de concepto por desperdicio de memoria
    dupla = new char*[2];
    dupla[0] = cad;
    dupla[1] = leeCadena(arch,150,',');
    return dupla;
}

char *leeCadena(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **aux;
    for(int i=0;productos[i]!=nullptr;i++){
        aux = productos[i];
        arch<<right<<setw(10)<<aux[0]<<setw(60)<<aux[1]<<setw(10)<<precios[i]
                <<setw(5)<<stock[i]<<endl;
    }
}
/*
JXD-139,50375303,6,24/08/2023
CRU-009,50375303,5,3/09/2023
*/
void lecturaDeProductos(const char *nombArch,int *&fechaPedidos,
                        char ***&codigoPedidos,int ***&dniCantPedidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int buffFecha[600],**buffCantPed[600],numped[600],dni,cant,dd,mm,aa,fecha;
    int ind,i=0;
    char **buffCodPed[600],*codigo,c;
    while(1){
        codigo = leeCadena(arch,8,',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        arch.get();
        fecha = aa*10000+mm*100+dd;
        ind = buscaFecha(fecha,buffFecha,i);
        if(ind==NO_ENCONTRADO)
            agregarFecha(buffFecha,buffCodPed,buffCantPed,fecha,numped,ind,i);
        //Para hacer la agregacion de pedido mandamos el buffer interno
        agregarPedido(buffCodPed[ind],buffCantPed[ind],numped[ind],dni,cant,
                      codigo);
        cargaArreglos(fechaPedidos,codigoPedidos,dniCantPedidos,buffFecha,
                      buffCodPed,buffCantPed,numped,i);
    }
}

int buscaFecha(int fecha,int *buffFecha,int &n){
    for(int i=0;i<n;i++)
        if(buffFecha[i]==fecha) return i;
    return NO_ENCONTRADO;
}

void agregarFecha(int *buffFecha,char ***buffCodPed,int ***buffCantPed,
                  int fecha,int *numped,int &ind,int &n){
    buffFecha[n] = fecha;
    buffCodPed[n] = new char*[600];
    buffCantPed[n] = new int*[600];
    numped[n] = 0;
    ind = n;
    n++;
}

void agregarPedido(char **buffcod,int **buffdni,int &n,int dni,int cant,
                   char *codigo){
    int *aux;
    buffdni[n] = new int[2];
    aux = buffdni[n];
    aux[0] = dni;
    aux[1] = cant;
    buffcod[n] = codigo;
    n++;
}

void cargaArreglos(int *&fechaPedidos,char ***&codigoPedidos,
                   int ***&dniCantPedidos,int *buffFecha,char ***buffCodPed,
                   int ***buffCantPed,int *numped,int n){
    fechaPedidos = new int[n+1];
    codigoPedidos = new char**[n];
    dniCantPedidos = new int**[n];
    
    for(int i=0;i<n;i++){
        fechaPedidos[i] = buffFecha[i];
        codigoPedidos[i] = new char*[numped[i]+1];
        dniCantPedidos[i] = new int*[numped[i]];
        cargaNivelInterno(codigoPedidos[i],dniCantPedidos[i],buffCodPed[i],
                          buffCantPed[i],numped[i]);
    }
    fechaPedidos[n] = 0;
}

void cargaNivelInterno(char **&codigoped,int **&dnicantped,char **buffCodPe,
                       int **buffCantPe,int cantped){
    for(int i=0;i<cantped;i++){
        codigoped[i] = buffCodPe[i];
        dnicantped[i] = buffCantPe[i];
    }
    codigoped[cantped] = nullptr;
}