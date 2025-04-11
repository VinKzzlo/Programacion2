/* 
 * File:   PunterosGenericos.h
 * Author: ramir
 *
 * Created on 26 de abril de 2024, 08:15
 */
#include <fstream>
using namespace std;
#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
//Carga de productos
void cargaproductos(void *&productos);
void *leerProductos(ifstream &archProd);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
//Carga de clientes
void cargaclientes(void *&clientes);
void *leerClientes(ifstream &archCli);
//Carga de pedidos
void cargapedidos(void *productos,void *clientes);
int buscarPosCliente(void *clientes,int dni);
int buscarPosProductos(void *productos,char *codigo);
void agregaPedido(void *cliente,void *producto,int cant);
#endif /* PUNTEROSGENERICOS_H */
