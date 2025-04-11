/* 
 * File:   PilaConEnteros.cpp
 * Author: ramir
 * 
 * Created on 1 de mayo de 2024, 23:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"
void *leenumero(ifstream &archReg){
    int *dato,d;
    archReg>>d;
    if(archReg.eof()) return nullptr;
    dato = new int;
    *dato = d;
    return dato;
}