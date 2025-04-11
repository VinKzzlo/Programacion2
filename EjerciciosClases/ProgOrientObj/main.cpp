/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  2 de octubre de 2024, 8:39
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Rectangulo.h"

//void g(class Rectangulo &rect1) - NO HACER


void f(const class Rectangulo &rect1){//Si el parametro es un objeto, >>>PASAR POR REFERENCIA<<<
    rect1.imprimirResultados();
//    g(rect1);
}

int main(int argc, char** argv) {
    class Rectangulo rect1, rect2;
    double area, perimetro;
    rect1.asignarBase(3.64);
    rect1.asignarAltura(9.746);
    area = rect1.area();
    perimetro = rect1.perimetro();
    cout<<"RECT1"<<endl;
    cout<<"Area = "<<setw(10)<<area<<endl;
    cout<<"Perimetro = "<<setw(10)<<perimetro<<endl;
    rect1.imprimirDatos();
    
    rect2 = rect1;
    cout<<"RECT2"<<endl;
    rect2.imprimirResultados();
    
    f(rect1);
    rect1.imprimirDatos();
    return 0;
}

