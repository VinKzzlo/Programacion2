/* 
 * Archivo: ConjuntoDePedidos.hpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#ifndef CONJUNTODEPEDIDOS_HPP
#define CONJUNTODEPEDIDOS_HPP

#include <iostream>
#include <fstream>
#include "Pedido.hpp"
#define CLIENTE_NO_ENCONTRADO -1
#define MAXIMO_POR_LINEA 40

using namespace std;

struct ConjuntoDePedidos{
    int **enteros;
    char ***cadenas;
    double **reales;    
};

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo);

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos);

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad);

void inicializarConjuntoDePedidos(int *&enteros,char **&cadenas,
                                     int dni_cliente,const char *codigo_repartidor);

void actualizarDatos(int *enteros,char **cadenas,int cantidad_platos, 
                     const char *codigo_plato);

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido);

void memoriaExactaEnterosCadenas(int *&enteros,char **&cadenas);

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos);

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni);

void actualizarPrecioPedido(double *&reales,int *enteros,char **cadenas,
                            const struct ConjuntoDePlatos &conjuntoDePlatos);

void operator++(ConjuntoDePedidos &conjuntoDePedidos);

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int);

void liberar_cadenas(char **cadenas);

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos);

void cambiarCodigoPorNombre(char **cadenas,const struct ConjuntoDePlatos &conjuntoDePlatos);

void operator!(ConjuntoDePedidos &conjuntoDePedidos);

void operator*(const ConjuntoDePedidos &conjuntoDePedidos);

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero);

void imprimir_linea(ofstream &archDeReporte, char c = '=');

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos);

#endif /* CONJUNTODEPEDIDOS_HPP */

