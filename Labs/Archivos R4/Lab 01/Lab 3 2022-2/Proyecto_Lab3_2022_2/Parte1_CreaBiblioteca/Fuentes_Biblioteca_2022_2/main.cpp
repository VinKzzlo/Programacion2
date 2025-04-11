
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 09:35 PM
 */

#include <iostream>

using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "Biblioteca.h"

#define MAX_MED 100
#define MAX_PAC 100
//#define MAX_CON 300
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archMed,archCon,archPac;
    AperturaDeUnArchivoDeTextosParaLeer(archMed,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archCon,"ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPac,"PacientesLab3.txt");
    struct StMedico medicos[MAX_MED];
    int numMed=0;
    struct StPaciente pacientes[MAX_PAC];
    int numPac=0;
    while(archMed>>medicos[numMed])numMed++;
    medicos[numMed].codigo = 0;
    while(archPac>>pacientes[numPac])numPac++;
    pacientes[numPac].dni = 0;
    struct StCita cita;
    int dni,i;
    while(true){
        dni = archCon >> cita;
        if(dni == -1)break;
        if(cita <= medicos)
            for (i = 0; pacientes[i].dni; i++)
                if (dni == pacientes[i].dni)
                    pacientes[i]+=cita;
    }
    for(i = 0; pacientes[i].dni; i++)++pacientes[i];
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,"Reporte.txt");
    arch.precision(2);
    arch << fixed;
    for(int i=0;pacientes[i].dni;i++){
        arch << pacientes[i];
        arch << endl ;
    }
    return 0;
}

