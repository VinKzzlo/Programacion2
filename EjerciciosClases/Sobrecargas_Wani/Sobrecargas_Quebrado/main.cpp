/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 11:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Quebrado.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Quebrado a(2, 3), b(5, 6), c, d;
    int p = 3;

    cout << "A = ";
    a.muestra();
    cout << endl;

    cout << "B = ";
    b.muestra();
    cout << endl;

    d = c = a;

    cout << "C = ";
    c.muestra();
    cout << endl;

    cout << "D = ";
    d.muestra();
    cout << endl;

    c = a + b;
    cout << "C = A + B = ";
    c.simplifica();
    c.muestra();
    cout << endl;

    d += b;
    cout << "D += B = ";
    d.muestra();
    cout << endl;

    d = a + Quebrado(p);
    //d = a + p;
    cout << "D = A + p = ";
    d.muestra();
    cout << endl;
    d = Quebrado(p) + a; // también: d = Quebrado(3) + a;
    //d = p + a;
    cout << "D = p + A = ";
    d.muestra();
    cout << endl;

    double f;
    f = double(a);
    cout << "f = " << f << endl;
    return 0;
}

