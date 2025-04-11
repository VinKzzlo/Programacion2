/* 
 * File:   FlotaGenerica.h
 * Author: ramir
 *
 * Created on 1 de mayo de 2024, 23:51
 */
#include <fstream>
using namespace std;
#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void cargacamiones(void *&flota,int numcamiones,double pesomaximo,
                   void*(*lee)(ifstream &),double(*calcula)(void *),
                   const char *nombArch);

#endif /* FLOTAGENERICA_H */
