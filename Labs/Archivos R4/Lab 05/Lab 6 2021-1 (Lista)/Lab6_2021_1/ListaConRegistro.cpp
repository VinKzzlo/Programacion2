/* 
 * File:   ListaConRegistro.cpp
 * Author: ramir
 * 
 * Created on 30 de abril de 2024, 22:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaConRegistro.h"
/*
35912665,O2Z-308,22/07/2019,156
32244565,M8W-853,18/11/2019,335
*/
void *leeregistro(ifstream &archReg){
    void **registro;
    int *licencia,dd,mm,aa,*fecha,*infraccion;
    char *placa,c;
    
    licencia = new int;
    archReg>>*licencia;
    if(archReg.eof()) return nullptr;
    archReg.get();
    placa = LeeCadenaExacta(archReg,8,',');
    infraccion = new int;
    archReg>>dd>>c>>mm>>c>>aa>>c>>infraccion;
    fecha = new int;
    *fecha = aa*10000+mm*100+dd;
    
    registro = new void*[4];
    registro[0] = licencia;
    registro[1] = placa;
    registro[2] = fecha;
    registro[3] = infraccion;
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

int cmpregistro(void *a,void *b){
    int *num1,*num2;
    void **aux1 = (void**)a;
    void **aux2 = (void**)b;
    
    num1 = (int*)aux1[0];
    num2 = (int*)aux2[0];
    return *num2-*num1;
}

void imprimeregistro(ofstream &archRep,void *dato){
    void **registro = (void**)dato;
    int *fecha,*licencia,*infraccion;
    char *placa,*nombre;
    licencia = (int*)dato[0];
    placa = (char*)dato[1];
    fecha = (int*)dato[2];
    infraccion = (int*)dato[3];
    nombre = buscarNombConductor(*licencia);
}
/*
63736112,ZAMORA ZAVALETA RONAL MANUEL
45043076,VEGA VILCARA CARMELA TERESA
*/
char *buscarNombConductor(int licencia){
    int licEncontrada;
    char *nombre;
    ifstream archCon("Conductores.csv",ios::in);
    if(not archCon.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    while(1){
        archCon>>licEncontrada;
        if(archCon.eof()) break;
        archCon.get();
        nombre = LeeCadenaExacta(archCon,60,'\n');
        if(licEncontrada==licencia) return nombre;
    }
}