
/* 
 * Archivo:   Complejo.h
 * Autor:     VinKzzlo
 *
 * Created on 27 de octubre de 2024, 21:21
 */

#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
private:
    double real;
    double imag;
public:
    Complejo(double r=0, double i=0);
    void SetImag(double imag);
    double GetImag() const;
    void SetReal(double real);
    double GetReal() const;
    class Complejo operator + (const class Complejo &);
    class Complejo operator - (const class Complejo &);
    class Complejo operator += (const class Complejo &);
};

#endif /* COMPLEJO_H */

