/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string.h>
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
    struct Pedido pedido;
    struct ConjuntoDePedidos buffer_de_conjunto_de_pedidos;
    inicializar_buffer_de_conjunto_de_pedidos(buffer_de_conjunto_de_pedidos,200);
    while(true){
        archivo_de_pedidos>>pedido;
        if(archivo_de_pedidos.eof())break;
        buffer_de_conjunto_de_pedidos<<pedido;
    }
    buffer_de_conjunto_de_pedidos>>conjuntoDePedidos;
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

void inicializarConjuntoDePedidos(int *&enteros,char **&cadenas,
                                     int dni_cliente,const char *codigo_repartidor){
    enteros=new int[50]{};
    cadenas=new char*[50]{};
    enteros[0]=dni_cliente;
    cadenas[0]=new char[strlen(codigo_repartidor)+1]{};
    strcpy(cadenas[0],codigo_repartidor);
}

void actualizarDatos(int *enteros,char **cadenas,int cantidad_platos, 
                     const char *codigo_plato){
    int n=enteros[1];
    enteros[n+2]=cantidad_platos;
    cadenas[n+1]=new char[strlen(codigo_plato)+1]{};
    strcpy(cadenas[n+1],codigo_plato);
    enteros[1]++;
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int pos=buscar_cliente(buffer_de_conjuntoDePedidos,pedido.dni_cliente);
    if(pos==-1){//No se encontro (agrega)
        pos=0;
        //Busca el ultimo elemento para agregarlo ahi
        while(buffer_de_conjuntoDePedidos.enteros[pos])pos++;
        inicializarConjuntoDePedidos(buffer_de_conjuntoDePedidos.enteros[pos],
                                     buffer_de_conjuntoDePedidos.cadenas[pos],
                                     pedido.dni_cliente,
                                     pedido.codigo_repartidor);
    }
    actualizarDatos(buffer_de_conjuntoDePedidos.enteros[pos],
                    buffer_de_conjuntoDePedidos.cadenas[pos],
                    pedido.cantidad_platos,pedido.codigo_plato);
}

void memoriaExactaEnterosCadenas(int *&enteros,char **&cadenas){
    int n=enteros[1]+2;
    //ENTEROS
    int *auxInt=new int[n+1]{};
    for (int i = 0; i < n; i++) {
        auxInt[i]=enteros[i];
    }
    delete enteros;
    enteros=auxInt;
    //CADENAS
    char **auxChar=new char*[n]{};
    for (int i = 0; i < n-1 ; i++) {
        auxChar[i]=cadenas[i];
    }
    delete cadenas;
    cadenas=auxChar;
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    conjuntoDePedidos.cadenas=buffer_de_conjuntoDePedidos.cadenas;
    conjuntoDePedidos.enteros=buffer_de_conjuntoDePedidos.enteros;
    conjuntoDePedidos.reales=buffer_de_conjuntoDePedidos.reales;
    for (int i = 0; i < 200; i++) {
        if(conjuntoDePedidos.enteros[i]){
            memoriaExactaEnterosCadenas(conjuntoDePedidos.enteros[i],
                                        conjuntoDePedidos.cadenas[i]);
        }else{
            delete conjuntoDePedidos.enteros[i];
            delete conjuntoDePedidos.cadenas[i];
        }
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

void actualizarPrecioPedido(double *&reales,int *enteros,char **cadenas,
                            const struct ConjuntoDePlatos &conjuntoDePlatos){
    reales=new double[enteros[1]+2]{};
    for (int i = 0; i < enteros[1]; i++) {
        reales[i+1]= (conjuntoDePlatos+=cadenas[i+1])*enteros[i+2];
        reales[0]+=reales[i+1];
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    struct ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos,"platos.csv");
    int numPed=0;
    while(conjuntoDePedidos.enteros[numPed])numPed++;
    conjuntoDePedidos.reales=new double*[numPed+1]{};
    for (int i = 0; i<numPed ; i++) {
        actualizarPrecioPedido(conjuntoDePedidos.reales[i],
                               conjuntoDePedidos.enteros[i],
                               conjuntoDePedidos.cadenas[i],conjuntoDePlatos);
    }
    liberar_conjunto_de_platos(conjuntoDePlatos);
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    struct ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos,"platos.csv");
    int numPed=0;
    while(conjuntoDePedidos.enteros[numPed])numPed++;
    conjuntoDePedidos.reales=new double*[numPed+1]{};
    for (int i = 0; i<numPed ; i++) {
        actualizarPrecioPedido(conjuntoDePedidos.reales[i],
                               conjuntoDePedidos.enteros[i],
                               conjuntoDePedidos.cadenas[i],conjuntoDePlatos);
    }
    liberar_conjunto_de_platos(conjuntoDePlatos);
}

void liberar_cadenas(char **cadenas){
    for (int i = 0; cadenas[i]; i++) {
        delete cadenas[i];
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {
    for (int i = 0; conjuntoDePedidos.enteros[i] ; i++) {
        liberar_cadenas(conjuntoDePedidos.cadenas[i]);
        delete conjuntoDePedidos.cadenas[i];
        delete conjuntoDePedidos.enteros[i];
        if(conjuntoDePedidos.reales!=nullptr)delete conjuntoDePedidos.reales[i];
    }
    delete conjuntoDePedidos.cadenas;
    delete conjuntoDePedidos.enteros;
    delete conjuntoDePedidos.reales;
}

void cambiarCodigoPorNombre(char **cadenas,const struct ConjuntoDePlatos &conjuntoDePlatos){
    char *nombre;
    for (int i = 1; cadenas[i] ; i++) {
        nombre= conjuntoDePlatos==cadenas[i];
        delete cadenas[i];
        cadenas[i]=nombre;
    }
}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    struct ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos,"platos.csv");
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        cambiarCodigoPorNombre(conjuntoDePedidos.cadenas[i],conjuntoDePlatos);
    }
}

void crearReporte(int *enteros,char **cadenas,double *reales){
    ofstream arch;
    char nombArch[25];
    obtener_nombre_archivo(nombArch,enteros[0]);
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    arch.precision(2);
    imprimir_linea(arch);
    arch<<fixed<<right<<setw(20)<<"D.N.I. CLIENTE:"<<left<<"  "<<setw(10)
        <<enteros[0]<<endl;
    arch<<right<<setw(20)<<"CODIGO REPARTIDOR:"<<left<<"  "<<setw(10)<<cadenas[0]
        <<endl;
    imprimir_linea(arch);
    arch<<left<<setw(5)<<"ITEM"<<setw(21)<<"PLATO"<<setw(5)<<"CANT"
        <<setw(15)<<"SUBTOTAL"<<endl;
    imprimir_linea(arch,'-');
    for (int i = 1; i < enteros[1]+1; i++) {
        arch<<"  "<<right<<setw(2)<<setfill('0')<<i<<setfill(' ')<<' '
           <<left<<setw(20)<<cadenas[i]<<right<<setw(4)<<enteros[i+1]
           <<setw(10)<<reales[i]<<endl;
    }
    imprimir_linea(arch,'-');
    arch<<right<<setw(30)<<"SUBTOTAL:"<<setw(9)<<reales[0]<<endl;
    arch<<right<<setw(30)<<"IGV:"<<setw(9)<<reales[0]*((double)18/100)<<endl;
    arch<<right<<setw(30)<<"TOTAL:"<<setw(9)<<reales[0]*((double)118/100)<<endl;
    imprimir_linea(arch);
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    for (int i = 0; conjuntoDePedidos.enteros[i] ; i++) {
        crearReporte(conjuntoDePedidos.enteros[i],conjuntoDePedidos.cadenas[i],
                     conjuntoDePedidos.reales[i]);
    }
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