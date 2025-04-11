
/* 
 * Archivo:   A.h
 * Autor:     VinKzzlo
 *
 * Created on 27 de octubre de 2024, 21:41
 */

#ifndef A_H
#define A_H

class A {
private:
    double x;
public:
    A(double cx=0);
    void SetX(double x);
    double GetX() const;
    class A operator ++ (void); //prefijo
    class A operator ++ (int); //sufijo
};

#endif /* A_H */

