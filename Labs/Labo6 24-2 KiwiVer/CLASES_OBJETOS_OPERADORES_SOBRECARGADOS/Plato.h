/* 
 * Archivo:   Plato.h
 * Autor:     VinKzzlo
 *
 * Creado el  7 de noviembre de 2024, 20:36
 */

#ifndef PLATO_H
#define PLATO_H

class Plato {
private:
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();
    void SetTotalNeto(double totalNeto);
    double GetTotalNeto() const;
    void SetTotalBruto(double totalBruto);
    double GetTotalBruto() const;
    void SetTotalEsperado(double totalEsperado);
    double GetTotalEsperado() const;
    void SetNoAtendidos(int noAtendidos);
    int GetNoAtendidos() const;
    void SetAtendidos(int atendidos);
    int GetAtendidos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPreparados(int preparados);
    int GetPreparados() const;
    void SetCategoria(char* categoria);
    void GetCategoria(char* cad) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char* cad) const;
    void operator =(const class Plato &plat);
    void actualiza(int cantidad, class Cliente &cli);
};
bool operator >>(ifstream &arch,class Plato &plat);
void operator <<(ofstream &arch,class Plato &plat);
#endif /* PLATO_H */

