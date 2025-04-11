/* 
 * File:   ColaConRegistros.cpp
 * Author: ramir
 * 
 * Created on 13 de mayo de 2024, 23:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ColaConRegistros.h"
#include "PriorityQueu.h"
#define MAX_LINEA 140
/*
36934113,Milagros Natalia Baca Camacho,E,6720
12484697,Angel Shirakawa Ortega,A,6720,37.94
34417318,Delia Estefania Cabrera Moreno,U,5291,15.18,17.48521033
*/
void *leeregistro(ifstream &archReg){
    void **registro;
    int *dni,*codEsp;
    char *nombre,*tipo,c;
    double *porcTarifa,*porcDesc;
    
    dni = new int;
    archReg>>*dni;
    if(archReg.eof()) return nullptr;
    archReg.get();
    nombre = LeeCadenaExacta(archReg,60,',');
    tipo = new char,codEsp = new int;
    porcTarifa = new double,porcDesc = new double;
    *porcTarifa = 100, *porcDesc = 100;
    archReg>>*tipo>>c>>*codEsp;
    if(tipo!='E') archReg>>c>>*porcTarifa;
    if(tipo=='U') archReg>>c>>*porcDesc;
    archReg.get();
    
    registro = new void*[6];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = tipo;
    registro[3] = codEsp;
    registro[4] = porcTarifa;
    registro[5] = porcDesc;
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

int prioridadregistro(void *dato){
    void **registro = (void**)dato;
    char *tipo = (char*)registro[2];
    
    if(tipo=='E') return 3;
    if(tipo=='U') return 2;
    if(tipo=='A') return 1;
}

void imprimeCola(void *cola,void(*imprime)(ofstream &,void*),
                 const char *nombArchTar,const char *nombArchRep){
    void *dato;
    double totCobrado = 0,*arrTarifas[10];
    leerTarifas(arrTarifas,nombArchTar);
    ofstream archRep(nombArchTar,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTar<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    imprimirEncabezado(archRep);
    while(1){
        dato = desencola(cola);
        if(dato==nullptr) break;
        imprime(archRep,dato);
    }
}

void leerTarifas(double **&arrTarifas,const char *nombArchTar){
    double codEsp,tarifa;
    ifstream archTar(nombArchTar,ios::in);
    if(not archTar.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTar<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        archTar>>codEsp;
        if(archTar.eof()) break;
        archTar>>tarifa;
        agregarDatos(arrTarifas[i],codEsp,tarifa);
        i++;
    }
}

void agregarDatos(double *&arrTarifa,double codEsp,double tarifa){
    arrTarifa = new double[2];
    arrTarifa[0] = codEsp;
    arrTarifa[1] = tarifa;
}

void imprimeregistro(ofstream &archRep,void *dato){
    void **registro = (void**)dato;
    
    
}

void imprimirEncabezado(ofstream &archRep){
    archRep<<setw(80)<<"ATENCION DE PACIENTES"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<left<<setw(5)<<"No."<<setw(10)<<"DNI"<<setw(60)<<"Paciente"
           <<setw(15)<<"Especialidad"<<setw(8)<<"Pago"<<"Tipo"<<endl;
    
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}