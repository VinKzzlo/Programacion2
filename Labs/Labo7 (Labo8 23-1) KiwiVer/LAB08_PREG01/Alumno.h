/* 
 * Archivo:   Alumno.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:53
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* nombre);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leeDatos(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

