
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 25 de abril de 2024, 09:48 PM
 */

#include "PunterosGenericos.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *clientes,*libros;
    cargarLibros(libros,"Libros.csv");
    reporteLibros(libros,"reporteLibros.txt");
    cargarClientes(clientes,"Cientes.csv");
    reporteClientes(clientes,"reporteClientes.txt");
    
    //Metodo 1
    cargarPedidos(clientes,libros,"Pedidos.txt");
    actualizarPedidos(libros,clientes);
    
    reporteFinal(clientes,"reporteFinal.txt");
    return 0;
}

