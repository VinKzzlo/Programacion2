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
    Repartidor *datosRepartidores;
    datosRepartidores = new struct Repartidor[50]{};
    int cant=0;
    while(archivo_de_repartidores>>datosRepartidores[cant]){
        cant++;
    }
    conjuntoDeRepartidores.conjunto_de_datos= new struct Repartidor[cant+1]{};
    for(int i=0;i<cant;i++){
        conjuntoDeRepartidores.conjunto_de_datos[i]=datosRepartidores[i];
    }
    conjuntoDeRepartidores.cantidad=cant;
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}