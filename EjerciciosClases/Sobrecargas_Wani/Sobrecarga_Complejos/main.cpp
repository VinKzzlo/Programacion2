/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  27 de octubre de 2024, 21:21
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Complejo.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Complejo a(1.5,2.3), b(5.2,4.7), c(1.1,0.4), d;
    cout.precision(2);
    cout<<fixed;
    
    d = a + b - c;
    cout << "D = "<< setw(7) << d.GetReal()
         << " + " << setw(7) << d.GetImag() << " i "<<endl;
    d = a += c;
    cout << "A = "<< setw(7) << a.GetReal()
         << " + " << setw(7) << a.GetImag() << " i "<<endl;
    cout << "D = "<< setw(7) << d.GetReal()
         << " + " << setw(7) << d.GetImag() << " i "<<endl;
    return 0;
}

