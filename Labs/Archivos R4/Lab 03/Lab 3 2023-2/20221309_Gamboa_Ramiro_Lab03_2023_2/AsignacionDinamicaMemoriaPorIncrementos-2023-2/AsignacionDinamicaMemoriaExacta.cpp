/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 8 de abril de 2024, 15:29
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define MAX_LINEA 140
//Lectura de Productos
/*
BIT-434,Campana Extractora modelo Glass,375.09,10
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23
*/
void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios){
    int capacidad = 0,numDatos = 0,cant;
    char **registro,c;
    double precio;
    ifstream archProd(nombArch,ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    productos = nullptr;
    while(1){
        registro = leeRegistro(archProd);
        if(archProd.eof()) break;
        archProd>>precio>>c>>cant;
        archProd.get(); //Coma
        if(capacidad==numDatos)
            aumentarCapacidad(productos,stock,precios,numDatos,capacidad);
        agregarProductos(productos,stock,precios,registro,cant,precio,numDatos);
    }
}
//Lectura de registro al segundo nivel del puntero
char **leeRegistro(ifstream &archProd){
    char **registro,*codigo;
    codigo = leeCadenaExacta(archProd,8,',');
    if(archProd.eof()) return nullptr;
    registro = new char*[2];
    registro[0] = codigo;
    registro[1] = leeCadenaExacta(archProd,60,',');
    return registro;
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

void aumentarCapacidad(char ***&productos,int *&stock,double *&precios,
                       int &numDatos,int &capacidad){
    int *auxstock;
    char ***auxprod;
    double *auxprecios;
    capacidad += INCREMENTO;
    if(productos==nullptr){
        productos = new char**[capacidad];
        stock = new int[capacidad];
        precios = new double[capacidad];
        productos[0] = nullptr;
        stock[0] = -1;
        precios[0] = 0.0;
        numDatos++;
    }else{
        auxprod = new char**[capacidad];
        auxstock = new int[capacidad];
        auxprecios = new double[capacidad];
        for(int i=0;i<numDatos;i++){
            auxprod[i] = productos[i];
            auxstock[i] = stock[i];
            auxprecios[i] = precios[i];
        }
        delete productos;
        delete stock;
        delete precios;
        productos = auxprod;
        stock = auxstock;
        precios = auxprecios;
    }
}

void agregarProductos(char ***&productos,int *&stock,double *&precios,
                      char **registro,int cant,double precio,int &numDatos){
    productos[numDatos-1] = registro;
    productos[numDatos] = nullptr;
    stock[numDatos-1] = cant;
    stock[numDatos] = -1;
    precios[numDatos-1] = precio;
    precios[numDatos] = 0.0;
    numDatos++;
}
//Prueba de Lectura de Productos
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios){
    char **auxProd;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;productos[i]!=nullptr;i++){
        auxProd = productos[i];
        archRep<<left<<setw(10)<<auxProd[0]<<setw(60)<<auxProd[1]<<right
               <<setw(5)<<stock[i]<<setw(10)<<precios[i]<<endl;
    }
}
//Lectura de Pedidos
/*
JXD-139,50375303,6,24/08/2023
CRU-009,50375303,5,3/09/2023
*/
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos){
    int capacidad = 0,numDatos = 0,fecha,dd,mm,aa,indice,*numPed,*capPed;
    int *dniCant;
    char *codigo,c;
    ifstream archPed(nombArch,ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    fechaPedidos = nullptr;
    while(1){
        codigo = leeCadenaExacta(archPed,8,',');
        if(archPed.eof()) break;
        dniCant = leeDniYCant(archPed);
        archPed>>dd>>c>>mm>>c>>aa;
        archPed.get();
        fecha = juntarFecha(dd,mm,aa);
        indice = buscarFecha(fechaPedidos,fecha);
        if(indice==NO_ENCONTRADO){
            if(capacidad==numDatos)
                aumentarCapFecha(fechaPedidos,codigoPedidos,dniCantPedidos,
                                   numPed,capPed,numDatos,capacidad);
            agregarFecha(fechaPedidos,codigoPedidos,dniCantPedidos,numPed,
                         capPed,fecha,indice,numDatos);
        }
        agregarPedido(codigoPedidos[indice],dniCantPedidos[indice],
                      numPed[indice],capPed[indice],dniCant,codigo);
    }
}

int *leeDniYCant(ifstream &archPed){
    int *dniCant;
    char c;
    dniCant = new int[2];
    archPed>>dniCant[0]>>c>>dniCant[1];
    archPed.get();
    return dniCant;
}

int juntarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

void aumentarCapFecha(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&capPed,
                      int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    if(fechaPedidos==nullptr){
        fechaPedidos = new int[capacidad];
        codigoPedidos = new char**[capacidad];
        dniCantPedidos = new int**[capacidad];
        numPed = new int[capacidad];
        capPed = new int[capacidad];
        fechaPedidos[0] = 0;
        codigoPedidos[0] = nullptr;
        dniCantPedidos[0] = nullptr;
        numPed[0] = 0;
        capPed[0] = 0;
        numDatos++;
    }else{
        cambiarAuxAPuntero(fechaPedidos,codigoPedidos,dniCantPedidos,numPed,
                           capPed,numDatos,capacidad);
    }
}

void cambiarAuxAPuntero(int *&fechaPedidos,char ***&codigoPedidos,
                        int ***&dniCantPedidos,int *&numPed,int *&capPed,
                        int numDatos,int capacidad){
    char ***auxCodPed;
    int ***auxDniCant,*auxFecha,*auxNumPed,*auxCapPed;
    auxFecha = new int[capacidad];
    auxCodPed = new char**[capacidad];
    auxDniCant = new int**[capacidad];
    auxNumPed = new int[capacidad];
    auxCapPed = new int[capacidad];
    for(int i=0;i<numDatos;i++){
        auxFecha[i] = fechaPedidos[i];
        auxCodPed[i] = codigoPedidos[i];
        auxDniCant[i] = dniCantPedidos[i];
        auxNumPed[i] = numPed[i];
        auxCapPed[i] = capPed[i];
    }
    delete fechaPedidos;
    delete codigoPedidos;
    delete dniCantPedidos;
    delete numPed;
    delete capPed;
    fechaPedidos = auxFecha;
    codigoPedidos = auxCodPed;
    dniCantPedidos = auxDniCant;
    numPed = auxNumPed;
    capPed = auxCapPed;
}

int buscarFecha(int *fechaPedidos,int fecha){
    if(fechaPedidos!=nullptr)
        for(int i=0;fechaPedidos[i]!=0;i++)
            if(fechaPedidos[i]==fecha) return i;
    return NO_ENCONTRADO;
}

void agregarFecha(int *&fechaPedidos,char ***&codigoPedidos,
                  int ***&dniCantPedidos,int *&numPed,int *&capPed,
                  int fecha,int &indice,int &numDatos){
    fechaPedidos[numDatos-1] = fecha;
    fechaPedidos[numDatos] = 0;
    codigoPedidos[numDatos] = nullptr;
    dniCantPedidos[numDatos] = nullptr;
    numPed[numDatos] = 0;
    capPed[numDatos] = 0;
    indice = numDatos-1;
    numDatos++;
}

void aumentarCapPedidos(char **&codigoPedidos,int **&dniCantPedidos,
                        int &numDatos,int &capacidad){
    int **auxDniCant;
    char **auxCodPed;
    capacidad += INCREMENTO;
    if(codigoPedidos==nullptr){
        codigoPedidos = new char*[capacidad];
        dniCantPedidos = new int*[capacidad];
        codigoPedidos[0] = nullptr;
        dniCantPedidos[0] = nullptr;
        numDatos++;
    }else{
        auxCodPed = new char*[capacidad];
        auxDniCant = new int*[capacidad];
        for(int i=0;i<numDatos;i++){
            auxCodPed[i] = codigoPedidos[i];
            auxDniCant[i] = dniCantPedidos[i];
        }
        delete codigoPedidos;
        delete dniCantPedidos;
        codigoPedidos = auxCodPed;
        dniCantPedidos = auxDniCant;
    }
}

void agregarPedido(char **&codigoPedidos,int **&dniCantPedidos,int &numPed,
                   int &capPed,int *dniCant,char *codigo){
    if(numPed==capPed)
        aumentarCapPedidos(codigoPedidos,dniCantPedidos,numPed,capPed);
    codigoPedidos[numPed-1] = codigo;
    codigoPedidos[numPed] = nullptr;
    dniCantPedidos[numPed-1] = dniCant;
    dniCantPedidos[numPed] = nullptr;
    numPed++;
}
//Prueba de Lectura de Pedidos
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos){
    int **auxDniCant,*auxDni;
    char **auxCodPed;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;fechaPedidos[i]!=0;i++){
        archRep<<left<<setw(10)<<fechaPedidos[i]<<endl;
        auxCodPed = codigoPedidos[i];
        auxDniCant = dniCantPedidos[i];
        for(int j=0;codigoPedidos[j]!=nullptr;j++){
            auxDni = auxDniCant[j];
            archRep<<left<<setw(10)<<auxCodPed[j]<<setw(15)<<auxDni[0]
                   <<setw(15)<<auxDni[1]<<endl;
        }
        archRep<<endl;
    }
}
//Ordenamiento
void ordenar(int *fechaPedidos,char ***productos,int ***dniCantPedidos){
    int numDatos = 0;
    while(fechaPedidos[numDatos]){
        numDatos++;
    }
    qSort(fechaPedidos,productos,dniCantPedidos,0,numDatos-1);
}

void qSort(int *fechaPedidos,char ***productos,int ***dniCantPedidos,int izq,
           int der){
    int limite,pos;
    if(izq >= der) return;
    pos = (izq+der)/2;
    cambiar(fechaPedidos[izq],productos[izq],dniCantPedidos[izq],
            fechaPedidos[pos],productos[pos],dniCantPedidos[pos]);
    limite = izq;
    for(int i=izq+1;i<=der;i++)
        if(fechaPedidos[i]<fechaPedidos[izq]){
            limite++; 
            cambiar(fechaPedidos[limite],productos[limite],dniCantPedidos[limite],
                    fechaPedidos[i],productos[i],dniCantPedidos[i]);
        }
    cambiar(fechaPedidos[limite],productos[limite],dniCantPedidos[limite],
            fechaPedidos[izq],productos[izq],dniCantPedidos[izq]);
    qSort(fechaPedidos,productos,dniCantPedidos,izq,limite-1);
    qSort(fechaPedidos,productos,dniCantPedidos,limite+1,der);
}

void cambiar(int &fechaPedidosI,char **&productosI,int **&dniCantPedI,
             int &fechaPedidosJ,char **&productosJ,int **&dniCantPedJ){
    int aux,**auxDni;
    char **auxProd;
    aux = fechaPedidosI;
    auxDni = dniCantPedI;
    auxProd = productosI;
    fechaPedidosI = fechaPedidosJ;
    dniCantPedI = dniCantPedJ;
    productosI = productosJ;
    fechaPedidosJ = aux;
    dniCantPedJ = auxDni;
    productosJ = auxProd;
}
//Reporte de Envio de Pedidos
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,
                             int *stock,double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos){
    int posProd,**auxDniCant;
    char **auxCodPed;
    double totIngresos,totPerdido,fechatotIngresado,fechatotPerdido;
    double resumTotIngr=0,resumTotPerd=0;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    imprimirTitulo(archRep);
    for(int i=0;fechaPedidos[i]!=0;i++){
        fechatotIngresado = 0,fechatotPerdido = 0;
        imprimirCabeceraFecha(archRep,fechaPedidos[i]);
        auxCodPed = codigoPedidos[i];
        auxDniCant = dniCantPedidos[i];
        for(int j=0;auxCodPed[j]!=nullptr;j++){
            totIngresos = 0,totPerdido = 0;
            posProd = buscarProducto(productos,auxCodPed[j]);
            archRep<<right<<setw(2)<<j+1<<")  ";
            imprimirFecPed(archRep,productos[posProd],stock[posProd],
                           precios[posProd],auxDniCant[j],totIngresos,
                           totPerdido);
            fechatotIngresado += totIngresos;
            fechatotPerdido += totPerdido;
        }
        imprimirLinea(archRep,'-');
        imprimirResumenFecha(archRep,fechatotIngresado,fechatotPerdido);
        resumTotIngr += fechatotIngresado;
        resumTotPerd += fechatotPerdido;
    }
    imprimirResumenGeneral(archRep,resumTotIngr,resumTotPerd);
}

void imprimirTitulo(ofstream &archRep){
    archRep<<setw(80)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    imprimirLinea(archRep,'=');
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void imprimirCabeceraFecha(ofstream &archRep,int fecha){
    int dd,mm,aa;
    archRep<<"FECHA: ";
    separarFecha(fecha,dd,mm,aa);
    archRep<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
           <<setfill(' ')<<endl;
    imprimirLinea(archRep,'=');
    archRep<<left<<setw(5)<<"No."<<setw(25)<<"DNI"<<setw(61)<<"Producto"
           <<setw(17)<<"Cantidad"<<setw(15)<<"Precio"<<"Total de ingresos"<<endl;
    imprimirLinea(archRep,'-');
}

void separarFecha(int fecha,int &dd,int &mm,int &aa){
    dd = fecha%100;
    mm = (fecha/100)%100;
    aa = fecha/10000;
}

int buscarProducto(char ***productos,char *codigo){
    char **auxProd;
    for(int i=0;productos[i]!=nullptr;i++){
        auxProd = productos[i];
        if(strcmp(auxProd[0],codigo)==0) return i;
    }
}

void imprimirFecPed(ofstream &archRep,char **productos,int &stock,double precio,
                    int *dniCant,double &totIngr,double &totPerd){
    archRep<<left<<setw(16)<<dniCant[0]<<setw(10)<<productos[0]<<setw(60)
           <<productos[1]<<right<<setw(4)<<dniCant[1]<<setw(20)<<precio;
    if(dniCant[1]<stock){
        archRep<<right<<setw(20)<<dniCant[1]*precio<<endl;
        stock -= dniCant[1];
        totIngr += dniCant[1]*precio;
    }else{
        archRep<<right<<setw(21)<<"SIN STOCK"<<endl;
        totPerd += dniCant[1]*precio;
    }
}

void imprimirResumenFecha(ofstream &archRep,double fechatotIngresado,
                          double fechatotPerdido){
    archRep<<left<<setw(35)<<"Total ingresado:"<<right<<setw(100)
           <<fechatotIngresado<<endl;
    archRep<<left<<setw(35)<<"Total perdido por falta de stock:"<<right
           <<setw(100)<<fechatotPerdido<<endl;
    imprimirLinea(archRep,'=');
}

void imprimirResumenGeneral(ofstream &archRep,double resumTotIngr,
                            double resumTotPerd){
    archRep<<"Resumen de ingresos:"<<endl;
    archRep<<left<<setw(35)<<"Total de ingresos en el periodo:"<<right
           <<setw(100)<<resumTotIngr<<endl;
    archRep<<left<<setw(35)<<"Total perdido por falta de stock:"<<right
           <<setw(100)<<resumTotPerd<<endl;
    imprimirLinea(archRep,'=');
}