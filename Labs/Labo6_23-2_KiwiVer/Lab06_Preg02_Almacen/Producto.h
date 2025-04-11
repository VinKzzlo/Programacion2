/* 
 * Archivo:   Producto.h
 * Autor:     VinKzzlo
 *
 * Creado el  30 de octubre de 2024, 0:44
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    virtual ~Producto();
    int GetCantidad_clientes_no_servidos() const;
    int GetCantidad_clientes_servidos() const;
    int *GetClientes_no_servidos();
    int *GetClientes_servidos();
    
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    char *GetDescripcion( ) const;
    void SetCodigo(char* codigo);
    char *GetCodigo( ) const;
    bool operator +=(class Pedido &ped);
};

bool operator>>(ifstream &arch,class Producto &prod);
void operator<<(ofstream &arch, class Producto &prod);
#endif /* PRODUCTO_H */

