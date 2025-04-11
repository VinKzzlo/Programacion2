/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on October 25, 2024, 11:00 PM
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Funciones.h"
#include "Cliente.h"
#include "Repartidor.h"

int main(int argc, char** argv) {
    Repartidor lrep[50];
    Cliente lcli[80];
    Plato lpla[150];
    
    cargarepartidores(lrep); //Es obvio leese repartidores y los cargas
    cargaclientes(lcli); //Es obvio leese clientes y los cargas
    cargaplatos(lpla); //Es obvio leese platos y los cargas
    actualizar(lrep, lcli, lpla); //En los anteriores solo cargas datos como nombre y codigo, en este usand el arch pedidos agregas lo necesario
    imprimir(lrep); //Y LOS IMPRIMIR NO LOS VOY A EXPLICAR ES LO MAS FACIL DE LA VIDA DESDE TP
    
    return 0;
}

