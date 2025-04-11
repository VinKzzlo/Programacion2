/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  27 de octubre de 2024, 21:41
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "A.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class A a1(2), a2(3), a3;

    cout.precision(2);
    cout << fixed;

    cout << "Inicialmente : " << endl;
    cout << "A1 : " << setw(7) << a1.GetX() << endl;
    cout << "A2 : " << setw(7) << a2.GetX() << endl << endl;

    a3 = ++a1;
    cout << "Como prefijo A3 = ++A1 :" << endl;
    cout << "A1 : " << setw(7) << a1.GetX() << endl;
    cout << "A3 : " << setw(7) << a3.GetX() << endl << endl;

    a3 = a2++;
    cout << "Como sufijo A3 = A2++" << endl;
    cout << "A2 : " << setw(7) << a2.GetX() << endl;
    cout << "A3 : " << setw(7) << a3.GetX() << endl;
    return 0;
}

