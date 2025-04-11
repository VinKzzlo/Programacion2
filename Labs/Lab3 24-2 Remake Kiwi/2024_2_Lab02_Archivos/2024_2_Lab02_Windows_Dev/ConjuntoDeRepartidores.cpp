/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    struct Repartidor *buffRepartidores;
    buffRepartidores = new struct Repartidor[50];
    int numRep=0;
    
    while(archivo_de_repartidores>>buffRepartidores[numRep]) numRep++;
    conjuntoDeRepartidores.conjunto_de_datos = new struct Repartidor[numRep+1];
    
    for(int i=0;i<numRep;i++)
        conjuntoDeRepartidores.conjunto_de_datos[i] = buffRepartidores[i];
    
    conjuntoDeRepartidores.cantidad = numRep;
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}