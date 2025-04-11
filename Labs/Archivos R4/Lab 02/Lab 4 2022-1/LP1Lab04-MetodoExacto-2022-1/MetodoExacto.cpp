/* 
 * File:   MetodoExacto.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 11 de abril de 2024, 11:04
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoExacto.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 140
//Carga de Clientes
/*
71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B,935441620
29847168,ALDAVE ZEVALLOS ROSARIO A,6261108
91897732,GAMARRA ALCOCER VIRGINIA,954025615
*/
void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    int buffDni[20],dni,telefono;
    char *buffNomb[20],buffCat[20],nombre[60],categoria;
    
    ifstream archCli("Clientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        archCli>>dni;
        if(archCli.eof()) break;
        archCli.get();
        archCli.getline(nombre,60,',');
        arreglarNombre(nombre,categoria);
        archCli>>telefono;
        buffDni[i] = dni;
        buffNomb[i] = new char[strlen(nombre)+1];
        strcpy(buffNomb[i],nombre);
        buffCat[i] = categoria;
        i++;
    }
    cargaArrClientes(cli_DNI,cli_Nombre,cli_Categoria,
                     buffDni,buffNomb,  buffCat,      i);
}

void arreglarNombre(char *nombre,char &categoria){
    int longCC = strlen(nombre);
    if(nombre[longCC-2]==' '){
        categoria = nombre[longCC-1];
        nombre[longCC-2] = '\0';
    }else categoria = '-';
}

void cargaArrClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria,
                      int *buffDni,char **buffNomb,char *buffCat,int n){
    cli_DNI = new int[n+1];
    cli_Nombre = new char*[n];
    cli_Categoria = new char[n];
    
    for(int i=0;i<n;i++){
        cli_DNI[i] = buffDni[i];
        cli_Nombre[i] = buffNomb[i];
        cli_Categoria[i] = buffCat[i];
    }
    
    cli_DNI[n] = 0;
}
//Reporte de Clientes
void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria){
    ofstream archRep("ReporteClientes.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteClientes.txt"<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;cli_DNI[i]!=0;i++){
        archRep<<left<<setw(10)<<cli_DNI[i]<<setw(50)<<cli_Nombre[i]
               <<cli_Categoria[i]<<endl;
    }
}
//Carga de Pedidos y Productos
/*
397718,LECHE LALA SEMI DESLACTOSADA 1LT,1.78,16.98,71378466,26/10/2020
793026,YOGHURT NATURAL LIGHT LALA 1KG,%4.7,5.54,25.86,32821689,19/04/2020
397718,LECHE LALA SEMI DESLACTOSADA 1LT,0.31,16.98,17913944,4/07/2021
*/
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
            char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
            int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido){
    int buffCod[150],*buffCodProdFecPed[150],codProd,dni,fecha,posCli,posProd;
    char *buffDesc[150],*descrip;
    double buffDsct[150],buffPrec[150],*buffCantPed[150],cant,prec,dsct;
    ifstream arch("Pedidos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.csv"<<endl;
        exit(1);
    }
    int i=0,numPed[150]={};
    while(1){   //Desde aqui se cuentan las lineas
        arch>>codProd;
        if(arch.eof()) break;
        leePedidos(arch,descrip,dsct,cant,prec,dni,fecha);
        posCli = buscarPosicionDni(cli_DNI,dni);
        if(numPed[posCli]==0){
            buffCodProdFecPed[posCli] = new int[100];
            buffCantPed[posCli] = new double[50];
        }
        completarCliente(buffCodProdFecPed[posCli],buffCantPed[posCli],
                         codProd,fecha,cant,numPed[posCli]);
        posProd = buscarPosicionProd(buffCod,codProd,i);
        if(posProd==NO_ENCONTRADO)
            agregarProducto(buffCod[i],buffDesc[i],buffDsct[i],buffPrec[i],
                            codProd,   descrip,    dsct,       prec,       i);
    }
    cargaArrProductos(pro_Codigo,pro_Descripcion,pro_Descuento,pro_Precio,
                      buffCod,   buffDesc,       buffDsct,     buffPrec,  i);
    segundaCargaClientes(cli_DNI,cli_CodigoProFechaPedido,cli_CantidadPedido,
                         buffCodProdFecPed,buffCantPed,numPed);
}

void leePedidos(ifstream &arch,char *&descrip,double &dsct,double &cant,
                double &prec,int &dni,int &fecha){
    int dd,mm,aa;
    char c;
    dsct = 0;
    arch.get();
    descrip = leeCadenaExacta(arch,60,',');
    arch>>cant; //1.78 o %4.7
    if(arch.fail()){
        arch.clear();
        arch.get();
        arch>>dsct>>c>>cant;
    }
    arch>>c>>prec>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    fecha = juntarFecha(dd,mm,aa);
}
//Lectura de cadena al primer nivel del puntero
char *leeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

int juntarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

int buscarPosicionDni(int *cli_DNI,int dni){
    for(int i=0;cli_DNI[i]!=0;i++)
        if(cli_DNI[i]==dni) return i;
    return NO_ENCONTRADO;
}

void completarCliente(int *&arrCodProFecPed,double *&arrCantPed,
                      int codProd,int fecha,double cantidad,int &cantPed){
    arrCodProFecPed[cantPed*2] = codProd;
    arrCodProFecPed[cantPed*2+1] = fecha;
    arrCantPed[cantPed] = cantidad;
    cantPed++;
}

int buscarPosicionProd(int *buffProd,int codProd,int cant){
    for(int i=0;i<cant;i++)
        if(buffProd[i]==codProd) return i;
    return NO_ENCONTRADO;
}

void agregarProducto(int &buffcodprod,char *&buffdescrip,double &buffdsct,
                     double &buffprec,int codProd,char *descrip,double dsct,
                     double prec,int &i){
    buffcodprod = codProd;
    buffdescrip = descrip;
    buffdsct = dsct;
    buffprec = prec;
    i++;
}

void cargaArrProductos(int *&pro_Codigo,char **&pro_Descripcion,
                       double *&pro_Descuento,double *&pro_Precio,int *buffCod,
                       char **buffDesc,double *buffDsct,double *buffPrec,int n){
    pro_Codigo = new int[n+1];
    pro_Descripcion = new char*[n];
    pro_Descuento = new double[n];
    pro_Precio = new double[n];
    for(int i=0;i<n;i++){
        pro_Codigo[i] = buffCod[i];
        pro_Descripcion[i] = buffDesc[i];
        pro_Descuento[i] = buffDsct[i];
        pro_Precio[i] = buffPrec[i];
    }
    pro_Codigo[n] = 0;
}

void segundaCargaClientes(int *cli_DNI,int **&cli_CodigoProFechaPedido,
                          double **&cli_CantidadPedido,int **buffCodProdFecPed,
                          double **buffCantPed,int *numPed){
    int n;
    for(n=0;cli_DNI[n]!=0;n++);
    cli_CodigoProFechaPedido = new int*[n];
    cli_CantidadPedido = new double*[n];
    
    for(int i=0;i<n;i++){
        cli_CodigoProFechaPedido[i] = new int[numPed[i]*2+1];
        cli_CantidadPedido[i] = new double[numPed[i]];
        cargaNivelInterno(cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],
                          buffCodProdFecPed[i],       buffCantPed[i],numPed[i]);
    }
}

void cargaNivelInterno(int *&cliCodProFechaPed,double *&cliCantPed,
                       int *buffCodProFechaPed,double *buffCantPed,int cantPed){
    for(int i=0;i<cantPed;i++){
        cliCodProFechaPed[i*2] = buffCodProFechaPed[i*2];
        cliCodProFechaPed[i*2+1] = buffCodProFechaPed[i*2+1];
        cliCantPed[i] = buffCantPed[i];
    }
    cliCodProFechaPed[cantPed*2] = 0;
}
//Reporte de Pedidos y Productos
void ReporteDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
                char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
                int **cli_CodigoProFechaPedido,double **cli_CantidadPedido){
    ofstream archRep("ReportePedidosYProductos.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReportePedidosYProductos.txt"
                <<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;pro_Codigo[i]!=0;i++){
        archRep<<left<<setw(10)<<pro_Codigo[i]<<setw(50)<<pro_Descripcion[i]
               <<right<<setw(8)<<pro_Descuento[i]<<setw(8)<<pro_Precio[i]<<endl;
    }
    for(int i=0;cli_DNI[i]!=0;i++){
        archRep<<left<<setw(10)<<cli_DNI[i]<<endl;
        imprimePedidos(archRep,cli_CodigoProFechaPedido[i],cli_CantidadPedido[i]);
    }
}
//A partir de aqui me dio sueño, puro Ctrl+C y Ctrl+V
void imprimePedidos(ofstream &archRep,int *codFecha,double *cant){
    for(int i=0;codFecha[2*i];i++){
        archRep<<setw(10)<<left<<codFecha[2*i]<<setw(10)<<left<<codFecha[2*i+1]
                <<setw(10)<<right<<setprecision(2)<<fixed<<cant[i]<<endl;
    }
}
//Reporte de Relacion de Pedidos
void ReporteRlacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,
                    int **cli_CodigoProFechaPedido,double **cli_CantidadPedido,
                    int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,
                    double *pro_Precio){
    ofstream archRep("PedidosPorCliente.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo PedidosPorCliente.txt"<<endl;
        exit(1);
    }
    imprimeCabecera(archRep);
    for(int i=0;cli_DNI[i];i++){
        imprimeCabeceraCliente(archRep,cli_DNI[i],cli_Nombre[i],cli_Categoria[i]);
        if(cli_CodigoProFechaPedido[i]){
            imprimirProductosCliente(cli_CodigoProFechaPedido[i],
                    cli_CantidadPedido[i],archRep,pro_Codigo,pro_Descripcion,
                    pro_Precio,pro_Descuento);
        }
    }
}

void hallarDescripPrecio(int *codProd,char **arrDescrip,double *arrPrecio,
                         double *arrDesc,char *&descripcion,double &precio,
                         double &descuento,int codigo){
    for(int i=0;codProd[i];i++){
        if(codProd[i]==codigo){
            descripcion=arrDescrip[i];
            precio=arrPrecio[i];
            descuento=arrDesc[i];
            return;
        }
    }
    cout<<"ERROR uwu no se encontro el codigo "<<codigo;
    exit(1);
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}
void imprimirProductosCliente(int *arrCodFecha,
                    double *arrCant,ofstream &archRep,int *codProd,
        char **arrDescrip,double *arrPrecio,double *arrDesc){
    char *descripcion;
    double precio,cantidad,descuento,tot;
    for(int i=0;arrCodFecha[i*2];i++){
        archRep<<setw(2)<<right<<i+1<<setw(10)<<right<<arrCodFecha[i*2];
        hallarDescripPrecio(codProd,arrDescrip,arrPrecio,arrDesc,
                descripcion,precio,descuento,arrCodFecha[i*2]);
        tot=arrCant[i]*precio;
        archRep<<"   "<<setw(40)<<left<<descripcion<<setw(12)<<right
                <<setprecision(2)<<fixed<<precio<<setw(10)<<right
                <<setprecision(2)<<fixed<<arrCant[i]<<setw(15)<<right
                <<setprecision(2)<<fixed<<tot;
        if(descuento>0){
            archRep<<setw(10)<<right<<setprecision(1)<<fixed<<descuento;
        }else{
            archRep<<setw(10)<<right<<"-.--";
        }
        archRep<<setw(8)<<right<<setprecision(1)<<fixed<<tot*(100-descuento)/100<<
                setw(8)<<right<<setprecision(1)<<fixed<<tot*descuento/100<<"       ";
        imprimeFecha(arrCodFecha[(i*2)+1],archRep);
        archRep<<endl;
    }
}

void imprimeCabecera(ofstream &archRep){
    archRep<<setw(92)<<right<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimeLinea(archRep,MAX_LINEA,'=');
    archRep<<left<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeCabeceraCliente(ofstream &arch,int dni,char *nombre,char cat){
    imprimeLinea(arch,MAX_LINEA,'=');
    arch<<setw(20)<<left<<"DNI"<<setw(60)<<left<<"Nombre"<<setw(20)<<left
            <<"Categoria"<<endl;
    arch<<setw(20)<<left<<dni<<setw(64)<<left<<nombre<<setw(20)<<left
            <<cat<<endl;
    imprimeLinea(arch,MAX_LINEA,'-');
    arch<<"PRODUCTOS ADQUIRIDOS"<<endl;
    imprimeLinea(arch,MAX_LINEA,'-');
    arch<<setw(12)<<right<<"Codigo"<<setw(12)<<right<<"  Descripcion"<<setw(38)
            <<right<<"P.U."<<setw(10)<<right<<"Cantidad"<<setw(10)<<right<<
            "Total"<<setw(14)<<right<<"Descuento %"<<
            "     A pagar    Descuento     Fecha"<<endl;
    imprimeLinea(arch,MAX_LINEA,'-');
}