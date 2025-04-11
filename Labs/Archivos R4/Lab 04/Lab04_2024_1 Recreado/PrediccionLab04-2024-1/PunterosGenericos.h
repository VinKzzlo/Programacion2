/* 
 * File:   PunterosGenericos.h
 * Author: ramir
 *
 * Created on 25 de abril de 2024, 23:12
 */
#include <fstream>
using namespace std;
#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
//Carga de clientes
void cargaclientes(void *&clientes);
void *leerClientes(ifstream &archCli);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
//Carga de libros
void cargalibros(void *&libros);
void *leerLibros(ifstream &archLib);
//Carga de pedidos
void cargapedidos(void *clientes,void *libros);
#endif /* PUNTEROSGENERICOS_H */
