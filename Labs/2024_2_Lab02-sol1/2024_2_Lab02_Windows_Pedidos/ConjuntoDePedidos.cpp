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
    ConjuntoDePedidos bufferConjuntoPedidos;
    inicializar_buffer_de_conjunto_de_pedidos(bufferConjuntoPedidos,200);
    while(true){
        struct Pedido datoPedido;
        if(!(archivo_de_pedidos>>datoPedido))break;
        bufferConjuntoPedidos<<datoPedido;
    }
    bufferConjuntoPedidos>>conjuntoDePedidos;
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

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    //buscamos cliente
    int idCliente;
    idCliente=buscar_cliente(buffer_de_conjuntoDePedidos,pedido.dni_cliente);
    if(idCliente==CLIENTE_NO_ENCONTRADO){
        //Cliente nuevo
        //un plato nuevo
        idCliente=obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
        int *datosClientes = new int [3]{};
        datosClientes[0]=pedido.dni_cliente;        //dni cliente
        datosClientes[1]=1;                         //Cantidad tipo de platos
        datosClientes[2]=pedido.cantidad_platos;    //cantidad tipo plato 1
        
        //guardamos datos del cliente
        buffer_de_conjuntoDePedidos.enteros[idCliente]=datosClientes;
        
        //AGREGAMOS REPARTIDOR ENCARGADO Y PRIMER PLATO
        char **datosPlatos = new char *[2]{};
        datosPlatos[0]=mi_strdup(pedido.codigo_repartidor);
        datosPlatos[1]=mi_strdup(pedido.codigo_plato);
        buffer_de_conjuntoDePedidos.cadenas[idCliente]=datosPlatos;
        
    }
    else{
        //Cliente antiguo
        //se agrega un plato nuevo
        int *datosCliente = buffer_de_conjuntoDePedidos.enteros[idCliente];
        int cant_datos_nuevo=2+datosCliente[1];
        // el valor 2 es porque DNI y Cantidad de tipo de platos son variables fijas. A ello le sumamos datosCliente[1] que es donde se guarda el valor de cantidad
        int *datosNuevoCliente = new int [cant_datos_nuevo+1];
        for(int i=0;i<cant_datos_nuevo;i++){
            datosNuevoCliente[i]=datosCliente[i];
        }
        datosNuevoCliente[1]=datosNuevoCliente[1]+1;
        datosNuevoCliente[cant_datos_nuevo]=pedido.cantidad_platos;
        buffer_de_conjuntoDePedidos.enteros[idCliente]=datosNuevoCliente;
        
        //AGREGAR PLATO NUEVO
        char **datosPlatos= buffer_de_conjuntoDePedidos.cadenas[idCliente];
        int cant_datos_plato_nuevo = datosNuevoCliente[1];
        char **datosNuevoPlatos= new char*[cant_datos_plato_nuevo +1]{};
        
        for(int i=0;i<cant_datos_plato_nuevo;i++){
            datosNuevoPlatos[i]=datosPlatos[i];
        }
        datosNuevoPlatos[cant_datos_plato_nuevo]=mi_strdup(pedido.codigo_plato);
        buffer_de_conjuntoDePedidos.cadenas[idCliente]=datosNuevoPlatos;
    }
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
        //cargar datos del plato
    ConjuntoDePlatos conjuntoDatosPlatos;
    cargar_conjunto_de_platos(conjuntoDatosPlatos,"platos.csv");
    
    int cantidadPedidos = obtener_cantidad_cliente(conjuntoDePedidos);
    conjuntoDePedidos.reales=new double *[cantidadPedidos]{};
    for(int i=0;i<cantidadPedidos;i++){
        //Obtener Datos del Cliente
        int *datosClientes = conjuntoDePedidos.enteros[i];
        //obtener Datos de los platos
        char **datosPlatos = conjuntoDePedidos.cadenas[i];
        //Separar espacio para el precio por plato y subtotal;
        double *datosPrecios = new double [datosClientes[1]+1]{};
        //Calculamos precio por plato y subtotal
        datosPrecios[0]=0; //subtotal en 0;
        for(int j=2;j<datosClientes[1]+2;j++){
            double precio = conjuntoDatosPlatos+=datosPlatos[j-1];
            double totalPorPlato = precio * datosClientes[j];
            datosPrecios[0]+=totalPorPlato;
            datosPrecios[j-1]=totalPorPlato;
        }
        conjuntoDePedidos.reales[i]=datosPrecios;
    }
  
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
        //cargar datos del plato
    ConjuntoDePlatos conjuntoDatosPlatos;
    cargar_conjunto_de_platos(conjuntoDatosPlatos,"platos.csv");
    
    int cantidadPedidos = obtener_cantidad_cliente(conjuntoDePedidos);
    conjuntoDePedidos.reales=new double *[cantidadPedidos]{};
    for(int i=0;i<cantidadPedidos;i++){
        //Obtener Datos del Cliente
        int *datosClientes = conjuntoDePedidos.enteros[i];
        //obtener Datos de los platos
        char **datosPlatos = conjuntoDePedidos.cadenas[i];
        //Separar espacio para el precio por plato y subtotal;
        double *datosPrecios = new double [datosClientes[1]+1]{};
        //Calculamos precio por plato y subtotal
        datosPrecios[0]=0; //subtotal en 0;
        for(int j=2;j<datosClientes[1]+2;j++){
            //extraemos el precio
            double precio = conjuntoDatosPlatos+=datosPlatos[j-1];
            //obtenemos precio por plato
            double totalPorPlato = precio * datosClientes[j];
            //actualizamos el subtotal
            datosPrecios[0]+=totalPorPlato;
            //guardamos precio
            datosPrecios[j-1]=totalPorPlato;
        }
        conjuntoDePedidos.reales[i]=datosPrecios;
    }
    
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {
    int cantidad = obtener_cantidad_cliente(conjuntoDePedidos);
    for(int i=0;i<cantidad;i++){
        if(conjuntoDePedidos.enteros[i]!=nullptr)
            delete conjuntoDePedidos.enteros[i];
        if(conjuntoDePedidos.cadenas[i]!=nullptr)
        delete conjuntoDePedidos.cadenas[i];
    }
    
    //delete para double cuando ya este lleno
    if(conjuntoDePedidos.reales!=nullptr){
        for(int i=0;i<cantidad;i++){
            delete conjuntoDePedidos.reales[i];
        }
    }
}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDatosPlatos;
    cargar_conjunto_de_platos(conjuntoDatosPlatos,"platos.csv");
    
    int cantidadPedidos=obtener_cantidad_cliente(conjuntoDePedidos);
    //leemos cada cliente
    for(int i=0;i<cantidadPedidos;i++){
        int *datosCliente  = conjuntoDePedidos.enteros[i];
        char **datosPlatos = conjuntoDePedidos.cadenas[i];
        int cantidadPlatos=datosCliente[1]+1;
        char **datosNombresPlato = new char*[cantidadPlatos]{};
        
        //copiamos el nombre del repartidor
        char *nombreRepartidor = mi_strdup(datosPlatos[0]);
        datosNombresPlato[0]=nombreRepartidor;
        for(int j=1;j<cantidadPlatos;j++){
            //Extraemos el nombre de los platos y lo guardamos en un char** nuevo
            char *nombrePlato = conjuntoDatosPlatos==datosPlatos[j];
            datosNombresPlato[j]= mi_strdup(nombrePlato);
        }
        conjuntoDePedidos.cadenas[i]=datosNombresPlato;
    }
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    int cantidad=obtener_cantidad_cliente(conjuntoDePedidos);
    for(int i=0;i<cantidad;i++){
        //extraemos los datos del cliente con sus platos y precios
        char nombre_archivo[100];
        int *datosCliente=conjuntoDePedidos.enteros[i];
        char **datosPlatos=conjuntoDePedidos.cadenas[i];
        double *datosPrecios=conjuntoDePedidos.reales[i];
        obtener_nombre_archivo(nombre_archivo,datosCliente[0]);
        ofstream arch;
        AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre_archivo);
        arch<<setprecision(2)<<fixed;
        imprimir_linea(arch,'=');
        arch<<setw(20)<<"D.N.I. CLIENTE: "<<datosCliente[0]<<endl;
        arch<<setw(20)<<"CODIGO REPARTIDOR: "<<datosPlatos[0]<<endl;
        imprimir_linea(arch,'=');
        arch<<"ITEM PLATO"<<setw(20)<<"CANT"<<setw(10)<<"SUBTOTAL"<<endl;
        imprimir_linea(arch,'-');
        for(int j=1;j<datosCliente[1]+1;j++){
            arch<<" "<<setw(2)<<setfill('0')<<j<<setfill('.')<<" "<<left<<setw(25)<<datosPlatos[j]<<setfill(' ')<<setw(3)<<datosCliente[j+1]<<right<<setw(5)<<datosPrecios[j]<<endl;
        }
        imprimir_linea(arch,'-');
        arch<<setw(30)<<"SUBTOTAL: "<<setw(7)<<datosPrecios[0]<<endl;
        arch<<setw(30)<<"I.G.V.: "<<setw(7)<<datosPrecios[0]*0.18<<endl;
        arch<<setw(30)<<"TOTAL: "<<setw(7)<<datosPrecios[0]*1.18<<endl;
        imprimir_linea(arch,'=');
        arch.close();
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
    while (conjuntoDePedidos.enteros[i] != nullptr){
        i++;
    }
        
    return i;
}