
/* 
 * Archivo:   Quebrado.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 28 de octubre de 2024, 11:47
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Quebrado.h"

Quebrado::Quebrado(int n, int d) {
    numerador = n;
    denominador = d;
}

void Quebrado::SetDenominador(int denominador) {
    this->denominador = denominador;
}

int Quebrado::GetDenominador() const {
    return denominador;
}

void Quebrado::SetNumerador(int numerador) {
    this->numerador = numerador;
}

int Quebrado::GetNumerador() const {
    return numerador;
}

void Quebrado::muestra(void) const{
    cout<<numerador<<'/'<<denominador<<endl;
}

class Quebrado Quebrado::simplifica(void){
    int mcd, temp, resto;
    
    mcd = (numerador >=0) ? numerador : - numerador;
    temp = (denominador >= 0 ) ? denominador : -denominador;
    
    while(temp>0){
        resto = mcd % temp;
        mcd = temp;
        temp = resto;
   }
    if(mcd > 1){
        numerador /= mcd;
        denominador /= mcd;
    }
    return *this;
    
}

class Quebrado Quebrado::operator =(const class Quebrado &q){
    numerador = q.GetNumerador();
    denominador = q.GetDenominador();
    return this->simplifica();
}

class Quebrado Quebrado::operator +=(const class Quebrado &q){
    numerador = numerador*q.denominador + q.numerador*denominador;
    denominador = denominador*q.denominador;
    return this->simplifica();
}

class Quebrado Quebrado::operator -=(const class Quebrado &q){
    numerador = numerador*q.denominador - q.numerador*denominador;
    denominador = denominador*q.denominador;
    return this->simplifica();
}

Quebrado::operator double(){
    return double(numerador)/denominador;
}

class Quebrado Quebrado::operator + (const class Quebrado &q2){
    return Quebrado(numerador * q2.denominador + q2.numerador * denominador,
                    denominador * q2.denominador);
}

class Quebrado Quebrado::operator - (const class Quebrado &q2){
    return Quebrado(numerador * q2.denominador - q2.numerador * denominador,
                    denominador * q2.denominador);
}