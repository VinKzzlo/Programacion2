/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 13 de mayo de 2024, 23:08
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PriorityQueu.h"
#include "ColaConRegistros.h"
int main(int argc, char** argv) {
    
    void *cola;
    
    creaCola(cola,leeregistro,prioridadregistro,"Pacientes.csv");
    imprimeCola(cola,imprimeregistro,"Tarifas.txt","Repnum.txt");
    
    return 0;
}

