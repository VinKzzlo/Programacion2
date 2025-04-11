
/* 
 * Archivo:   Vector.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 27 de octubre de 2024, 20:02
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Vector.h"

Vector::Vector(double cx, double cy){
    x = cx; y=cy;
}

void Vector::SetY(double y) {
    this->y = y;
}

double Vector::GetY() const {
    return y;
}

void Vector::SetX(double x) {
    this->x = x;
}

double Vector::GetX() const {
    return x;
}

double Vector::operator *(const class Vector&v){
    return x*v.x + y*v.y;
}

void Vector::operator *(double f){
    x*=f;
    y*=f;
}