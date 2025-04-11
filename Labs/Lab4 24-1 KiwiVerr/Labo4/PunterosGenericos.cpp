/* 
 * Archivo:   PunterosGenericos.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  23 de septiembre de 2024, 23:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#include "PunterosGenericos.h"
enum LIB {COD,NOMB,AUT,PED,STK};
#define NO_ENCONTRADO -1

void cargaclientes(void *&cli){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Clientes.csv");
    void *buffCli[100], **clientes, *reg;
    int numCli=0;
    while(true){
        reg = leerRegistro(arch);
        if(arch.eof())break;
        buffCli[numCli] = reg;
        numCli++;
    }
    clientes = new void*[numCli+1]{};
    for(int i=0;i<numCli;i++) clientes[i] = buffCli[i];
    cli = clientes;
    muestraclientes(cli);
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *ptrdni, dni;
    char *nombre;
    ptrdni = new int;
    arch>>dni;
    if(arch.eof())return nullptr;
    arch.get();
    *ptrdni = dni;
    nombre = leeCadenaExacta(arch);
    registro = new void*[2]{};
    registro[0] = ptrdni;
    registro[1] = nombre;
    return registro;
}

char *leeCadenaExacta(ifstream &arch, char delim){
    char buffer[60], *cadena;
    arch.getline(buffer,60,delim);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void creareserva(void *&res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    void *buffReserva[300]{}, **reserva;
    int numRes=0;
    while(true){
        buffReserva[numRes] = leeReserva(arch);
        if(arch.eof())break;
        numRes++;
    }
    reserva = new void*[numRes+1]{};
    for (int i = 0; i < numRes; i++) {
        reserva[i] = buffReserva[i];
    }
    res = reserva;
    muestrareservas(res);
}

void* leeReserva(ifstream &arch){
    void **registro;
    int stock, *ptrStock;
    double precio;
    char *codigo, *nombre, *autor, c;
    codigo = leeCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    nombre = leeCadenaExacta(arch,',');
    autor = leeCadenaExacta(arch,',');
    arch>>stock>>c>>precio;
    arch.get();
    ptrStock = new int;
    *ptrStock = stock;
    registro = new void*[5]{};
    registro[COD] = codigo;
    registro[NOMB] = nombre;
    registro[AUT] = autor;
    registro[PED] = crearEspaciosExactos(stock);
    registro[STK] = ptrStock;
    return registro;
}

void* crearEspaciosExactos(int stock){
    void**registro = new void *[stock]{};
    return registro;
}

void cargareservar(void *cli,void *res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos2.csv");
    void **clientes = (void**)cli, **reserva = (void**)res;
    int dni, posCli, posLib, *stockActual;
    char *codLib;
    stockParaManejarlo(res,stockActual);
    while(true){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        codLib = leeCadenaExacta(arch);
        posCli = buscaCliente(cli,dni);
        posLib = buscaLibro(res,codLib);
        if(posLib != NO_ENCONTRADO and posCli != NO_ENCONTRADO){
            agregarPedido(clientes[posCli],reserva[posLib],stockActual[posLib]);
        }
    }
    
}
void stockParaManejarlo(void *res, int *&stockActual){
    void **reserva = (void**)res, **registro;
    int numDat = 0;
    for(int i=0;reserva[i];i++) numDat++;
    stockActual = new int[numDat];
    for(int i=0;reserva[i];i++){
        registro = (void**)reserva[i];
        stockActual[i] = *(int*)registro[STK];
    }
}

int buscaCliente(void *cli,int dni){
    void **clientes = (void**)cli, **registro;
    int *dniBuscado;
    for(int i=0;clientes[i];i++){
        registro = (void**)clientes[i];
        dniBuscado = (int*)registro[0];
        if(*dniBuscado==dni) return i;
    }
    return NO_ENCONTRADO;
}

int buscaLibro(void *res,char *codLib){
    void **reserva = (void**)res, **registro;
    char *codBuscado;
    for(int i=0;reserva[i];i++){
        registro = (void**)reserva[i];
        codBuscado = (char*)registro[COD];
        if(strcmp(codLib,codBuscado)==0)return i;
    }
    return NO_ENCONTRADO;
}

void agregarPedido(void *cliente,void *reserva,int &stockActual){
    void **regCli = (void**)cliente, **regRes = (void**)reserva;
    void **regPed = (void**)regRes[PED], **registro;
    
    int numPed=0;
    
    int *dni = (int*)regCli[0];
    char *nombre = (char*)regCli[1];
    
    if(stockActual>0){
        while(regPed[numPed]) numPed++;
        registro = new void*[2];
        registro[0] = dni;
        registro[1] = nombre;
        regPed[numPed] = registro;
        stockActual--;
    }
}