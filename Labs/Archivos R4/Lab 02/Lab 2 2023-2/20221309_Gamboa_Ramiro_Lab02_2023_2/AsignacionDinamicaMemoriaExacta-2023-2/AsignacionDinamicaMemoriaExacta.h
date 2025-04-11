/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 5 de abril de 2024, 23:41
 */
#include <fstream>
using namespace std;
#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
//Lectura de Productos
void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios);
char **leerProductos(ifstream &archProd);
char *leeCadena(ifstream &archProd,int max,char delim);
//Prueba de Lectura de Productos
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios);
//Lectura de Pedidos
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos);
int juntarFecha(int dd,int mm,int aa);
int buscarFecha(int *buffFecha,int fecha,int n);
void agregarFecha(int *buffFecha,char ***buffCodPed,int ***buffCantPed,
                  int fecha,int *numPed,int &indice,int &i);
void agregarPedido(char **buffcod,int **buffdni,int &n,int dni,int cant,
                   char *codigo);
void cargarArreglos(int *&fechaPedidos,char ***&codigoPedidos,
                    int ***&dniCantPedidos,int *buffFecha,char ***buffCodPed,
                    int ***buffCantPed,int *numPed,int cantFecha);
void cargaNivelInterno(char **&codigoPed,int **&dnicantped,char **buffcodped,
                       int **buffcantped,int cantPed);
//Prueba de Lectura de Pedidos
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos);
//Reporte de Envio de Pedidos
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
                             double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos);
void imprimirLinea(ofstream &archRep,char c);
void separarFecha(int fecha,int &dd,int &mm,int &aa);
int buscarProducto(char ***productos,char *codProd);
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
