/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 23 de abril de 2024, 10:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"
int main(int argc, char** argv) {
    
    void *lista1,*lista2;
    
    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"Repnum.txt");
    /*
    creaLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
    creaLista(lista2,leeregistro,cmpregistro,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimeregistro,"Repfalta.txt");
    */
    return 0;
}

