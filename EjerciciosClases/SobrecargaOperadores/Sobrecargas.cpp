/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * Archivo:   Sobrecargas.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 21 de agosto de 2024, 9:12
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Persona.h"
#include "Sobrecargas.h"

void operator *=(struct Persona &persona, double porcentaje){
    persona.sueldo *= (1+porcentaje/100);
}

//void operator <<(ostream &out, const struct Persona &persona){
//    out.precision(2);
//    out<<fixed;
//    out<<left<<setw(10)<<"DNI"<<setw(30)<<"Nombre"<<setw(10)<<"Sueldo"<<endl;
//    out<<setw(10)<<persona.dni<<left<<setw(30)<<persona.nombre
//       <<right<<setw(10)<<persona.sueldo<<endl;
//}

ostream& operator <<(ostream &out, const struct Persona &persona){
    out.precision(2);
    out<<fixed;
    out<<left<<setw(10)<<"DNI"<<setw(30)<<"Nombre"<<setw(10)<<"Sueldo"<<endl;
    out<<setw(10)<<persona.dni<<left<<setw(30)<<persona.nombre
       <<right<<setw(10)<<persona.sueldo<<endl;
    return out;
}