
/* 
 * Archivo:   A.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 27 de octubre de 2024, 21:41
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "A.h"

A::A(double cx) {
    x = cx;
}

void A::SetX(double x) {
    this->x = x;
}

double A::GetX() const {
    return x;
}

class A A::operator ++(void){ // como PREFIJO
    x = x*x;
    return *this;
}

class A A::operator ++(int){ //como SUFIJO
    class A aux =*this;
    x = x*x;
    return aux;
}