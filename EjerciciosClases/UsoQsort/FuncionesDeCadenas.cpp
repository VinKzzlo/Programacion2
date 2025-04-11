/* 
 * Archivo:   FuncionesDeCadenas.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de septiembre de 2024, 9:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesDeCadenas.h"

void leerDatos(char**& personas,int &nPer, const char*nombArch){
    char *buff[200];
    ifstream arch(nombArch,ios::in);
    while(true){
        buff[nPer] = leeCadena(arch);
        if(arch.eof()) break;
        nPer++;
    }
    personas = new char*[nPer+1]{};
    for(int i=0;i<nPer;i++){
        personas[i] = buff[i];
    }
}
char*leeCadena(ifstream &arch){
    char buffer[100], *cadena;
    arch.getline(buffer,100);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

int miStrcmp(const void *a, const void *b){
    char **ai = (char**)a, **bi = (char**)b;
    return strcmp(*ai,*bi);
}