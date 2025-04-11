/* 
 * File:   PunterosGenericos.h
 * Author: n422
 *
 * Created on 23 de abril de 2024, 01:51 PM
 */
#include <fstream>
using namespace std;
#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
//Cargar clientes
void cargaClientes(void *&clientes);
void *leerClientes(ifstream &archCli);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
//Cargar libros
void cargaLibros(void *&libros);
void *leerLibros(ifstream &archLib);
//Cargar pedidos
void cargaPedidos(void *clientes,void *libros);
int buscarPosLib(void *libros,char *codigo);
int buscarPosCli(void *clientes,int dni);
void agregaPedido(void *&cliente,void *&libro);
//Imprimir reporte
void imprimeReporte(void *clientes);
#endif /* PUNTEROSGENERICOS_H */
