/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   metodoExacto.h
 * Author: n421
 *
 * Created on 12 de abril de 2024, 01:10 PM
 */
/*
 * nombre: Jefferson Robles Cervantes
 * codigo: 20185878
 */
#include <fstream>
using namespace std;

#ifndef METODOEXACTO_H
#define METODOEXACTO_H

void leerLibros(const char*nombreArch,char ***&libros,int **&stock);
char *leercadena(ifstream &arch);
void asignarEspacioGuardarDatos(char ***bufferLibros,int **bufferStock,int numDat,char *codLibro,char *titulo,char *autor,int cant);
void pruebaLecturaLibros(const char*nombreArch,char ***libros,int **stock);
void leerPedidos(const char*nombreArch,char ***libros,int **&stock,int **&PedidosClientes,char ***&PedidosLibros,bool **&PedidoEstado);
int buscarCliente(int dniCliente,int **bufferPedCli,int numDat);
int buscarLibro(char ***libros,char *codLibro);
void agregarOActualizarClientes(int **bufferPedCli,int dniCliente,int codPedido,int posCliente,int &numDat);
void actualizarStockYEstado(int posLibro,int **&stock,bool **bufferEstado,int cantidadLibros,int codPedido);
void asignarMemoriaYGuardatosPedClientesLibrosEstado(int **&PedidosClientes,char ***&PedidosLibros,bool **&PedidoEstado,int **bufferPedCli,char ***bufferPedLibros,bool **bufferEstado,int numDat,int cantPedidos,int *cantLibros);
void imprimirReporte(const char*nombreArch,char ***libros,int **stock,int **PedidosClientes,char ***PedidosLibros,bool **PedidoEstado);
void imprimirLinea(ofstream &arch,char car,int limite);
#endif /* METODOEXACTO_H */

