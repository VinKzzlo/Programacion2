/* 
 * Archivo:   ProductoEntregado.h
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:19
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* codigo);
    char *GetCodigo() const;

};

#endif /* PRODUCTOENTREGADO_H */

