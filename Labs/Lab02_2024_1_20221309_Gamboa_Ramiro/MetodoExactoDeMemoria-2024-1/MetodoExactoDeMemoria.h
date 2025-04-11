/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: ramir
 *
 * Created on 29 de julio de 2024, 10:13 PM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

//Lectura de libros
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerLibros(ifstream &archLib);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
int *leerStock(ifstream &archLib);
//Prueba de Lectura de Libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
//Atencion de Pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
int buscarCliente(int **buffPedCli,int dni);
void agregarCliente(int *&buffpedcli,int dni,int &posCli,int &cantCli);
void agregarPedido(int *buffpedcli,int numPed);
void leerPedidos(ifstream &archPed,char ***libros,int **stock,
                 char **&buffPedLib,bool *&buffPedAten,int &cantLib);
int buscarLibro(char ***libros,char *codLib);
void modificarPedidoAtendido(int *stock,bool &seAtendio);
void cargarArreglos(int **&pedidosClientes,char ***&pedidosLibros,
                   bool **&pedidosAtendidos,int **buffPedCli,char ***buffPedLib,   
                   bool **buffPedAten,int cantCli,int cantPed,int *cantLibEnPed);
void cargaClienteNivelInterno(int *pedidoscliente,int *buffpedcli);
void cargaPedidoNivelInterno(char **pedidoslibros,bool *pedidosatendidos,
                             char **buffpedlib,bool *buffpedaten,int n);
//Reporte de Entrega de Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,
                               char ***pedidosLibros,bool **pedidosAtendidos);
void imprimirTitulo(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);
void imprimirEncabezadoCliente(ofstream &archRep);

#endif /* METODOEXACTODEMEMORIA_H */
