/* 
 * Archivo:   Pedido.h
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:46
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;

};

bool operator >>(ifstream &arch, class Pedido &ped);

#endif /* PEDIDO_H */

