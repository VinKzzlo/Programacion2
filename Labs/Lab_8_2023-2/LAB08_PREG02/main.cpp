/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 11 de junio de 2024, 11:31 PM
 */
#include "Flota.h"

using namespace std;

int main(int argc, char** argv) {
    Flota transporte;
    
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();
    
    return 0;
}
