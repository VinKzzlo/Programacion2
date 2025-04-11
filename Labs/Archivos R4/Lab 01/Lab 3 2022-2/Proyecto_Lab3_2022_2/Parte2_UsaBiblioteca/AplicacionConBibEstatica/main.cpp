
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 11:45 PM
 */

#include <iostream>

using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "Biblioteca.h"
#include "Funciones.h"
#define MAX_MED 100
#define MAX_PAC 100
/*
 * 
 */
int main(int argc, char** argv) {
    struct StMedico medicos[MAX_MED];
    struct StPaciente pacientes[MAX_PAC];
    LecturaDeMedicos(medicos,"MedicosLab3.txt");
    LecturaDePacientes(pacientes,"PacientesLab3.txt");
    ProcesarCitas(medicos,pacientes,"ConsultasLab3.txt");
    EmitirReporte(pacientes,"Reporte.txt");
    return 0;
}

