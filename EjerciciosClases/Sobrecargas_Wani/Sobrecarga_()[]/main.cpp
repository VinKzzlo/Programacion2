/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 17:57
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "B.h"

/*
 * 
 */
int main(int argc, char** argv) {
    class B obj;
    ifstream arch("datos.txt", ios::in); //Archivo d eenteros
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo datos.txt" << endl;
        exit(1);
    }
    while (1) {
        int p;
        arch >> p;
        if (arch.eof()) break;
        obj.ingresa(p);
    }

    cout << "Datos leidos : " << endl;
    // Por efecto de la sobrecarga el objeto parece un arreglo
    for (int i = 0; i < obj.GetCant(); i++)
        cout << setw(6) << obj[i];
    cout << endl;

    // Por efecto de la sobrecarga el objeto parece una función
    cout << "Sobrecarga del (): " << obj(3, 5) << endl;
    return 0;
}

