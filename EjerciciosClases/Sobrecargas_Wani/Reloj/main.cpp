
/* 
 * Archivo:   main.cpp
 * Autor:     Vinkzzlo
 *
 * Creado el 22 de octubre de 2024, 18:19
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Reloj1.h"

int main(int argc, char** argv) {
    class Reloj1 reloj(23, 59, 56);
    
    for (int i = 0; i < 10; ++i, ++reloj) {
        cout<<"  "<<setfill('0');
        cout<<setw(2)<< reloj.GetHora() <<':';
        cout<<setw(2)<< reloj.GetMinuto() <<':';
        cout<<setw(2)<< reloj.GetSegundo() <<endl;
        cout<<setfill(' ');
    }

    
    return 0;
}

