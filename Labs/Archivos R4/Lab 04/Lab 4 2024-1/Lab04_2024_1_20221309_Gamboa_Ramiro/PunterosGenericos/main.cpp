/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 11 de mayo de 2024, 22:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
int main(int argc, char** argv) {

    void *clientes,*reserva;
    
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes,reserva);
    reportefinal(reserva);

    return 0;
}

