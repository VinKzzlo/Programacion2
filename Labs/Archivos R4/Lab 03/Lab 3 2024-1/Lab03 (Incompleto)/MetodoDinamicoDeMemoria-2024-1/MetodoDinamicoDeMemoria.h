/* 
 * File:   MetodoDinamicoDeMemoria.h
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 20 de abril de 2024, 03:33
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
//Prueba de Lectura de Libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
//Atencion de Pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **&stock,
                       int **&pedidosClientes,char ***&pedidosLibros,
                       bool **&pedidosAtendidos);
int buscarPosCliente(int **pedidosClientes,int dni);
void aumentarCapPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                       int &numDatos,int &capacidad);
void cambiarAuxAPuntPedCli(int **&pedidosClientes,int *&numPed,int *&capPed,
                           int numDatos,int capacidad);
void agregarCliente(int **&pedidosClientes,int *numPed,int *capPed,int &numDatos,
                    int &indice,int dni);
void agregarCapacidad(int *&pedCliente,int dni,int &numDatos,int &capacidad);
void agregarPedidos(int *&pedCliente,int &numDatos,int &capacidad,int numPed);
void aumentarCapPedidos(int *&pedCliente,int numDatos,int &capacidad);
void aumentarCapPedLib(char ***&pedidosLibros,bool **&pedidosAtendidos,
                       int codPed,int &numLib);
void aumentarCapLibEnPed(char **&pedLibros,bool *&pedAtendidos,int &numDatos,
                         int &capacidad);
int buscarPosicionLib(char ***libros,char *codigo);
bool verificarStock(int *stock);
void agregarLibYAten(char **pedLibros,bool *pedidosAtendidos,char *codigo,
                     bool tieneStock,int &numDatos);
void agregarCantDePedidos(int **pedidosClientes,int *numPed);
//Ordenamiento
void ordenar(int **pedCli);
void qSort(int **pedCli,int izq,int der);
void cambiar(int *&pedCliI,int *&pedCliK);
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos);
void imprimirTitulo(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);
void imprimirEncabezadoCliente(ofstream &archRep);
#endif /* METODODINAMICODEMEMORIA_H */
