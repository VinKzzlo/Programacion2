/* 
 * File:   Pedido.h
 * Author: ramir
 *
 * Created on 6 de junio de 2024, 08:17 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char *cad);
    void GetCodigo(char *cad) const;
    void SetEstado(char *cad);
    void GetEstado(char *cad) const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
    virtual void actualiza();
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;
};

#endif /* PEDIDO_H */

