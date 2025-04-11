/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 23 de mayo de 2024, 09:38 AM
 */

#include "Almacen.h"

using namespace std;

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    
    return 0;
}

