/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:06
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

