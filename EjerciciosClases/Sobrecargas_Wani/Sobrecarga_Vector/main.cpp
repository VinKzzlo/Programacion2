/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  27 de octubre de 2024, 19:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Vector.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Vector v1(10,20), v2(5,5);
    double prodEsc;
    cout.precision(2);
    cout<<fixed;
    
    prodEsc = v1*v2;
    cout << " Producto escalar = " << setw(8)<< prodEsc <<endl;
    
    v1*5;
    cout<<"Resultado de escalar el vector:"<<endl;
    cout<<"x = "<<setw(8)<<v1.GetX()<<endl;
    cout<<"y = "<<setw(8)<<v1.GetY()<<endl;
    return 0;
}

