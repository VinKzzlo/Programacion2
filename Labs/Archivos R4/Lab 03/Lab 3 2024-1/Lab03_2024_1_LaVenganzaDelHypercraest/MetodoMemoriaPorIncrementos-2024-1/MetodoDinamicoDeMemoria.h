/* 
 * File:   MetodoDinamicoDeMemoria.h
 * Author: ramir
 *
 * Created on 4 de mayo de 2024, 16:39
 */
#include <fstream>
using namespace std;
#ifndef METODODINAMICODEMEMORIA_H
#define METODODINAMICODEMEMORIA_H
//Lectura de Libros
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerRegistroLib(ifstream &archLib);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
int *leerRegistroStk(ifstream &archLib);
void aumentarCapLibros(char ***&libros,int **&stock,int &numDatos,int &capacidad);
void agregarLibros(char ***libros,int **stock,char **registroLib,
                   int *registroStk,int &numDatos);
//Prueba de lectura de libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
//Atencion de pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **&stock,
                       int **&pedidosClientes,char ***&pedidosLibros,
                       bool **&pedidosAtendidos);
int buscarPosCliente(int **pedidosClientes,int dni);
void aumentarCapPedCli(int **&pedidosClientes,int *&numDatosPed,
                       int *&capacidadPed,int &numDatos,int &capacidad);
void cambiarAuxAPuntPedCli(int **&pedidosClientes,int *&numDatosPed,
                           int *&capacidadPed,int numDatos,int capacidad);
void agregarCliente(int **&pedidosClientes,int *numDatosPed,int *capacidadPed,
                    int &numDatos,int &indice,int dni);
void agregarCapacidad(int *&pedCliente,int dni,int &numDatos,int &capacidad);
//Ordenar pedidos clientes
void ordenarPedidosClientes(int **&pedidosClientes);
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos);
#endif /* METODODINAMICODEMEMORIA_H */
