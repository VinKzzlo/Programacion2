/* 
 * Archivo:   NPedido.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 07:32 PM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

class NPedido {
private:
    char* codigo;
    int cantidad;
    double peso;
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* cad);
    void GetCodigo(char *cad) const;
    void leePedido(ifstream &arch);
    void operator =(const NPedido &orig);
    void imprimePedido(int id, ofstream &arch);
    void imprimePedido(ofstream &arch);
};

#endif /* NPEDIDO_H */

