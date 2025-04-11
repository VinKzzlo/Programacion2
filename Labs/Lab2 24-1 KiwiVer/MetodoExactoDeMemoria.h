/* 
 * Archivo:   MetodoExactoDeMemoria.h
 * Autor:     VinKzzlo
 *
 * Creado el  12 de septiembre de 2024, 16:06
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerDatLibro(ifstream &arch);
int *leerStock(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,char delim);

void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
void imprimeLibro(char **libro,int *stock,ofstream &arch);

void atencionDePedidos(const char *nombArch,char ***libros, int **stock,
                       int **&pedidosClientes, char ***&pedidosLibros, 
                       bool **&pedidosAtendidos);
void inicializarBuffers(int **buffPedCli,char ***buffPedLib, bool **buffPedAtend);
void asignarPedidoACliente(int numPed,int dni,int **buffPedCli,int &cantCli);
int buscarCliente(int dni,int **buffPedCli,int cantCli);
void asignarLibros(char *codLib,char **buffPedLib,bool *buffPedAtend,
                   int &cantLib, char ***libros,int **stock);
int buscarLibro(char ***libros,char *codLib);
#endif /* METODOEXACTODEMEMORIA_H */

