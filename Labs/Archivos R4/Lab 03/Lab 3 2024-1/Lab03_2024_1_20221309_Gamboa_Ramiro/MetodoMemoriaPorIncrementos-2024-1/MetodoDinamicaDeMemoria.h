/* 
 * File:   MetodoDinamicaDeMemoria.h
 * Author: ramir
 *
 * Created on 11 de mayo de 2024, 02:42
 */
#include <fstream>
#ifndef METODODINAMICADEMEMORIA_H
#define METODODINAMICADEMEMORIA_H

//Lectura de Libros
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerRegistroLib(ifstream &archLib);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
int *leerRegistroStk(ifstream &archLib);
void aumentarCapLibros(char ***&libros,int **&stock,int &numDatos,int &capacidad);
void agregarLibros(char ***libros,int **stock,char **registroLib,
                   int *registroStk,int &numDatos);
//Prueba de Lectura de Libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
//Atencion de Pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
int buscarPosCliente(int **pedidosClientes,int dni);
void aumentarCapPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                       int &numDatos,int &capacidad);
void cambiarAuxAPunteroPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                              int numDatos,int capacidad);
void agregarCliente(int **pedidosClientes,int *numPed,int *capPed,int &numDatos,
                    int &indice,int dni);
void agregarCapacidadPed(int *&pedCliente,int dni,int &numDatos,int &capacidad);
void agregarPedidoCli(int *&pedCliente,int numPed,int &numDatos,int &capacidad);
void aumentarCapPedCliente(int *&pedCliente,int numDatos,int &capacidad);
void aumentarCapPedLib(char ***&pedidosLibros,bool **&pedidosAtendidos,
                       int &numDatos,int capacidad);
void aumentarCapLibEnPed(char **&pedLibro,bool *&pedAtendido,int &numDatos,
                         int &capacidad);
int buscarPosLibro(char ***libros,char *codigo);
bool verificarStock(int *stock);
void agregarLibYAten(char **pedLibro,bool *pedAtendido,char *codigo,
                     bool tieneStock,int &numDatos);
void agregarCantDePedidos(int **pedidosClientes,int *numPed);
//Ordenacion
void ordenarPedidosClientes(int **pedidosClientes);
void qSort(int **pedidosClientes,int izq,int der);
void cambiar(int *&pedidosClientesI,int *&pedidosClientesK);
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos);
void imprimirTitulo(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);
void imprimirEncabezadoCliente(ofstream &archRep);

#endif /* METODODINAMICADEMEMORIA_H */
