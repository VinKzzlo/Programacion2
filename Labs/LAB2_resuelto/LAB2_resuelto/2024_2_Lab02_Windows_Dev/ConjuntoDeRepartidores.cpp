/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"
#include "ConjuntoDePlatos.hpp"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}
void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    struct Repartidor buffRepartidores[150]{};
    conjuntoDeRepartidores.cantidad=0;
    while(true){
        int n=conjuntoDeRepartidores.cantidad;
        buffRepartidores[n].codigo=leeCadena(archivo_de_repartidores,',');
        if(archivo_de_repartidores.eof())break;
        buffRepartidores[n].nombre=leeCadena(archivo_de_repartidores,',');
        buffRepartidores[n].vehiculo=leeCadena(archivo_de_repartidores);
        conjuntoDeRepartidores.cantidad++;
    }
    conjuntoDeRepartidores.conjunto_de_datos=
            new Repartidor[conjuntoDeRepartidores.cantidad+1]{};
    for (int i = 0; i < conjuntoDeRepartidores.cantidad; i++) {
        conjuntoDeRepartidores.conjunto_de_datos[i]=buffRepartidores[i];
    }
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    for (int i = 0; i < conjuntoDeRepartidores.cantidad; i++) {
        delete conjuntoDeRepartidores.conjunto_de_datos[i].codigo;
        delete conjuntoDeRepartidores.conjunto_de_datos[i].nombre;
        delete conjuntoDeRepartidores.conjunto_de_datos[i].vehiculo;
    }
    delete conjuntoDeRepartidores.conjunto_de_datos;
}