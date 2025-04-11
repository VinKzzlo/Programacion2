/* 
 * Archivo:   PunterosGenericos.h
 * Autor:     VinKzzlo
 *
 * Creado el  26 de septiembre de 2024, 12:43
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaproductos(void *&productos);
void *leeProducto(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,char delim='\n');
void cargaclientes(void *&clientes);
void *leeCliente(ifstream &arch);
void cargapedidos(void *productos,void *clientes);
int buscarCliente(void *clis,int dni);
int buscarProducto(void *prods, char *codigo);
void agregarPedido(void *prod,void *cli,int cant);
void insertarPedidoEnCliente(void *&pedidos,void *regPed);
void ajustarListaPedidos(void *&listaPed);
void ordenarClientesKiwi(void *cli);
void qSortKiwi(void *cli,int izq,int der);
void cambiarKiwi(void *&clienteI, void *&clienteK);
bool estanEnDesordenKiwi(void *clieI, void *clieK);
#endif /* PUNTEROSGENERICOS_H */

