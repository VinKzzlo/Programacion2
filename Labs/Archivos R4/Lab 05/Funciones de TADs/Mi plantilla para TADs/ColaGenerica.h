/* 
 * File:   ColaGenerica.h
 * Author: ramir
 *
 * Created on 1 de mayo de 2024, 20:31
 */
#include <fstream>
using namespace std;
#ifndef COLAGENERICA_H
#define COLAGENERICA_H

void creaCola(void *&cola,void*(*lee)(ifstream &),int(*cmp)(void *,void *),
              const char *nombArch);
void generacola(void *&cola);
void encola(void *cola,void *dato,int(*cmp)(void *,void *));
bool colavacia(void *cola);
void *desencola(void *cola);

#endif /* COLAGENERICA_H */
