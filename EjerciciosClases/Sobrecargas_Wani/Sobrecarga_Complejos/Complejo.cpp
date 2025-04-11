
/* 
 * Archivo:   Complejo.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 27 de octubre de 2024, 21:21
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Complejo.h"

Complejo::Complejo(double r, double i) {
    real = r;
    imag = i;
}


void Complejo::SetImag(double imag) {
    this->imag = imag;
}

double Complejo::GetImag() const {
    return imag;
}

void Complejo::SetReal(double real) {
    this->real = real;
}

double Complejo::GetReal() const {
    return real;
}

class Complejo Complejo::operator +(const class Complejo &c){
    return Complejo( real + c.GetReal() , imag + c.GetImag() );
}

class Complejo Complejo::operator -(const class Complejo &c){
    return Complejo( real - c.GetReal() , imag - c.GetImag());
}

class Complejo Complejo::operator +=(const class Complejo &c){
    real += c.GetReal();
    imag += c.GetImag();
    return *this;
}