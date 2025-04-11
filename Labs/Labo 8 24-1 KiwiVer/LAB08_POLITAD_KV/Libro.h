/* 
 * Archivo:   Libro.h
 * Autor:     VinKzzlo
 *
 * Creado el  21 de noviembre de 2024, 20:10
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char* nombre;
    int paginas;
    double peso;
    
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(char* nomb);
    void GetNombre(char *cad) const;
    char * leeCadenaExacta(ifstream &arch, char delim='\n');
    virtual void lee(ifstream &arch);
    virtual void actualiza()=0;
    virtual void imprime(ofstream &arch);
};

#endif /* LIBRO_H */

