/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 22 de mayo de 2024, 02:29 PM
 */

#include "Cliente.h"
#include "Pedido.h"
#include "Producto.h"
#include "ProductoEntregado.h"

void prueba_cliente(Cliente *arr,int &cant){
    ifstream arch("Clientes.csv");
    ofstream arch2("pruebaClientes.txt");
    
    
    while(arch>>arr[cant]){
        arch2<<arr[cant];
        arch2<<endl;
        cant++;
    }
}
void prueba_producto(Producto *arr,int &cant){
    ifstream arch("Productos.csv");
    ofstream arch2("pruebaProductos.txt");
    
    
    while(arch>>arr[cant]){
        arch2<<arr[cant];
        arch2<<endl;
        cant++;
    }
}
void prueba_pedido(Cliente *arrCli,int cantCli,Producto *arrProd,int cantProd){
    ifstream arch("Pedidos.csv");
    ofstream arch2("pruebaPedidos.txt");
    Pedido ped;
    
    arch>>ped;
    arrProd[3]+=ped;
    arrCli[3]+=ped;
    
    arch2<<arrCli[3];
    arch2<<endl;
    arch2<<arrProd[3];
}

int main(int argc, char** argv) {
    Cliente arrCliente[150];
    Producto arrProducto[180];
    int cantCli=0,cantProd=0;
    prueba_cliente(arrCliente,cantCli);
    prueba_producto(arrProducto,cantProd);
    prueba_pedido(arrCliente,cantCli,arrProducto,cantProd);
    
    return 0;
}

