/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 21 de agosto de 2024, 9:07
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Persona.h"
#include "Sobrecargas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Persona persona{11111111,"Juan Perez",3500.0};
    struct Persona persona2{22222222,"Maria Ruiz",5500.0};
    cout<<persona<<persona2<<endl;
    persona *= 20.5; 
    persona2 *= 100; 
    cout<<persona<<persona2;
    return 0;
}

