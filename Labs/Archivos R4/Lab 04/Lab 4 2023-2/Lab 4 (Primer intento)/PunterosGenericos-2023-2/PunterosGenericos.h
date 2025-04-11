/* 
 * File:   PunterosGenericos.h
 * Author: ramir
 *
 * Created on 21 de abril de 2024, 01:23
 */
#include <fstream>
using namespace std;
#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
//Carga de productos
void cargaproductos(void *&productos);
void *LeerProductos(ifstream &archProd);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
//Carga de clientes
void cargaclientes(void *&clientes);
void *LeerClientes(ifstream &archCli);
//Carga de pedidos
void cargapedidos(void *productos,void *clientes);
//Imprimir reporte
void imprimereporte(void *clientes);
#endif /* PUNTEROSGENERICOS_H */
