/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    struct ConjuntoDePedidos buffConjPedidos;
    inicializar_buffer_de_conjunto_de_pedidos(buffConjPedidos,200);
    while(true){
        struct Pedido pedLeido;
        if(!(archivo_de_pedidos>>pedLeido)) break;
        buffConjPedidos<<pedLeido;
    }
    buffConjPedidos>>conjuntoDePedidos;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad]; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}
void inicializarConjPedidos(int *&enteros,char **&cadenas,int dni,
                            const char *codRep){
    enteros = new int[50]{};
    cadenas = new char*[50]{};
    enteros[0] = dni;
    cadenas[0] = new char[strlen(codRep)+1];
    strcpy(cadenas[0],codRep);
}
void actualizarDatos(int *enteros,char **cadenas,int cantPlatos,
                     const char *codPla){
    int n=enteros[1]; //cantPlatos;
    enteros[n+2] = cantPlatos;
    cadenas[n+1] = new char[strlen(codPla)+1];
    strcpy(cadenas[n+1],codPla);
    enteros[1]++;
}
void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int posCliente;
    posCliente = buscar_cliente(buffer_de_conjuntoDePedidos,pedido.dni_cliente);
    if(posCliente == CLIENTE_NO_ENCONTRADO){
        //Si no se encontró, añadir cliente al último
        posCliente = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
        inicializarConjPedidos(buffer_de_conjuntoDePedidos.enteros[posCliente],
                               buffer_de_conjuntoDePedidos.cadenas[posCliente],
                               pedido.dni_cliente, pedido.codigo_repartidor);
    }
    actualizarDatos(buffer_de_conjuntoDePedidos.enteros[posCliente],
                    buffer_de_conjuntoDePedidos.cadenas[posCliente],
                    pedido.cantidad_platos, pedido.codigo_plato);
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    int cantidad;
    cantidad=obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
    inicializar_buffer_de_conjunto_de_pedidos(conjuntoDePedidos,cantidad+1);
    for(int i=0;i<cantidad;i++){
        conjuntoDePedidos.enteros[i]=buffer_de_conjuntoDePedidos.enteros[i];
        conjuntoDePedidos.cadenas[i]=buffer_de_conjuntoDePedidos.cadenas[i];
    }
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos){
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}