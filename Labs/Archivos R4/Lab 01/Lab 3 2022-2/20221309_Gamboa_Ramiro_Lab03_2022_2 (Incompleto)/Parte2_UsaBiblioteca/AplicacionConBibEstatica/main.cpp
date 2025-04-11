/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 4 de abril de 2024, 22:46
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
int main(int argc, char** argv) {
    
    struct StMedico arrMed[50];
    struct StPaciente arrPac[80];
    //Parte A
    leerMedicos(arrMed,"MedicosLab3.txt");
    //Parte B
    leerPacientes(arrPac,"PacientesLab3.txt");
    //Parte C
    completarCitas(arrMed,arrPac,"ConsultasLab3.txt");
    //Parte D
    imprimirReporte(arrPac,"Reporte.txt");
    
    return 0;
}

