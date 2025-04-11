/* 
 * Archivo:   B.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de octubre de 2024, 18:01
 */
#include "A.h"
#ifndef B_H
#define B_H

class B {
private:
    int b;
    int cant;
    class A m[20];
public:
    B(void);
    int GetCant() const;
    void SetB(int b);
    int GetB() const;
    void ingresa(int);
    int operator[](int);
    int operator () (int, int);
};

#endif /* B_H */

