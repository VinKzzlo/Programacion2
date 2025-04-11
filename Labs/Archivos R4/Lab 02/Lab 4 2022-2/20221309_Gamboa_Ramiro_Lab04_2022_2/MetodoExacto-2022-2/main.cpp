/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 8 de abril de 2024, 15:32
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoExacto.h"
int main(int argc, char** argv) {
    
    char **med_Nombre,**med_Especialidad,**pac_Nombre;
    int *med_Codigo,*pac_Dni,**pac_Citas;
    double *med_Tarifa;
    
    lecturaDeMedicos("Medicos.csv",med_Codigo,med_Nombre,med_Especialidad,
                     med_Tarifa);
    pruebaDeLecturaDeMedicos("ReporteMedicos.txt",med_Codigo,med_Nombre,
                             med_Especialidad,med_Tarifa);
    lecturaDeCitas("Citas.csv",pac_Dni,pac_Nombre,pac_Citas);
    pruebaDeLecturaDeCitas("ReporteDeCitas.txt",pac_Dni,pac_Nombre,pac_Citas);
    reporteDeIngresosMedicosYGastosDeLosPacientes("ReporteDeIngresosMedicos.txt",
            med_Codigo,med_Nombre,med_Especialidad,med_Tarifa,pac_Dni,
            pac_Nombre,pac_Citas);
    
    return 0;
}

