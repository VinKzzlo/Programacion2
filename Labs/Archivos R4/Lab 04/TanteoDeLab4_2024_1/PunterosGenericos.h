/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: ISA
 *
 * Created on 25 de abril de 2024, 09:50 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;
void cargarLibros(void *&libros,const char* nomArch);
void* leerLibro(ifstream &arch);
char* LeerCadenaExacta(ifstream &arch,int max,char c);

void reporteLibros(void *libros,const char* nomArch);
void ImprimirLibros(ofstream &arch,void *leer_libro);

void cargarClientes(void *&clientes,const char* nomArch);
void* leerCliente(ifstream &arch);

void reporteClientes(void *clientes,const char* nomArch );
void ImprimirIDClientes(ofstream &arch,void *cliente);

void cargarPedidos(void *clientes, void *libros,const char* nomArch);
int BuscarCliente(int dni,void *clientes);
int BuscarLibro(char *cod,void *libros);
void ActualizarInformacion(void *cliente,char *cod);
void* AsignarEspacioProducto(char *cod);
void actualizarPedidos(void *libros, void *clientes);
void RecorrerPedidos(void *arr_productos,void *cantidad_productos,
                void *total_gastos,void *libros);
double CompletarInformacionProducto(void *&reg_nombre,void *&reg_precio,
        void *libro);

void reporteFinal(void *clientes,const char* nomArch);
void ImprimirClientes(ofstream &arch,void *cliente);
void ImprimirProducto(ofstream &arch,void* pedido);
void ImprimirLinea(ofstream &arch,int n,char c);

#endif /* PUNTEROSGENERICOS_H */
