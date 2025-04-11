/* 
 * Archivo:   main.cpp
 * Autor:     Guanira
 *
 * Creado el  24 de octubre de 2024, 12:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "FunciionesDeEnteros.h"
#include "FuncionesDeCadenas.h"
#include "FuncionesDePunterosGenericos.h"
/*
 * 
 */
int main(int argc, char** argv) {
void *lista;
//    creaLista("datos.txt",lista,leerInt,miCmpInt);
//    imprimirLista("reporte.txt",lista,imprimeInt);
//    eliminarLista(lista,eliminaInt);

    creaLista("personas.txt",lista,leeCadena,miStrcmp);
    imprimirLista("reporte.txt",lista,imprimeStr);
    eliminarLista(lista,eliminaStr);

    creaLista("personal.csv",lista,leerRegistro,miVoidcmpNombres);
    imprimirLista("reporteNom.txt",lista,imprimePersona);
    eliminarLista(lista,eliminaReg);

//    creaLista("personal.csv",lista,leerRegistro,miVoidcmpSueldos);
//    imprimirLista("reporteSueldo.txt",lista,imprimePersona);
//    eliminarLista(lista,eliminaReg);
    return 0;
}

