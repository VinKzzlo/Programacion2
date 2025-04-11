/* 
 * Archivo:   Presencial.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:58
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"
class Presencial: public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream &arch);
    actualiza(double montoT);
    void imprime (ofstream &arch);
};

#endif /* PRESENCIAL_H */

