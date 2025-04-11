/* 
 * Archivo:   Semipresencial.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 17:06
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial: public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream &arch);
    void actualiza(double montoT);
    void imprime (ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */

