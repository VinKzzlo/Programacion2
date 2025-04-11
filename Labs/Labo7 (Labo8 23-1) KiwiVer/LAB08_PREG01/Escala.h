/* 
 * Archivo:   Escala.h
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 16:53
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

};

#endif /* ESCALA_H */

