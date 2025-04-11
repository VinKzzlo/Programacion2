/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Bleak
 *
 * Created on September 12, 2024, 9:27 PM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros (const char *nomb,char ***&libros, int **&stock);
char **obtienelibro(ifstream &arch);
int *obtienestock(ifstream &arch);
char *leecadenaexacta(ifstream &arch, char delim);
void pruebaDeLecturaDeLibros (const char *nomb,char ***libros, int **stock);
void atencionDePedidos (const char *nomb, char ***libros, int **stock, int **&pedidosClientes,
        char ***&pedidosLibros, bool **&pedidosAtendidos);
void guardacliente(int cliente,int pedido, int **buffpedcli,int &ncli, int *tampedcli);
int buscacli(int cliente, int **buffpedcli);
void guardarlibro(char **buffpedlib,char *cod, bool *buffpedAt,int &n, char ***libros, int **stock);
int buscaLibro(char ***libros, char *cod);
char *leecadena(ifstream &arch);
void cargapedlib(char ***buffpedlib,bool **buffpedAt,int *tampedlib,int nped,char ***&pedidosLibros,bool **&pedidosAtendidos);
void cargapedcli(int **buffpedcli,int *tampedcli,int ncli,int **&pedidosClientes);
void reporteDeEntregaDePedidos (const char *nomb, int **pedidosClientes, char ***pedidosLibros,bool **pedidosAtendidos);
void imprimePorLibro(int *pedidos, char ***pedLib, bool **pedAt, ofstream &arch);
void imprimirlinea(char simbolo, int cant, ofstream &arch);

#endif /* METODOEXACTODEMEMORIA_H */
