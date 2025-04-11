/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: ISA
 * 
 * Created on 25 de abril de 2024, 09:50 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <valarray>
#include "AperturaDeArchivos.h"
#include "PunterosGenericos.h"
#define MAX 400
#define NO_ENCONTRADO -1
enum LIB{LIB_COD,LIB_TIT,LIB_AUT,LIB_STK,LIB_PRE};
enum CLI{CLI_DNI,CLI_NOM,CLI_PED,CLI_CANT,CLI_TOTAL};
enum PRO{PRO_COD,PRO_NOM,PRO_PRE};
void cargarLibros(void *&libros,const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    void *buff[MAX];
    int num = 0;
    while(true){
        buff[num] = leerLibro(arch);
        if(buff[num] == nullptr)break;
        num++;
    }
    void **a_lib = new void*[num+1];
    for(int i=0;i<=num;i++)
        a_lib[i] = buff[i];
    libros = a_lib;
}
void* leerLibro(ifstream &arch){
    char *cod,*titulo,*autor,c;
    int *stock;
    double *precio;
    cod = LeerCadenaExacta(arch,8,',');
    if(cod == nullptr)return nullptr;
    titulo = LeerCadenaExacta(arch,120,',');
    autor = LeerCadenaExacta(arch,120,',');
    stock = new int;
    precio = new double;
    arch >> *stock >> c >> *precio;
    arch.get();
    void **registro = new void*[5];
    registro[LIB_COD] = cod;
    registro[LIB_TIT] = titulo;
    registro[LIB_AUT] = autor;
    registro[LIB_STK] = stock;
    registro[LIB_PRE] = precio;
    return registro;
}
char* LeerCadenaExacta(ifstream &arch,int max,char c){
    char cadena[max],*cad;
    arch.getline(cadena,max,c);
    if(arch.eof())return nullptr;
    cad = new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}
void reporteLibros(void *libros,const char* nomArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nomArch);
    arch << setprecision(2) << fixed;
    void** leer_libros = (void**)libros;
    for(int i=0;leer_libros[i]!=nullptr;i++){
        ImprimirLibros(arch,leer_libros[i]);
    }
}
void ImprimirLibros(ofstream &arch,void *leer_libro){
    void **leer_registro = (void**)leer_libro;
    char *cod = (char*)leer_registro[LIB_COD],*titulo = (char*)leer_registro[LIB_TIT],
        *autor = (char*)leer_registro[LIB_AUT];
    int *stk = (int*)leer_registro[LIB_STK];
    double *precio = (double*)leer_registro[LIB_PRE] ;
    arch << left << setw(10) << cod << setw(80) << titulo << setw(60) << autor << endl;
    arch << right << "STOCK: "<<*stk << "  PRECIO: "<<*precio<< endl;
}
void cargarClientes(void *&clientes,const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    void *buff[MAX];
    int num = 0;
    while(true){
        buff[num] = leerCliente(arch);
        if(buff[num] == nullptr)break;
        num++;
    }
    void **a_clientes = new void*[num+1];
    for(int i=0;i<=num;i++)
        a_clientes[i] = buff[i];
    clientes = a_clientes;
}
void* leerCliente(ifstream &arch){
    char *nombre,c;
    int *ptrdni,dni;
    arch >> dni;
    if(arch.eof())return nullptr;
    arch.get();
    nombre = LeerCadenaExacta(arch,120,'\n'); //Cambiar Funcion
    ptrdni = new int{dni};
    void **registro = new void*[5];
    double *total = new double{};
    int *cant = new int{};
    registro[CLI_DNI] = ptrdni;
    registro[CLI_NOM] = nombre;
    registro[CLI_PED] = nullptr;
    registro[CLI_CANT] = cant;
    registro[CLI_TOTAL] = total;
    return registro;
}
void reporteClientes(void *clientes,const char* nomArch ){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nomArch);
    void** leer_clientes = (void**)clientes;
    for(int i=0;leer_clientes[i]!=nullptr;i++)
        ImprimirIDClientes(arch,leer_clientes[i]);
}
void ImprimirIDClientes(ofstream &arch,void *cliente){
    void **registro = (void**)cliente;
    char *nom = (char*)registro[CLI_NOM];
    int *dni = (int*)registro[CLI_DNI];
    arch << *dni << setw(60) <<nom << endl;
}
//Metodo 1
void cargarPedidos(void *clientes, void *libros,const char* nomArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nomArch);
    int codped,dni,posCli,posLib;
    char c,*cod;
    void **acceso_cli;
    while(true){
        arch >> codped;
        if(arch.eof())break;
        arch >> c >> dni;
        arch.get();
        posCli = BuscarCliente(dni,clientes);
        if(posCli != NO_ENCONTRADO){
            cod = new char[8];
            arch >> cod;
            posLib = BuscarLibro(cod,libros); //VerificarExistencia
            if(posLib != NO_ENCONTRADO){
                acceso_cli = (void**)clientes;
//                cout << codped << " - " << dni << " - "<<cod <<endl;
                ActualizarInformacion(acceso_cli[posCli],cod);
            }else delete cod;
        }else while(arch.get()!='\n');
    }
}
int BuscarCliente(int dni,void *clientes){
    void **leer_clientes = (void**)clientes;
    void **registro;
    int *ptrdni;
    for(int i=0;leer_clientes[i]!=nullptr;i++){
        registro = (void**)leer_clientes[i];
        ptrdni = (int*)registro[CLI_DNI];
        if(*ptrdni == dni)return i;
    }
    return NO_ENCONTRADO;
}
int BuscarLibro(char *cod,void *libros){
    void **leer_libros = (void**)libros;
    void **registro;
    char *codigo;
    for (int i = 0; leer_libros[i] != nullptr; i++) {
        registro = (void**)leer_libros[i];
        codigo = (char*) registro[LIB_COD];
        if (strncmp(codigo,cod,8)==0)return i;
    }
    return NO_ENCONTRADO;
}
void ActualizarInformacion(void *cliente,char *cod){
    void **registro = (void**)cliente;
    void **listado_productos = (void**)registro[CLI_PED];
    int *num_productos = (int*)registro[CLI_CANT];
    cout << *num_productos << endl;
    if(*num_productos < 20){
       if (listado_productos == nullptr){
           listado_productos = new void*[20]{}; //Fijo
           registro[CLI_PED] = listado_productos;
       }
       listado_productos[*num_productos] = AsignarEspacioProducto(cod);
       (*num_productos)++; 
    }//else delete cod;
    void **tripleta;
    char *codigo,*nom;
    double *pre;
    for(int i=0;i<*num_productos;i++){
        tripleta = (void**)listado_productos[i];
        codigo = (char*)tripleta[PRO_COD];
        nom = (char*)tripleta[PRO_NOM];
        pre = (double*)tripleta[PRO_PRE];
        cout << codigo << endl;
    }
}
void* AsignarEspacioProducto(char *cod){
    void** registro_producto = new void*[3];
    registro_producto[PRO_COD] = cod;
    registro_producto[PRO_NOM] = nullptr;
    registro_producto[PRO_PRE] = nullptr;
    return registro_producto;
}
void actualizarPedidos(void *libros, void *clientes){
    void** ver_clientes = (void**)clientes;
    void** registro_cli;
    for(int i=0;ver_clientes[i]!=nullptr;i++){
        registro_cli = (void**)ver_clientes[i];
        cout << *((int*)registro_cli[CLI_DNI]) << " - " 
                << ((char*)registro_cli[CLI_NOM]) << endl;;
        RecorrerPedidos(registro_cli[CLI_PED],registro_cli[CLI_CANT],
                registro_cli[CLI_TOTAL],libros);
    }
}
void RecorrerPedidos(void *arr_productos,void *cantidad_productos,
                void *total_gastos,void *libros){
    int *cantidad = (int*)cantidad_productos,pos;
    double *total = (double*)total_gastos;
    void **leer_productos = (void**)arr_productos;
    void **reg_producto;
    char *cod;
    void **acceso_libro = (void**)libros;
    if(*cantidad > 0){
        for (int i = 0; i<*cantidad; i++) {
            reg_producto = (void**) leer_productos[i];
            cod = (char*) reg_producto[PRO_COD];
            pos = BuscarLibro(cod, libros);
            if (pos != NO_ENCONTRADO) {
                acceso_libro = (void**) libros;
                *total += CompletarInformacionProducto(reg_producto[PRO_NOM],
                        reg_producto[PRO_PRE], acceso_libro[pos]);
            }
        }
    }
    
}
double CompletarInformacionProducto(void *&reg_nombre,void *&reg_precio,
        void *libro){
    void **registro_libro = (void**)libro;
    char *titulo = (char*)registro_libro[LIB_TIT];
    double *precio = (double*)registro_libro[LIB_PRE];
    char *pro_nom = new char[strlen(titulo)+1];
    strcpy(pro_nom,titulo);
    double *pro_precio = new double{*precio};
    reg_nombre = pro_nom;
    reg_precio = pro_precio;
    return *pro_precio;
}

void reporteFinal(void *clientes,const char* nomArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nomArch);
    arch << setprecision(2) << fixed;
    void** leer_clientes = (void**) clientes;
    for (int i = 0; leer_clientes[i] != nullptr; i++)
        ImprimirClientes(arch, leer_clientes[i]);
}
void ImprimirClientes(ofstream &arch,void *cliente){
    void **registro = (void**)cliente;
    char *nom = (char*)registro[CLI_NOM];
    int *dni = (int*)registro[CLI_DNI];
    int *cantidad = (int*)registro[CLI_CANT];
    double *total = (double*)registro[CLI_TOTAL];
    void **pedidos = (void**)registro[CLI_PED];
    arch << left <<"DNI: "<< setw(14) <<*dni << "NOMBRE: "<<setw(60) << nom << endl;
    arch << left << setw(10)<<"CANTIDAD:" << right <<setw(10) << *cantidad
            << left <<setw(4)<<' '<<setw(10) << "TOTAL:" << right << setw(10) << *total << endl;
    ImprimirLinea(arch,130,'=');
    if(*cantidad > 0){
       for (int i = 0; i<*cantidad; i++) {
            ImprimirProducto(arch, pedidos[i]);
       } 
    }else arch << "No hay pedidos" << endl;
    
    ImprimirLinea(arch,130,'=');
}
void ImprimirProducto(ofstream &arch,void* pedido){
    void **reg_producto = (void**)pedido;
    char* cod = (char*)reg_producto[PRO_COD],*nom = (char*)reg_producto[PRO_NOM];
    double* precio = (double*)reg_producto[PRO_PRE];
    arch << left << setw(10) << cod << setw(60) << nom << right << setw(10) << *precio << endl;
}
void ImprimirLinea(ofstream &arch,int n,char c){
    arch << setfill(c) << setw(n)<< c <<setfill(' ') <<endl;
}
