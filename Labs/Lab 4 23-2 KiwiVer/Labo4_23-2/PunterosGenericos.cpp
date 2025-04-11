/* 
 * Archivo:   PunterosGenericos.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  26 de septiembre de 2024, 12:43
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#define NOT_FOUND -1
#define MAXLIN 100
enum PROD {COD,DESC,PRE,TIPO};
enum CLI {DNI,NOMB,PED,CRE};

//BIT-434,Campana Extractora modelo Glass,375.09,S
void cargaproductos(void *&pro){
    ifstream arch("Productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo de productos"<<endl;
        exit(1);
    }

    void *buffProds[200]{}, **productos, *registro;
    int numProd=0;
    while(true){
        registro = leeProducto(arch);
        if(arch.eof())break;
        buffProds[numProd] = registro;
        numProd++;
    }
    productos = new void*[numProd+1];
    for(int i=0;i<numProd;i++) productos[i] = buffProds[i];
    pro = productos;
    imprimeproductos(pro);
}

void *leeProducto(ifstream &arch){
    void **registro;
    char *codigo, *descripcion, *tipo;
    double *precio;
    codigo = leeCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    descripcion = leeCadenaExacta(arch,',');
    precio = new double;
    arch>>*precio;
    arch.get();
    tipo = leeCadenaExacta(arch);
    registro = new void*[4]{};
    registro[COD] = codigo;
    registro[DESC] = descripcion;
    registro[PRE] = precio;
    registro[TIPO] = tipo;
    return registro;
}

char *leeCadenaExacta(ifstream &arch,char delim){
    char buffer[60], *cadena;
    arch.getline(buffer,60,delim);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
//79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000

void cargaclientes(void *&cli){
    ifstream arch("Clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo de productos"<<endl;
        exit(1);
    }
    void *buffCli[150]{}, **clientes, *registro;
    int numCli=0;
    while(true){
        registro = leeCliente(arch);
        if(arch.eof())break;
        buffCli[numCli] = registro;
        numCli++;
    }
    clientes = new void*[numCli+1]{};
    for(int i=0;i<numCli;i++) clientes[i] = buffCli[i];
    cli = clientes;
    imprimeclientes(cli);
}

void *leeCliente(ifstream &arch){
    void **registro;
    int *dni, telefono;
    double *lineaCred;
    char *nombre,c;
    dni = new int;
    arch>>*dni;
    if(arch.eof())return nullptr;
    arch.get();
    nombre = leeCadenaExacta(arch,',');
    lineaCred = new double;
    arch>>telefono>>c>>*lineaCred;
    arch.get();
    registro = new void*[4];
    registro[DNI] = dni;
    registro[NOMB] = nombre;
    registro[PED] = nullptr;
    registro[CRE] = lineaCred;
    return registro;
}

void cargapedidos(void *prods,void *clis){
    ifstream arch("Pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo de productos"<<endl;
        exit(1);
    }
    void **productos = (void**)prods, **clientes = (void**)clis, **auxCli;
    char *codigo, c;
    int dni, cant, posCli, posProd;
    while(true){
        codigo = leeCadenaExacta(arch,',');
        if(arch.eof())break;
        arch>>dni>>c>>cant;
        arch.get();
        posCli = buscarCliente(clis,dni);
        posProd = buscarProducto(prods,codigo);
        if(posCli != NOT_FOUND and posProd != NOT_FOUND){
            agregarPedido(productos[posProd],clientes[posCli],cant);
        }
    }
    for(int i=0;clientes[i];i++){
        auxCli = (void**)clientes[i];
        ajustarListaPedidos(auxCli[PED]);
    }
    clis = clientes;
//    imprimerepfinal(clis);
}

int buscarCliente(void *clis,int dni){
    void **clientes = (void**)clis, **cliente;
    for(int i=0;clientes[i];i++){
        cliente = (void**)clientes[i];
        if(*(int*)cliente[DNI]==dni) return i;
    }
    return NOT_FOUND;
        
}
int buscarProducto(void *prods, char *codigo){
    void **productos = (void**)prods, **producto;
    for(int i=0;productos[i];i++){
        producto = (void**)productos[i];
        if(strcmp((char*)producto[COD],codigo)==0) return i;
    }
    return NOT_FOUND;
}

void agregarPedido(void *prod,void *cli,int cant){
    void **producto = (void**)prod, **cliente = (void**)cli;
    void **regPed;
    char *codigo, *consumeLinea;
    int *cantPr;
    double *precio, *totalPed, *lineaCred, monto;
    precio = (double*)producto[PRE];
    consumeLinea = (char*)producto[TIPO];
    lineaCred = (double*)cliente[CRE];
    monto = (*precio)*cant;
    if(*consumeLinea!='S' or monto < *lineaCred){
        if(*consumeLinea == 'S')
            *(double *)cliente[CRE] -= monto;
        codigo = new char[strlen((char*)producto[COD])+1];
        strcpy(codigo,(char*)producto[COD]);
        cantPr = new int;
        *cantPr = cant;
        totalPed = new double;
        *totalPed = monto;
        regPed = new void*[3]{};
        regPed[0] = codigo;
        regPed[1] = cantPr;
        regPed[2] = totalPed;
        insertarPedidoEnCliente(cliente[PED],regPed);
    }
}

void insertarPedidoEnCliente(void *&listaPed,void *regPed){
    void **pedidos = (void**)listaPed;
    int cantPed=0;
    if(pedidos==nullptr) pedidos = new void*[100]{};
    while(pedidos[cantPed]) cantPed++;
    pedidos[cantPed] = regPed;
    listaPed = pedidos;
}

void ajustarListaPedidos(void *&listaPed){
    void **pedidos = (void**)listaPed, **auxPeds;
    int cant=0;
    if(pedidos != nullptr){
        while(pedidos[cant]) cant++;
        auxPeds = new void *[cant+1];
        for (int i = 0; i < cant; i++) auxPeds[i] = pedidos[i];
    }
    listaPed = auxPeds;
}
void ordenarClientesKiwi(void *cli){
    void **clientes = (void**)cli;
    int numCli=0;
    for(numCli;clientes[numCli];numCli++);
    qSortKiwi(cli,0,numCli-1);
}

void qSortKiwi(void *cli,int izq,int der){
    void **clientes = (void**)cli;
    int limite;
    if(izq>=der)return;
    cambiarKiwi(clientes[izq],clientes[(izq+der)/2]);
    limite = izq;
    for (int i=izq+1; i<=der ;i++)
        if(estanEnDesordenKiwi(clientes[i],clientes[izq]))
            cambiarKiwi(clientes[++limite],clientes[i]);
    cambiarKiwi(clientes[izq],clientes[limite]);
    qSortKiwi(clientes,izq,limite-1);
    qSortKiwi(clientes,limite+1,der);
}

void cambiarKiwi(void *&clienteI, void *&clienteK){
    void *aux;
    aux = clienteI;
    clienteI = clienteK;
    clienteK = aux;
}

bool estanEnDesordenKiwi(void *clieI, void *clieK){
    void **clienteI = (void**)clieI, **clienteK = (void**)clieK;
    char *nombreI = (char*)clienteI[NOMB], *nombreK = (char*)clienteK[NOMB];
    return strcmp(nombreI,nombreK)<0;
}