/* 
 * File:   Arbol.h
 * Author: alulab14
 *
 * Created on 21 de junio de 2024, 10:14
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "NEstante.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void crea(ifstream &);
    void insertarR(class NEstante*&,class NEstante*);
    void muestraEstantes(ofstream &);
    void verificaSiEntra(ofstream &,double);
private:
    NEstante *raiz;
    void imprimeEstantes(ofstream &,class NEstante*);
    void imprimePrueba(ofstream &,class NEstante*,double);
};

#endif /* ARBOL_H */

