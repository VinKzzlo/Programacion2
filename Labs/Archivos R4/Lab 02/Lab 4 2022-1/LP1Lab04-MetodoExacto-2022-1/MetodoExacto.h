/* 
 * File:   MetodoExacto.h
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 11 de abril de 2024, 11:04
 */
#include <fstream>
using namespace std;
#ifndef METODOEXACTO_H
#define METODOEXACTO_H
//Carga de Clientes
void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria);
void arreglarNombre(char *nombre,char &categoria);
void cargaArrClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria,
                      int *buffDni,char **buffNomb,char *buffCat,int n);
//Reporte de Clientes
void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria);
//Carga de Pedidos y Productos
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
            char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
            int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido);
void leePedidos(ifstream &arch,char *&descrip,double &dsct,double &cant,
                double &prec,int &dni,int &fecha);
char *leeCadenaExacta(ifstream &arch,int max,char c);
int juntarFecha(int dd,int mm,int aa);
int buscarPosicionDni(int *cli_DNI,int dni);
void completarCliente(int *&arrCodProFecPed,double *&arrCantPed,
                      int codProd,int fecha,double cantidad,int &cantPed);
int buscarPosicionProd(int *buffProd,int codProd,int cant);
void agregarProducto(int &buffcodprod,char *&buffdescrip,double &buffdsct,
                     double &buffprec,int codProd,char *descrip,double dsct,
                     double prec,int &i);
void cargaArrProductos(int *&pro_Codigo,char **&pro_Descripcion,
                       double *&pro_Descuento,double *&pro_Precio,int *buffCod,
                       char **buffDesc,double *buffDsct,double *buffPrec,int n);
void segundaCargaClientes(int *cli_DNI,int **&cli_CodigoProFechaPedido,
                          double **&cli_CantidadPedido,int **buffCodProdFecPed,
                          double **buffCantPed,int *numPed);
void cargaNivelInterno(int *&cliCodProFechaPed,double *&cliCantPed,
                       int *buffCodProFechaPed,double *buffCantPed,int cantPed);
//Reporte de Pedidos y Productos
void ReporteDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
                char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
                int **cli_CodigoProFechaPedido,double **cli_CantidadPedido);
void imprimePedidos(ofstream &archRep,int *codFecha,double *cant);
//Reporte de Relacion de Pedidos
void ReporteRlacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,
                    int **cli_CodigoProFechaPedido,double **cli_CantidadPedido,
                    int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,
                    double *pro_Precio);
void hallarDescripPrecio(int *codProd,char **arrDescrip,double *arrPrecio,
                         double *arrDesc,char *&descripcion,double &precio,
                         double &descuento,int codigo);
void imprimeFecha(int fecha,ofstream &arch);
void imprimirProductosCliente(int *arrCodFecha,
                    double *arrCant,ofstream &archRep,int *codProd,
        char **arrDescrip,double *arrPrecio,double *arrDesc);
void imprimeCabecera(ofstream &archRep);
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeCabeceraCliente(ofstream &arch,int dni,char *nombre,char cat);
#endif /* METODOEXACTO_H */
