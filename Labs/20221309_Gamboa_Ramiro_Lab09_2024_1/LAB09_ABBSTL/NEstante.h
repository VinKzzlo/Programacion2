/* 
 * File:   NEstante.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:23
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <vector>

class NEstante {
public:
    NEstante();
    NEstante(const NEstante& orig);
    virtual ~NEstante();
    friend class Arbol;
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void leerLibros(ifstream &);
    void muestra(ofstream &archRep);
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro>vlibros;
    NEstante *izq;
    NEstante *der;
    void imprimirLinea(ofstream &,char);
};

#endif /* NESTANTE_H */

