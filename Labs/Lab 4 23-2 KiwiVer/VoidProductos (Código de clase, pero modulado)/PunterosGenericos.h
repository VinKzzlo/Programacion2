/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: cueva.r
 *
 * Created on 17 de septiembre de 2024, 10:15 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H 
#include <fstream>
using namespace std;

    void cargaproductos(void *&productos);
    void *leeproducto(ifstream &arch);
    char *leercadena(ifstream &arch,int max,char carsep);
    void imprimereg(ofstream &arch,void*registro);
    void imprimeproducto(void *producto);
    void *leecliente(ifstream &arch);
    void cargaclientes(void *&clientes);
    void cargapedidos(void *productos,void *clientes);
    void insertapedido(void *pedidos,int &pos,char *codigo,
        int *cantidad,double precio);
    int buscacliente(int dni,void *clientes,double &linea);
    double buscaprecio(char *codigo,void *productos,
        char &estado);
    
#endif /* PUNTEROSGENERICOS_H */
