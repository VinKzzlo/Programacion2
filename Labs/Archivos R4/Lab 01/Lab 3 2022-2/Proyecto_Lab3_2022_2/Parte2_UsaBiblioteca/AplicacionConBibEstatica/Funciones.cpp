
/* 
 * File:   Funciones.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 11:50 PM
 */

#include <iostream>



using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Biblioteca.h"
#include "Funciones.h"

void LecturaDeMedicos(struct StMedico *medicos, const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    int i = 0;
    while(arch >> medicos[i])i++;
    medicos[i].codigo = 0;
}
void LecturaDePacientes(struct StPaciente *pacientes, const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    int i = 0;
    while(arch >> pacientes[i])i++;
    pacientes[i].dni = 0;
}
void ProcesarCitas(struct StMedico *medicos,struct StPaciente *pacientes,
        const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    struct StCita cita;
    int dni,i,pos;
    while(true){
        dni = arch >> cita;
        if(dni == -1)break;
        if(cita <= medicos){
            pos = BuscarPaciente(pacientes,dni);
            if(pos != -1)pacientes[pos]+=cita;
        }
    }
    for(i = 0;pacientes[i].dni;i++)++pacientes[i];
}

int BuscarPaciente(struct StPaciente *pacientes,int dni){
    for(int i=0;pacientes[i].dni;i++)
        if(pacientes[i].dni == dni)return i;
    return -1;
}

void EmitirReporte(struct StPaciente *pacientes, const char* nomArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nomArch);
    arch.precision(2);
    arch << fixed;
    arch << setw(60) << "EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    arch << setw(59) << "PACIENTES QUE FUERON ATENDIDOS"<<endl;
    ImprimirLinea(arch,'=',150);
    for (int i = 0; pacientes[i].dni; i++) {
        arch << pacientes[i];
        ImprimirLinea(arch,'=',150);
    }
}

void ImprimirLinea(ofstream &arch,char c,int n){
    arch << setfill(c) << setw(n) << c << setfill(' ')<<endl;
}
