/* 
 * Archivo:   Vehiculo.h
 * Autor:     VinKzzlo
 *
 * Creado el  28 de noviembre de 2024, 10:51 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* cad);
    void GetPlaca(char* cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* VEHICULO_H */

