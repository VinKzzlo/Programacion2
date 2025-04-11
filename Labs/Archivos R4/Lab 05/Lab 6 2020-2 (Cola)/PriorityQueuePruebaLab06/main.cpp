/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 13 de mayo de 2024, 21:58
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PriorityQueu.h"
#include "ColaConEnteros.h"
int main(int argc, char** argv) {
    
    void *cola;
    
    creaCola(cola,leenumero,prioridadnum,"Datos.txt");
    prueba(cola,imprimenum,"Repnum.txt");
    
    return 0;
}

