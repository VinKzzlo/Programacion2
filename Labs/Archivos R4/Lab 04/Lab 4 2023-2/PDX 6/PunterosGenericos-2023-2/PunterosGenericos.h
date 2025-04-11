
/*/ 
 * Projecto:  PunterosGenericos-2023-2
 * Nombre del Archivo:  funciones.h
 * Autor: void *heart = nullptr;
/*/

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

                /*  - / > [ Declaracion de Funciones ] < / -  */

void cargarproductos(void *&);

void *obtenerRegistrosDeProducto(ifstream &);

void cargarclientes(void *&);

void *obtenerRegistrosDeCliente(ifstream &);

void cargarpedidos(void *,void *);

void actualizarListaDePedidos_Cli(void *,void *,int);

void insertarRegistroDePedido(void *,void *&);

void compactarSubRegistros_Cli(void *&,void **);

void compactarRegistrosDePedidos(void *&);

void imprimereporte(void *);

void imprimirPedidosAtendidosDeCliente(ofstream &,void *);

ifstream abrirArchivo_IFS(const char *);

ofstream abrirArchivo_OFS(const char *);

char *obtenerCadenaExacta(ifstream &,char);

void almacenarRegistrosExactos(void *&,void **,int);

int obtenerPosCli(int,void **);

bool validarCliente(int,void *);

int obtenerPosProd(char *,void **);

bool validarProducto(char *,void *);

void imprimirEncabezado(ofstream &,int,char);

void imprimirLinea(ofstream &,int,char);

void imprimeProductos(void *);

void imprimirRegistrosDeProducto(ofstream &,void *);

void imprimeClientes(void *);

void imprimirRegistrosDeCliente(ofstream &,int,void *,bool);

void imprimirSubRegistrosDeCliente_Ped(ofstream &,void *);

#endif /* PUNTEROSGENERICOS_H */
