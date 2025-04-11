/* 
 * Archivo:   Virtual.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 17:10
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual:public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* licencia);
    void GetLicencia(char* cad) const;
    void leerDatos(ifstream &arch);
    void actualiza(double montoT);
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

