
/* 
 * Archivo:   Vector.h
 * Autor:     VinKzzlo
 *
 * Created on 27 de octubre de 2024, 20:02
 */

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x;
    double y;
public:
    Vector(double cx=0, double cy=0);
    void SetY(double y);
    double GetY() const;
    void SetX(double x);
    double GetX() const;
    double operator * (const class Vector &);
    void operator * (double);
};

#endif /* VECTOR_H */

