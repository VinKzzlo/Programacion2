/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de septiembre de 2024, 9:06
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstdlib>
#include "FuncionesDeEnteros.h"
#include "FuncionesDeCadenas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int a[50]{10,25,7,15,8,33,45,1,19,10,6,16,41}, n=13;
    qsort(a,n,sizeof(int),miStrInt);
    for(int i=0;a[i];i++)
        cout<<a[i]<<' ';
    cout<<endl;
    
    int nPer=0;
    char**personas;
    leerDatos(personas,nPer,"Personas.txt");
    qsort(personas,nPer,sizeof(char*),miStrcmp);
    for(int i=0;i<nPer;i++)
        cout<<personas[i]<<endl;
    return 0;
}

