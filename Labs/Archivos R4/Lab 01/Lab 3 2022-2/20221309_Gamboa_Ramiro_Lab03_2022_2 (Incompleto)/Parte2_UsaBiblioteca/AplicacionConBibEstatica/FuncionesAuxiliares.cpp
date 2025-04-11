/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ramir
 * 
 * Created on 4 de abril de 2024, 22:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "FuncionesAuxiliares.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 120
//Parte A
void leerMedicos(struct StMedico *arrMed,const char *nombArch){
    ifstream archMed;
    
    AperturaDeUnArchivoDeTextosParaLeer(archMed,nombArch);
    
    struct StMedico med;
    
    for(int i=0;i<50;i++){
        if(!(archMed>>med)){
            arrMed[i].codigo = 0;
            break;
        }
        arrMed[i] = med;
    }
}
//Parte B
void leerPacientes(struct StPaciente *arrPac,const char *nombArch){
    ifstream archPac;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPac,nombArch);
    
    struct StPaciente pac;
    
    for(int i=0;i<80;i++){
        if(!(archPac>>pac)){
            arrPac[i].dni = 0;
            break;
        }
        arrPac[i] = pac;
    }
}
//Parte C
void completarCitas(struct StMedico *arrMed,struct StPaciente *arrPac,
                    const char *nombArch){
    ifstream archCit;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCit,nombArch);
    
    struct StCita cit;
    
    int dni,posPac;
    while(1){
        dni = archCit>>cit;   //Devuelve el DNI
        if(dni==NO_ENCONTRADO) break;
        if(cit <= arrMed){
            posPac = buscarPaciente(arrPac,dni);
            if(posPac!=NO_ENCONTRADO)
                arrPac[posPac] += cit;
        }
    }
    for(int i=0;arrPac[i].dni!=0;i++){
        ++arrPac[i];
    }
}

int buscarPaciente(struct StPaciente *arrPac,int dni){
    for(int i=0;arrPac[i].dni!=0;i++)
        if(arrPac[i].dni==dni) return i;
    return NO_ENCONTRADO;
}
//Parte D
void imprimirReporte(struct StPaciente *arrPac,const char *nombArch){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<fixed<<setprecision(2);
    archRep<<setw(60)<<"EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    archRep<<setw(59)<<"PACIENTES QUE FUERON ATENDIDOS"<<endl;
    imprimirLinea(archRep,'=');
    for (int i=0;arrPac[i].dni!=0;i++) {
        archRep<<arrPac[i];
        imprimirLinea(archRep,'=');
    }
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}