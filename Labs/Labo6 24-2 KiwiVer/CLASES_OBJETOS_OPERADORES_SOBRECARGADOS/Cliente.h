/* 
 * Archivo:   Cliente.h
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 18:55
 */

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalPagado(double monto);
    double GetTotalPagado() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetDistrito(char* distrito);
    void GetDistrito(char *cad) const;
    void SetNombre(char* nombre);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const class Cliente &copyC);
};
bool operator >>(ifstream &arch, class Cliente &cli);
void operator <<(ofstream &arch, class Cliente &cli);

#endif /* CLIENTE_H */

