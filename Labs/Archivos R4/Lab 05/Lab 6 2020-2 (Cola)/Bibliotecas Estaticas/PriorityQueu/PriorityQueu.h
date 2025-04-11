/* 
 * File:   PriorityQueu.h
 * Author: ramir
 *
 * Created on 13 de mayo de 2024, 22:07
 */
#include <fstream>
using namespace std;
#ifndef PRIORITYQUEU_H
#define PRIORITYQUEU_H

void creaCola(void *&cola,void*(*lee)(ifstream &),int(*prioridad)(void *),
              const char *nombArch);
void generacola(void *&cola);
void encolar(void *cola,void *dato,int(*prioridad)(void *));
bool colavacia(void *cola);
void prueba(void *cola,void(*imprime)(ofstream &,void *),const char *nombArch);
void *desencola(void *cola);

#endif /* PRIORITYQUEU_H */
