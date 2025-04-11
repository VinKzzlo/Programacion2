/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: ramir
 *
 * Created on 23 de abril de 2024, 10:49
 */
#include <fstream>
using namespace std;
#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leenum(ifstream &arch);
int cmpnum(void *a,void *b);
void imprimenum(void *dato,ofstream &arch);

#endif /* LISTACONENTEROS_H */
