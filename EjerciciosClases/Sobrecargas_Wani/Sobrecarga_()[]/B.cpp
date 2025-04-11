/* 
 * Archivo:   B.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 18:01
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "B.h"

B::B(void) {
    cant =0;
}

int B::GetCant() const {
    return cant;
}

void B::SetB(int b) {
    this->b = b;
}

int B::GetB() const {
    return b;
}

void B::ingresa(int x){
    m[cant++].SetA(x);
}

int B::operator[](int i) {
    return m[i].GetA();
}

int B::operator ()(int p, int q){
    return cant*p +q;
}