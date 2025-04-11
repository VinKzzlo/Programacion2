
/*/ 
 * Projecto:  AsignacionDinamicaMemoriaPorIncrementos-2023-2
 * Nombre del Archivo:  AsignacionDinamicaMemoriaExacta.cpp
 * Autor: XxGatitaDinamica69xX
/*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define XD -1
#define INCREMENTO 5
#define MAXTEXTO 60
#define MAXFECHAS 200

                    /*  - / > [ - Pregunta #1 - ] < / -  */

// Proceso de Carga de Datos de Producto || Prueba de Carga de Datos de Productos
void lecturaDeProducto(const char *nombProdArch,char ***&productos,int *&stock,
                       double *&precios){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archProd = abrirArchivo_IFS(nombProdArch);
    int numDat = 0,cap = 0,posProd,prodStock; double prodPrecio;
    char *prodID,*prodNomb;
    // Inicializacion de Elementos
    productos = nullptr;
    stock = nullptr;
    precios = nullptr;
    // Iterativa del Proceso de Carga de Datos de Producto por Incremento
    while(1){
        prodID = obtenerCadenaExacta(archProd,',');
        if(prodID == nullptr) break;                                            // Validacion de Fin de Proceso
        prodNomb = obtenerCadenaExacta(archProd,',');
        archProd>>prodPrecio;
        archProd.get();                                                         // Descarte de 'Coma'
        archProd>>prodStock;
        archProd.get();                                                         // Descarte de 'Enter'
        // Validacion de Incremento de Capacidad
        if(numDat == cap)
            incrementarCapacidad(productos,stock,precios,numDat,cap);
        // Insercion de Datos de Producto
        posProd = numDat - 1;
        stock[posProd] = prodStock;
        precios[posProd] = prodPrecio;
        productos[posProd] = new char*[2];
        (productos[posProd])[0] = prodID;
        (productos[posProd])[1] = prodNomb;
        numDat++;
    }
}
// Modulo de Incremento de Capacidad de Arreglos Dinamicos de Datos de Producto
void incrementarCapacidad(char ***&productos,int *&stock,double *&precios,
                          int &numDat,int &cap){
    // Aumento de Capacidad de Arreglos
    cap += INCREMENTO;
    // Declaracion de Variables
    int *auxStock = new int[cap]{}; double *auxPrecios = new double[cap]{};
    char ***auxProductos = new char **[cap]{};
    // Validacion de Existencia de Elementos
    if(productos){
        for(int i = 0;i < numDat;i++){
            auxProductos[i] = productos[i];
            auxPrecios[i] = precios[i];
            auxStock[i] = stock[i];
        }
        delete productos;
        delete precios;
        delete stock;
    } else numDat = 1;
    // Inicializacion de Elementos
    productos = auxProductos;
    precios = auxPrecios;
    stock = auxStock;
}
// Modulo de Prueba de Impresion de Carga de Datos de Producto || Modulo de Impresion de Reporte de Estado de Productos
void pruebaDeLecturaDeProductos(const char *nombRepArch,char ***productos,
                                int *stock,double *precios){
    // Declaracion de Variables && Apertura de Archivos
    int medLinea = 101; ofstream archRep = abrirArchivo_OFS(nombRepArch);
    // Inicializacion de Elementos
    archRep<<fixed; archRep.precision(2);
    // Proceso de Impresion de Reporte de Estado de Productos
    imprimirEncabezado(archRep,'A',medLinea);
    for(int i = 0;productos[i];i++){
        archRep<<setw(11)<<(productos[i])[0]<<setw(4)<<' '<<left;
        archRep<<setw(MAXTEXTO)<<(productos[i])[1]<<right;
        archRep<<setw(6)<<stock[i]<<setw(16)<<precios[i]<<endl;
    }
    imprimirLinea(archRep,medLinea,'=');
}

                    /*  - / > [ - Pregunta #2 - ] < / -  */

// Proceso de Carga de Datos de Pedidos || Prueba de Carga de Datos de Pedidos
void lecturaDePedidos(const char *nombPedArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archPed = abrirArchivo_IFS(nombPedArch);
    int numDat = 0,cap = 0,dni,cantidad,fecha,posFecha;
    int arrCap_Fecha[MAXFECHAS]{},arrNd_Fecha[MAXFECHAS]{}; char *prodID;
    // Inicializacion de Elementos
    fechaPedidos = nullptr;
    codigoPedidos = nullptr;
    dniCantPedidos = nullptr;
    // Iterativa del Proceso de Carga de Datos de Pedidos
    while(1){
        prodID = obtenerCadenaExacta(archPed,',');
        if(prodID == nullptr) break;                                            // Validacion de Fin de Proceso
        archPed>>dni;
        archPed.get();                                                          // Descarte de 'Coma'
        archPed>>cantidad;
        archPed.get();                                                          // Descarte de 'Coma'
        fecha = obtenerFecha(archPed);
        archPed.get();                                                          // Descarte de 'Enter'
        posFecha = obtenerPosFecha(fecha,fechaPedidos,numDat);
        // Validacion por Nuevo Registro de Fecha
        if(posFecha == XD){
            // Validacion de Incremento de Capacidad
            if(numDat == cap){
                incrementarCapacidad(codigoPedidos,dniCantPedidos,fechaPedidos,
                                     numDat,cap);
            }
            posFecha = numDat - 1;
            fechaPedidos[posFecha] = fecha;
            numDat++;
        }
        // Proceso de Insercion de Datos por Fecha
        insertarDatosDeFecha(prodID,dni,cantidad,codigoPedidos[posFecha],
                             dniCantPedidos[posFecha],arrCap_Fecha[posFecha],
                             arrNd_Fecha[posFecha]);
    }
}
// Modulo de Incremento de Capacidad de Arreglos Dinamicos de Datos de Pedido
void incrementarCapacidad(char ***&codigoPedidos,int ***&dniCantPedidos,
                          int *&fechaPedidos,int &numDat,int &cap){
    // Aumento de Capacidad de Arreglos
    cap += INCREMENTO;
    // Declaracion de Variables
    int ***auxArrPedInfo = new int**[cap]{}, *auxArrFechas = new int[cap]{};
    char ***auxArrProdIDs = new char**[cap]{};
    // Validacion de Existencia de Elementos
    if(fechaPedidos){
        for(int i = 0;i < numDat;i++){
            auxArrFechas[i] = fechaPedidos[i];
            auxArrPedInfo[i] = dniCantPedidos[i];
            auxArrProdIDs[i] = codigoPedidos[i];
        }
        delete fechaPedidos;
        delete dniCantPedidos;
        delete codigoPedidos;
    } else numDat = 1;
    // Inicializacion de Elementos
    fechaPedidos = auxArrFechas;
    dniCantPedidos = auxArrPedInfo;
    codigoPedidos = auxArrProdIDs;
}
// Modulo de Insercion de Datos de Fecha por Incremento
void insertarDatosDeFecha(char *prodID,int dni,int cantidad,char **&prodIDs,
                          int **&pedInfo,int &cap,int &numDat){
    // Declaracion de Variables
    int posPed;
    // Validacion de Incremento de Capacidad
    if(numDat == cap) incrementarCapacidad(prodIDs,pedInfo,cap,numDat);
    // Insercion de Datos de Fecha
    posPed = numDat - 1;
    prodIDs[posPed] = prodID;
    pedInfo[posPed] = new int[2]{};
    (pedInfo[posPed])[0] = dni;
    (pedInfo[posPed])[1] = cantidad;
    numDat++;
}
// Modulo de Incremento de Capacidad de Arreglos Dinamicos de Datos de Pedido de Fecha
void incrementarCapacidad(char **&prodIDs,int **&pedInfo,int &cap,int &numDat){
    // Aumento de Capacidad de Arreglos
    cap += INCREMENTO;
    // Declaracion de Variables
    char **auxProdIDs = new char *[cap]{}; int **auxPedInfo = new int *[cap]{};
    // Validacion de Existencia de Elementos
    if(pedInfo){
        for(int i = 0;i < numDat;i++){
            auxProdIDs[i] = prodIDs[i];
            auxPedInfo[i] = pedInfo[i];
        }
        delete prodIDs;
        delete pedInfo;
    } else numDat = 1;
    // Inicializacion de Elementos
    prodIDs = auxProdIDs;
    pedInfo = auxPedInfo;
}
// Modulo de Prueba de Impresion de Carga de Datos de Pedidos por Fecha
void pruebaDeLecturaDePedidos(const char *nombArchRep,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos){
    // Declaracion de Variables && Apertura de Archivos
    int medLinea = 44; ofstream archRep = abrirArchivo_OFS(nombArchRep);
    // Proceso de Impresion de Reporte de Datos de Pedidos por Fecha
    imprimirEncabezado(archRep,'B',medLinea);
    for(int i = 0;fechaPedidos[i];i++){
        archRep<<setw((44-10)/2)<<' ';
        imprimirFecha(archRep,fechaPedidos[i]);
        archRep<<endl;
        imprimirEncabezado(archRep,'C',medLinea);
        for(int j = 0;(codigoPedidos[i])[j];j++){
            archRep<<setw(12)<<((dniCantPedidos[i])[j])[0];
            archRep<<setw(15)<<(codigoPedidos[i])[j];
            archRep<<setw(10)<<((dniCantPedidos[i])[j])[1];
            archRep<<endl;
        }
        imprimirLinea(archRep,medLinea,'=');
    }
}

                    /*  - / > [ - Pregunta #3 - ] < / -  */

// Emision de Reporte de Envio de Pedidos
void reporteDeEnvioDePedidos(const char *nombArchRep,char ***productos,
                             int *&stock,double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos){
    // Apertura de Archivos && Declaracion de Variables
    ofstream archRep = abrirArchivo_OFS(nombArchRep);
    int medLinea = 138; double ingreso_Fecha,perdida_Fecha;
    double ingresoTotal = 0,perdidaTotal = 0;
    // Inicializacion de Elementos
    archRep<<fixed; archRep.precision(2);
    // Proceso de Impresion de Reporte de Envio de Pedidos
    imprimirEncabezado(archRep,'D',medLinea);
    for(int i = 0;fechaPedidos[i];i++){
        archRep<<setw(12)<<"FECHA:  ";
        imprimirFecha(archRep,fechaPedidos[i]);
        archRep<<endl;
        imprimirEncabezado(archRep,'E',medLinea);
        procesarPedidosDeFecha(archRep,productos,stock,precios,codigoPedidos[i],
                               dniCantPedidos[i],ingreso_Fecha,perdida_Fecha);
        procesarResumen_Fecha(archRep,medLinea,ingreso_Fecha,perdida_Fecha);
        ingresoTotal += ingreso_Fecha;
        perdidaTotal += perdida_Fecha;
    }
    procesarResumen_Total(archRep,medLinea,ingresoTotal,perdidaTotal);
}
// Modulo de Procesamiento de Pedidos durante Fecha
void procesarPedidosDeFecha(ofstream &archRep,char ***productos,int *&stock,
                            double *precios,char **prodIDs,int **pedInfo,
                            double &ingreso,double &perdida){
    // Declaracion de Variables && Inicializacion de Variables
    int numPed = 0; double monto_Ped;
    ingreso = 0; perdida = 0;
    // Iterativa del Proceso de Emision de Pedidos durante Fecha
    for(int j = 0,posProd;prodIDs[j];j++){
        posProd = obtenerPosProd(prodIDs[j],productos);
        // Validacion de Existencia de Producto
        if(posProd != XD){
            archRep<<setw(5)<<numPed+1<<")  "<<(pedInfo[j])[0];
            archRep<<setw(15)<<(productos[posProd])[0]<<setw(2)<<' '<<left;
            archRep<<setw(MAXTEXTO)<<(productos[posProd])[1]<<right;
            archRep<<setw(6)<<(pedInfo[j])[1];
            archRep<<setw(14)<<precios[posProd];
            monto_Ped = (pedInfo[j])[1]*precios[posProd];
            // Validacion de Existencia de Stock Disponible
            if((pedInfo[j])[1] <= stock[posProd]){
                stock[posProd] -= (pedInfo[j])[1];
                ingreso += monto_Ped;
                archRep<<setw(16)<<monto_Ped;
            } else{
                perdida += monto_Ped;
                archRep<<setw(17)<<"SIN STOCK";
            }
            archRep<<endl;
            numPed++;
        }
    }
}
// Modulo de Emision de Resumen Parcial por Fecha de Ingresos y Perdidas durante Perdidos
void procesarResumen_Fecha(ofstream &archRep,int medLinea,double ingreso,
                           double perdida){
    imprimirLinea(archRep,medLinea,'-');
    archRep<<setw(20)<<"Total ingresado:";
    archRep<<setw(medLinea - 29)<<ingreso<<endl;
    archRep<<setw(37)<<"Total perdido por falta de stock:";
    archRep<<setw(medLinea - 46)<<perdida<<endl;
    imprimirLinea(archRep,medLinea,'=');
}
// Modulo de Emision de Resumen Total de Ingresos y Perdidas durante Periodo
void procesarResumen_Total(ofstream &archRep,int medLinea,double ingreso,
                           double perdida){
    archRep<<setw(36)<<"Total de ingresos en el periodo:";
    archRep<<setw(medLinea - 45)<<ingreso<<endl;
    archRep<<setw(37)<<"Total perdido por falta de stock:";
    archRep<<setw(medLinea - 46)<<perdida<<endl;
    imprimirLinea(archRep,medLinea,'=');
}

                  /*  - / > [ Funciones Auxiliares ] < / -  */

// Modulo de Apertura de Archivos IFSTREAM
ifstream abrirArchivo_IFS(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
    exit(1);
}
// Modulo de Apertura de Archivos OFSTREAM
ofstream abrirArchivo_OFS(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
    exit(1);
}
// Modulo de Lectura de Cadena Exacta
char *obtenerCadenaExacta(ifstream &archEntrada,char delimitador){
    char texto[MAXTEXTO]{},*cadena;
    if(delimitador == ' ') archEntrada>>texto;
    else archEntrada.getline(texto,MAXTEXTO,delimitador);
    if(archEntrada.eof()) return nullptr;
    cadena = new char[strlen(texto) + 1];
    strcpy(cadena,texto);
    return cadena;
}
// Modulo de Impresion de Encabezados PREDETERMINADOS de Reporte
void imprimirEncabezado(ofstream &archSalida,char seleccion,int dimension){
    if(seleccion == 'A'){
        archSalida<<setw((dimension + 30)/2)<<"REPORTE DE ESTADO DE PRODUCTOS";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'=');
        archSalida<<setw(10)<<"CODIGO";
        archSalida<<setw(5)<<' '<<left<<setw(MAXTEXTO)<<"NOMBRE"<<right;
        archSalida<<setw(8)<<"STOCK";
        archSalida<<setw(14)<<"PRECIO"<<endl;
        imprimirLinea(archSalida,dimension,'-');
    } else if(seleccion == 'B'){
        archSalida<<setw((dimension + 26)/2)<<"REPORTE PEDIDOS REALIZADOS POR ";
        archSalida<<"FECHA"<<endl;
        imprimirLinea(archSalida,dimension,'=');
    }else if(seleccion == 'C'){
        imprimirLinea(archSalida,dimension,'-');
        archSalida<<setw(9)<<"DNI";
        archSalida<<setw(19)<<"PRODUCTO";
        archSalida<<setw(12)<<"CANTIDAD"<<endl;
        imprimirLinea(archSalida,dimension,'-');
    }else if(seleccion == 'D'){
        archSalida<<setw((dimension + 29)/2)<<"REPORTE DE ENTREGA DE PEDIDOS";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'=');
    } else{
        imprimirLinea(archSalida,dimension,'=');
        archSalida<<setw(6)<<"No."<<setw(5)<<"DNI"<<setw(17)<<' ';
        archSalida<<left<<setw(MAXTEXTO - 3)<<"Producto"<<right;
        archSalida<<setw(17)<<"Cantidad"<<setw(11)<<"Precio";
        archSalida<<setw(21)<<"Total de ingresos";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'-');
    }
}
// Modulo de Impresion de Simbolos en Linea
void imprimirLinea(ofstream &archSalida,int medida,char simbolo){
    for(int i = 0;i < medida;i++) archSalida.put(simbolo);
    archSalida<<endl;
}
// Modulo de Carga de Dato Temporal [Fecha]
int obtenerFecha(ifstream &archEntrada){
    int dd,mm,aa;
    archEntrada>>dd;
    archEntrada.get();
    archEntrada>>mm;
    archEntrada.get();
    archEntrada>>aa;
    return dd+100*mm+10000*aa;
}
// Modulo de Impresion de Dato Temporal [Fecha]
void imprimirFecha(ofstream &archSalida,int fecha){
    int aa = fecha/10000;
    int mm = (fecha - aa*10000)/100;
    int dd = fecha - mm*100 - aa*10000;
    archSalida.fill('0');
    archSalida<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa;
    archSalida.fill(' ');
}
// Modulo de Busqueda de Posicion de Fecha Almacenada
int obtenerPosFecha(int fecha,int *arrFechas,int numFechas){
    for(int i = 0;i < numFechas;i++) if(arrFechas[i] == fecha) return i;
    return XD;
}
// Modulo de Busqueda de Posicion de Codigo de Producto Almacenado
int obtenerPosProd(char *prodID,char ***arrProdBuff){
    for(int i = 0;(arrProdBuff[i])[0];i++)
        if(strcmp((arrProdBuff[i])[0],prodID) == 0) return i;
    return XD;
}
