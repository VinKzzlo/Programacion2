/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 5 de abril de 2024, 23:41
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 140
//Lectura de Productos
/*
BIT-434,Campana Extractora modelo Glass,375.09,10
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23
*/
void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios){
    char **buffProductos[200],c;
    double buffPrecio[200];
    int buffStock[200];
    
    ifstream archProd(nombArch,ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int i=0;
    while(1){
        buffProductos[i] = leerProductos(archProd);
        if(archProd.eof()) break;
        archProd>>buffPrecio[i]>>c>>buffStock[i];
        archProd.get();
        i++;
    }
    int n=i;
    //Para la prueba de lectura se tomara como bandera del fin del arreglo
    //al nullptr de la variable "productos", por eso tiene n+1, para agregar
    //el nullptr al final, el resto no necesita porque se guian de la misma
    //cantidad de elementos
    productos = new char**[n+1];
    stock = new int[n];
    precios = new double[n];
    
    for(i=0;i<n;i++){
        productos[i] = buffProductos[i];
        stock[i] = buffStock[i];
        precios[i] = buffPrecio[i];
    }
    productos[n] = buffProductos[n];    //Agrega el nullptr
}
//Lectura de productos al segundo nivel del puntero
char **leerProductos(ifstream &archProd){
    char **dupla,*cadena;
    
    cadena = leeCadena(archProd,8,',');
    if(archProd.eof()) return nullptr;
    //Se asigna la memoria de dupla despues de verificar que leyo
    //Sino, error de concepto por desperdicio de memoria
    dupla = new char*[2];
    dupla[0] = cadena;
    dupla[1] = leeCadena(archProd,60,',');
    return dupla;
}
//Lectura de cadena al primer nivel del puntero
char *leeCadena(ifstream &archProd,int max,char delim){
    char buff[max],*cad;
    
    archProd.getline(buff,max,delim);
    if(archProd.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    char **dupla;
    
    for(int i=0;productos[i]!=nullptr;i++){
        dupla = productos[i];
        //dupla[0] tiene el codigo, dupla[1] tiene la descripcion
        archRep<<setw(10)<<dupla[0]<<setw(60)<<dupla[1]
               <<setw(10)<<precios[i]<<setw(5)<<stock[i]<<endl;
    }
}
/*
JXD-139,50375303,6,24/08/2023
CRU-009,50375303,5,3/09/2023
*/
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos){
    int buffFecha[600],**buffCantPed[600],dni,cant,dd,mm,aa,fecha,indice,i=0;
    int numPed[600];
    char **buffCodPed[600],*codigo,c;
    
    ifstream archPed(nombArch,ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    //El i se comporta como un posicionFecha dentro del arreglo de fechas, y la 
    //misma posicion tendran los otros arr para los pedidos e info de esa fecha
    while(1){
        codigo = leeCadena(archPed,8,',');
        if(archPed.eof()) break;
        archPed>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        archPed.get();
        //Analizamos primero la fecha
        fecha = juntarFecha(dd,mm,aa);
        indice = buscarFecha(buffFecha,fecha,i);
        if(indice==NO_ENCONTRADO){
            agregarFecha(buffFecha,buffCodPed,buffCantPed,fecha,numPed,indice,i);
        }
        agregarPedido(buffCodPed[indice],buffCantPed[indice],numPed[indice],
                      dni,cant,codigo);
    }
    cargarArreglos(fechaPedidos,codigoPedidos,dniCantPedidos,
                   buffFecha,   buffCodPed,   buffCantPed,  numPed,i);
}

int juntarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

int buscarFecha(int *buffFecha,int fecha,int n){
    for(int i=0;i<n;i++)
        if(buffFecha[i]==fecha) return i;
    return NO_ENCONTRADO;
}

void agregarFecha(int *buffFecha,char ***buffCodPed,int ***buffCantPed,
                  int fecha,int *numPed,int &indice,int &i){
    //Al agregar una nueva fecha, viene consigo con los datos de los pedidos
    //y la cantidad pedida de los clientes (nueva informacion para los otros
    //arreglos), el i va a indicar la cantidad total de fechas que hay.
    buffFecha[i] = fecha;
    buffCodPed[i] = new char*[600];
    buffCantPed[i] = new int*[600];
    numPed[i] = 0;
    indice = i;
    i++;
}

void agregarPedido(char **buffcod,int **buffdni,int &n,int dni,int cant,
                   char *codigo){
    //Independientemente de si se agrega una nueva fecha, se pueden agregar mas
    //de un pedido en cada fecha, el n (numPed[indice]) (indice tambien se puede
    //llamar como posicionFecha) determinara la cantidad de pedidos en una fecha
    int *aux;
    //Agregar al buffCantPed[indice]
    buffdni[n] = new int[2];
    aux = buffdni[n];
    aux[0] = dni; //Usamos el aux para no usar doble indice
    aux[1] = cant;
    /*Otra forma:
    int *aux = new int[2];
    aux[0] = dni;
    aux[1] = cant;
    buffdni[n] = aux;*/
    //Agregar al buffCodPed[indice]
    buffcod[n] = codigo;
    n++;
}

void cargarArreglos(int *&fechaPedidos,char ***&codigoPedidos,
                    int ***&dniCantPedidos,int *buffFecha,char ***buffCodPed,
                    int ***buffCantPed,int *numPed,int n){
    //Pasamos los punteros por referencia porque todavia no modificamos su 
    //espacio de memoria
    fechaPedidos = new int[n+1];
    codigoPedidos = new char**[n];
    dniCantPedidos = new int**[n];
    
    for(int i=0;i<n;i++){
        fechaPedidos[i] = buffFecha[i];
        //Le designamos la cantidad de memoria exacta de la cantidad de pedidos
        //que hubieron en esa fecha, +1 para el codigo porque a ese le
        //asignaremos el nullptr
        codigoPedidos[i] = new char*[numPed[i]+1];
        dniCantPedidos[i] = new int*[numPed[i]];
        cargaNivelInterno(codigoPedidos[i],dniCantPedidos[i],buffCodPed[i],
                          buffCantPed[i],numPed[i]);
        //Aqui se eliminan los buffers dinamicos
        delete buffCodPed[i];
        delete buffCantPed[i];
    }
    //Un 0 como ultimo dato como fin del arreglo, no podemos poner nullptr
    //porque no apunta a nada, es un int, no es como para una cadena de char
    fechaPedidos[n] = 0;
}

void cargaNivelInterno(char **&codigoped,int **&dnicantped,char **buffcodped,
                       int **buffcantped,int cantPed){
    for(int i=0;i<cantPed;i++){
        codigoped[i] = buffcodped[i];
        dnicantped[i] = buffcantped[i];
    }
    //Le ponemos nullptr al ultimo codigo para tener una bandera al momento de
    //imprimir los productos de los pedidos y los dnis que estan a la par
    codigoped[cantPed] = nullptr;
}

void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos){
    char **auxCod;
    int **auxDni,*auxDniCant;
    
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    for(int i=0;fechaPedidos[i]!=0;i++){
        archRep<<fechaPedidos[i]<<endl;
        auxCod = codigoPedidos[i];
        auxDni = dniCantPedidos[i];
        for(int j=0;auxCod[j]!=nullptr;j++){
            auxDniCant = auxDni[j]; //aux para no usar doble indice
            archRep<<setw(10)<<auxCod[j]<<setw(15)<<auxDniCant[0]<<" "
                   <<auxDniCant[1]<<endl;
        }
        archRep<<endl;
    }
}
//Reporte de Envio de Pedidos
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
                             double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos){
    int dd,mm,aa,posProd,**auxDni,*auxDniCant;
    double totIngr,totPerd,TOTINGRESOS = 0,TOTPERDIDO = 0;
    char **auxCod,**auxProd;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    archRep<<setw(70)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;fechaPedidos[i]!=0;i++){
        totIngr = 0,totPerd = 0;
        separarFecha(fechaPedidos[i],dd,mm,aa);
        archRep<<"FECHA:  "<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm
               <<'/'<<aa<<setfill(' ')<<endl;
        imprimirLinea(archRep,'=');
        archRep<<right<<"No."<<setw(6)<<"DNI"<<setw(26)<<"Producto"<<setw(60)
               <<"Cantidad"<<setw(12)<<"Precio"<<setw(20)<<"Total de ingresos"
               <<endl;
        imprimirLinea(archRep,'-');
        auxCod = codigoPedidos[i];
        auxDni = dniCantPedidos[i];
        for(int j=0;auxCod[j]!=nullptr;j++){
            auxDniCant = auxDni[j];
            posProd = buscarProducto(productos,auxCod[j]);
            auxProd = productos[posProd];
            archRep<<right<<setw(2)<<j+1<<')'<<setw(11)<<auxDniCant[0]<<setw(15)
                   <<auxProd[0]<<"  "<<left<<setw(60)<<auxProd[1]<<right
                   <<setw(2)<<auxDniCant[1]<<setw(15)<<precios[posProd];
            if(auxDniCant[1]<stock[posProd]){
                archRep<<right<<setw(15)<<auxDniCant[1]*precios[posProd]<<endl;
                totIngr += auxDniCant[1]*precios[posProd];
                stock[posProd] -= auxDniCant[1];    //Debe descontar el stock
            }
            else{
                archRep<<right<<setw(16)<<"SIN STOCK"<<endl;
                totPerd += auxDniCant[1]*precios[posProd];
            }
        }
        imprimirLinea(archRep,'-');
        archRep<<left<<setw(35)<<"Total ingresado:"<<right<<setw(88)<<totIngr
               <<endl;
        archRep<<left<<setw(35)<<"Total perdido por falta de stock:"<<right
               <<setw(88)<<totPerd<<endl;
        TOTINGRESOS += totIngr;
        TOTPERDIDO += totPerd;
        imprimirLinea(archRep,'=');
    }
    archRep<<"Resumen de ingresos:"<<endl;
    archRep<<left<<setw(35)<<"Total de ingresos en el periodo:"<<right<<setw(88)
           <<TOTINGRESOS<<endl;
    archRep<<left<<setw(35)<<"Total perdido por falta de stock"<<right<<setw(88)
           <<TOTPERDIDO<<endl;
    imprimirLinea(archRep,'=');
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void separarFecha(int fecha,int &dd,int &mm,int &aa){
    dd = fecha%100;
    mm = (fecha/100)%100;
    aa = fecha/10000;
}

int buscarProducto(char ***productos,char *codProd){
    char **auxProductos;
    for(int i=0;productos[i]!=nullptr;i++){
        auxProductos = productos[i];
        if(strcmp(auxProductos[0],codProd)==0) return i;
    }
    return NO_ENCONTRADO;
}