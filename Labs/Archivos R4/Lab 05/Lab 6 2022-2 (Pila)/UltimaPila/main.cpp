/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 14 de mayo de 2024, 00:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
int main(int argc, char** argv) {
    
    void *arreglo,*pilaini,*pilafin;
    
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    return 0;
}

