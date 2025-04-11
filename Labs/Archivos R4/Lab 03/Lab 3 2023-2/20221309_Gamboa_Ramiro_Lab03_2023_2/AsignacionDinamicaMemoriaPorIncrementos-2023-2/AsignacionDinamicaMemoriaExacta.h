/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 8 de abril de 2024, 15:29
 */
#include <fstream>
using namespace std;
#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
//Lectura de Productos
void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios);
char **leeRegistro(ifstream &archProd);
char *leeCadenaExacta(ifstream &arch,int max,char delim);
void aumentarCapacidad(char ***&productos,int *&stock,double *&precios,
                       int &numDatos,int &capacidad);
void agregarProductos(char ***&productos,int *&stock,double *&precios,
                      char **registro,int cant,double precio,int &numDatos);
//Prueba de Lectura de Productos
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios);
//Lectura de Pedidos
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos);
int *leeDniYCant(ifstream &archPed);
int juntarFecha(int dd,int mm,int aa);
void aumentarCapFecha(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&capPed,
                      int &numDatos,int &capacidad);
void cambiarAuxAPuntero(int *&fechaPedidos,char ***&codigoPedidos,
                        int ***&dniCantPedidos,int *&numPed,int *&capPed,
                        int numDatos,int capacidad);
int buscarFecha(int *fechaPedidos,int fecha);
void agregarFecha(int *&fechaPedidos,char ***&codigoPedidos,
                  int ***&dniCantPedidos,int *&numPed,int *&capPed,
                  int fecha,int &indice,int &numDatos);
void aumentarCapPedidos(char **&codigoPedidos,int **&dniCantPedidos,
                        int &numDatos,int &capacidad);
void agregarPedido(char **&codigoPedidos,int **&dniCantPedidos,int &numPed,
                   int &capPed,int *dniCant,char *codigo);
//Prueba de Lectura de Pedidos
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos);
//Ordenamiento
void ordenar(int *fechaPedidos,char ***productos,int ***dniCantPedidos);
void qSort(int *fechaPedidos,char ***productos,int ***dniCantPedidos,int izq,
           int der);
void cambiar(int &fechaPedidosI,char **&productosI,int **&dniCantPedI,
             int &fechaPedidosJ,char **&productosJ,int **&dniCantPedJ);
//Reporte de Envio de Pedidos
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,
                             int *stock,double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos);
void imprimirTitulo(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);
void imprimirCabeceraFecha(ofstream &archRep,int fecha);
void separarFecha(int fecha,int &dd,int &mm,int &aa);
int buscarProducto(char ***productos,char *codigo);
void imprimirFecPed(ofstream &archRep,char **productos,int &stock,double precio,
                    int *dniCant,double &totIngr,double &totPerd);
void imprimirResumenFecha(ofstream &archRep,double fechatotIngresado,
                          double fechatotPerdido);
void imprimirResumenGeneral(ofstream &archRep,double resumTotIngr,
                            double resumTotPerd);
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
