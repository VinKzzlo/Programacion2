/* 
 * File:   BibGenerica.h
 * Author: ramir
 *
 * Created on 27 de abril de 2024, 21:19
 */

#include <fstream>
using namespace std;

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

void creacola(void *&cola,void*(*lee)(ifstream &),int(*prioridad)(void*),
              const char *nombArch);
void generacola(void *&cola);
void encola(void *cola,void *dato,int(*buscarPosPrioridad)(void*));
bool colavacia(void *cola);
void encolaprioridad1(void *cola,void **nuevo);
void encolaprioridad2(void *cola,void **nuevo);
void encolaprioridad3(void *cola,void **nuevo);
void *desencola(void *cola);

#endif /* BIBGENERICA_H */
