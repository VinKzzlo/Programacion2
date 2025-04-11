/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 2 de mayo de 2024, 23:36
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaGenerica.h"
#include "ListaConEnteros.h"
int main(int argc, char** argv) {

    void *lista1,*lista2,*listafin;
    
    creaLista(lista1,leenumero,"numeros1.txt");
    creaLista(lista2,leenumero,"numeros2.txt");
    uneLista(listafin,lista1,lista2,cmpnumero);
    imprimeLista(listafin,imprimenumero,"Reportefinal.txt");

    return 0;
}

