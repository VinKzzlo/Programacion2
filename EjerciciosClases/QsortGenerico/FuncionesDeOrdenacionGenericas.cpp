/* 
 * Archivo:   FuncionesDeOrdenacionGenericas.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  25 de septiembre de 2024, 8:44
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesDeOrdenacionGenericas.h"

void ordenarG(void *arr, int izq, int izq, int(*cmp)(const void*,const void *)){
    void **areglo = (void**)arr;
    int limite;
    
    if (izq >= der) return;
    cambiarG(arreglo[izq],arreglo[(izq+der)/2]);
    limite = izq;
    for(int i= izq+1; i<=der; i++){
        if(cmp(arreglo[izq],arreglo[i])>0){
            cambiarG(arreglo[++limite],arreglo[i]);
        }
    }
    ordenarG(arreglo,izq,limite-1,cmp);
    ordenarG(arreglo,limite+1,der,cmp);
}