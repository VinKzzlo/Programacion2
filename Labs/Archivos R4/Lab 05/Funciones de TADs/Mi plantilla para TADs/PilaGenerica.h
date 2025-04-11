/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PilaGenerica.h
 * Author: ramir
 *
 * Created on 1 de mayo de 2024, 20:31
 */
#include <fstream>
using namespace std;
#ifndef PILAGENERICA_H
#define PILAGENERICA_H

void generapila(void *&pila);
void push(void *pila,void *dato);
void *pop(void *pila);
bool pilavacia(void *pila);

#endif /* PILAGENERICA_H */
