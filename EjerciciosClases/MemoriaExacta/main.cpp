/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 28 de agosto de 2024, 8:39
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int *datos, numDat;
    int *datos2;
    
    leerDatosDeManeraExacta(datos2,"datos.txt");
    imprimirDatos(datos2,"reporte.txt");
    
    return 0;
}

