/* 
 * File:   main.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 *
 * Created on 11 de abril de 2024, 11:03
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExacto.h"
int main(int argc, char** argv) {
    
    char **cli_Nombre,*cli_Categoria,**pro_Descripcion;
    int *cli_DNI,**cli_CodigoProFechaPedido,*pro_Codigo;
    double *pro_Precio,*pro_Descuento,**cli_CantidadPedido;
    
    //Carga de Clientes
    CargaDeClientes(cli_DNI,cli_Nombre,cli_Categoria);
    //Reporte de Clientes
    ReporteDeClientes(cli_DNI,cli_Nombre,cli_Categoria);
    //Carga de Pedidos y Productos
    CargaDePedidosYProductos(cli_DNI,pro_Codigo,pro_Descripcion,pro_Descuento,
                        pro_Precio,cli_CodigoProFechaPedido,cli_CantidadPedido);
    //Reporte de Pedidos y Productos
    ReporteDePedidosYProductos(cli_DNI,pro_Codigo,pro_Descripcion,pro_Descuento,
                        pro_Precio,cli_CodigoProFechaPedido,cli_CantidadPedido);
    //Reporte de Relacion de Pedidos
    ReporteRlacionDePedidos(cli_DNI,cli_Nombre,cli_Categoria,
                        cli_CodigoProFechaPedido,cli_CantidadPedido,pro_Codigo,
                        pro_Descripcion,pro_Descuento,pro_Precio);
    
    return 0;
}

