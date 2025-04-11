
/* 
 * Archivo:   Quebrado.h
 * Autor:     VinKzzlo
 *
 * Created on 28 de octubre de 2024, 11:47
 */

#ifndef QUEBRADO_H
#define QUEBRADO_H

class Quebrado {
private:
    int numerador;
    int denominador;
public:
    Quebrado(int n= 0, int d= 1);
    void SetDenominador(int denominador);
    int GetDenominador() const;
    void SetNumerador(int numerador);
    int GetNumerador() const;
    void muestra(void) const;
    class Quebrado simplifica(void);
    class Quebrado operator = (const class Quebrado &);
    class Quebrado operator += (const class Quebrado &);
    class Quebrado operator -= (const class Quebrado &);
    class Quebrado operator + (const class Quebrado &);
    class Quebrado operator - (const class Quebrado &);
    
    operator double();
};

#endif /* QUEBRADO_H */

