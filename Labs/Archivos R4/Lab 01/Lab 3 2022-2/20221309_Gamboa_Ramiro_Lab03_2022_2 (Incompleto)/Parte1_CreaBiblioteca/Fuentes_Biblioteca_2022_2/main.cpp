/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 29 de marzo de 2024, 23:17
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
int main(int argc, char** argv) {
    
    ifstream archMed,archPac,archCit;
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaLeer(archMed,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPac,"PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archCit,"ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Reporte.txt");
    
    struct StMedico arrMed[50];
    struct StPaciente arrPac[80];
    struct StCita cit;
    
    for (int i = 0; i < 40; i++) {
        archMed >> arrMed[i];
        archPac >> arrPac[i];
    }
    
    for (int i = 0; i < 40; i++) {
        arrPac[i].citas[0] = {};
    }
    
    while(true){
        int dni = (archCit >> cit);
        if (archCit >> cit) break; // se terminaron de leer las consultas
        if (!(cit <= arrMed)) continue;
        int j;
        for (j = 0; arrPac[j].dni != dni and j < 40; j++); // buscamos al paciente
        if (j == 40) continue; // no se encontro al paciente con el dni
        arrPac[j] += cit; // como si se encontro, vamos a guardar su cita
    }
    
    for (int i = 0; i < 40; i++) {
        ++(arrPac[i]); //calculamos el costo de sus consultas
        archRep << arrPac[i]; //imprimos el reporte
    }
    
    return 0;
}

