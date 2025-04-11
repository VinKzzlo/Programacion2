/* 
 * Archivo:   NPedido.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 23:49
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

class NPedido {
private:
    char *codigo;
    int cantidad;
    double peso;
    class NPedido *sig;
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *) const;
    friend class Vehiculo;
};

#endif /* NPEDIDO_H */

