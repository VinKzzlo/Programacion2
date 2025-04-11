/* 
 * File:   PunterosGenericos.h
 * Author: ramir
 *
 * Created on 25 de abril de 2024, 13:18
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
int buscarPosProd(void **lproductos,char *codigo);
int buscarPosCli(void **lclientes,int dni);
void agregarPedidos(void *cliente,void *producto,int cant);
void insertarPedidoEnCliente(void *&dirPed,void *registroPed);
void crearMemoriaExacta(void *&clientes,void **lclientes);
void ajustarArreglo(void *&dirPed);
#endif /* PUNTEROSGENERICOS_H */
