/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 1 de mayo de 2024, 20:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaGenerica.h"
#include "ListaConEnteros.h"
#include "ColaGenerica.h"
#include "ColaConEnteros.h"
#include "PilaGenerica.h"
#include "PilaConEnteros.h"
int main(int argc, char** argv) {
    
    //Plantilla de TADs para cabezas y nodos que son duplas
    void *lista1,*lista2,*cola,*pila;
    
    creaLista(lista1,leenumero,cmpnumero,"numeros.txt");
    creaLista(lista2,leenumero,cmpnumero,"numeros.txt");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"ReporteLista.txt");
    
    creaCola(cola,leenumero,cmpnumero,"numeros.txt");
    
    
    return 0;
}

