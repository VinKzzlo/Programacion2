/* 
 * Archivo:   A.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 23:50
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "A.h"

A::A(int x) {
    a = x;
}

void A::SetA(int a) {
    this->a = a;
}

int A::GetA() const {
    return a;
}

