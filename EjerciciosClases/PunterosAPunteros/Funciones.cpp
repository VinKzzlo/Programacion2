/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   Funciones.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 28 de agosto de 2024, 9:28
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Funciones.h"

void cargarAlumnos(int *&codigos, char **&nombres, char ***&cursos,
                   const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int buffCod[50]{}, numDat=0, cod;
    char *buffNomb[50]{}, **buffCur[50]{};
    
    while(true){
        arch>>cod;
        if(arch.eof());
        arch.get();
        buffCod[numDat] = cod;
        buffNomb[numDat] = leeNombre(arch);
        buffCur[numDat] = leeCursos(arch);
        numDat++;       
    }
    codigos = new int   [numDat+1]{};
    nombres = new char *[numDat+1]{};
    cursos = new char **[numDat+1]{};
    for(int i=0;i<numDat;i++){
        codigos[i] = buffCod[i];
        nombres[i] = buffNomb[i];
        cursos[i] = buffCur[i];
    }
    
}
char* leeNombre(ifstream &arch){
    char buffer[60], *cadena;
    arch.getline(buffer,60,',');
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

char** leeCursos(ifstream &arch){
    char* buffCod[20], *cur;
    int numCur=0;
    while(true){
        cur = 
    }
}

void imprimirAlumnos(int *&codigos, char **&nombres, char ***&cursos,
                     const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    
    
}
