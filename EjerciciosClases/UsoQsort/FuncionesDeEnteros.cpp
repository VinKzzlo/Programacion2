/* 
 * Archivo:   FuncionesDeEnteros.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de septiembre de 2024, 9:07
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesDeEnteros.h"

int miStrInt(const void *a, const void *b){
    int *ai=(int*)a, *bi=(int*)b;
    return *ai - *bi;
}