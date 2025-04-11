/* 
 * Archivo: ConjuntoDePlatos.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:50
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo) {
    ifstream archivo_de_platos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_platos, nombre_de_archivo);
    archivo_de_platos >> conjuntoDePlatos;
    archivo_de_platos.close();
}
char *leeCadena(istream &arch, char delim){
    char buffer[100],*cadena;
    arch.getline(buffer,100,delim);
    if(arch.eof())return nullptr;
    cadena=new char[strlen(buffer)+1]{};
    strcpy(cadena,buffer);
    return cadena;
}
void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos) {
    struct Plato buffPlatos[150]{};
    conjuntoDePlatos.cantidad=0;
    while(true){
        int n=conjuntoDePlatos.cantidad;
        buffPlatos[n].codigo=leeCadena(archivo_de_platos,',');
        if(archivo_de_platos.eof())break;
        buffPlatos[n].nombre=leeCadena(archivo_de_platos,',');
        archivo_de_platos>>buffPlatos[n].precio;
        archivo_de_platos.get();//lee coma
        buffPlatos[n].tipo=leeCadena(archivo_de_platos);
        conjuntoDePlatos.cantidad++;
    }
    conjuntoDePlatos.conjunto_de_datos=new Plato[conjuntoDePlatos.cantidad+1]{};
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        conjuntoDePlatos.conjunto_de_datos[i]=buffPlatos[i];
    }
}

void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        delete conjuntoDePlatos.conjunto_de_datos[i].codigo;
        delete conjuntoDePlatos.conjunto_de_datos[i].nombre;
        delete conjuntoDePlatos.conjunto_de_datos[i].tipo;
    }
    delete conjuntoDePlatos.conjunto_de_datos;
}

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {    
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].precio;
    }
}

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}