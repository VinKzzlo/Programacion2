
/*/ 
 * Projecto:  PunterosGenericos-2023-2
 * Nombre del Archivo:  funciones.cpp
 * Autor: void *heart = nullptr;
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
//#include "MuestraPunteros.h"
#define XD -1
#define MAXBUFF 60
#define MAXPED_CLI 100
#define MAXPROD 200
#define MAXCLI 200

                    /*  - / > [ - Pregunta #1 - ] < / -  */

// Modulo de Carga de Registros de Producto
void cargarproductos(void *&productos){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archProd = abrirArchivo_IFS("Productos2.csv");
    void *arrProdRegs[MAXPROD]{},*prodRegs; int numProd = 0;
    // Iterativa del Proceso de Carga de Registros de Producto
    while(1){
        prodRegs = obtenerRegistrosDeProducto(archProd);
        if(prodRegs == nullptr) break;                                          // Validacion de Fin de Proceso
        arrProdRegs[numProd] = prodRegs;
        numProd++;
    }
    // Almacenamiento Compactado de Registros Cargados
    if(numProd > 0) almacenarRegistrosExactos(productos,arrProdRegs,numProd);
    else productos = nullptr;
    // Prueba de Carga de Registros de Productos
    imprimeProductos(productos);
}
// Modulo de Lectura & Enlazamiento de Registros de Producto
void *obtenerRegistrosDeProducto(ifstream &archProd){
    // Declaracion de Variables
    void **arrProdReg; char *prodID,*prodDesc,*prodTipo; double *prodPrecio;
    // Proceso de Lectura & Enlazamiento de Registros de Producto
    prodID = obtenerCadenaExacta(archProd,',');
    if(prodID == nullptr) return nullptr;                                       // Validacion de Retorno por Fin de Proceso
    prodDesc = obtenerCadenaExacta(archProd,',');
    prodPrecio = new double;
    archProd>>*prodPrecio;
    archProd.get();
    prodTipo = new char;
    *prodTipo = archProd.get();
    archProd.get();
    arrProdReg = new void *[4]{};
    arrProdReg[0] = prodID;
    arrProdReg[1] = prodDesc;
    arrProdReg[2] = prodPrecio;
    arrProdReg[3] = prodTipo;
    return arrProdReg;
}
// Modulo de Carga de Registros de Cliente
void cargarclientes(void *&clientes){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archCli = abrirArchivo_IFS("Clientes2.csv");
    void *arrCliRegs[MAXCLI]{},*cliRegs; int numCli = 0;
    // Iterativa del Proceso de Carga de Registros de Cliente
    while(1){
        cliRegs = obtenerRegistrosDeCliente(archCli);
        if(cliRegs == nullptr) break;                                           // Validacion de Fin de Proceso
        arrCliRegs[numCli] = cliRegs;
        numCli++;
    }
    // Almacenamiento Compactado de Registros Cargados
    if(numCli > 0) almacenarRegistrosExactos(clientes,arrCliRegs,numCli);
    else clientes = nullptr;
    // Prueba de Carga de Registros de Clientes
    imprimeClientes(clientes);
}
// Modulo de Lectura & Enlazamiento de Registros de Cliente
void *obtenerRegistrosDeCliente(ifstream &archCli){
    // Declaracion de Variables
    void **arrCliReg; char *cliNomb; int idAux,*cliID; double *cliLC;
    // Proceso de Lectura & Enlazamiento de Registros de Cliente
    archCli>>idAux;
    if(archCli.eof()) return nullptr;                                           // Validacion de Fin de Archivo
    archCli.get();
    cliID = new int;
    *cliID = idAux;
    cliNomb = obtenerCadenaExacta(archCli,',');
    while(archCli.get() != ',');                                                // Descarte de 'Telefono'
    cliLC = new double;
    archCli>>*cliLC;
    arrCliReg = new void *[4]{};
    arrCliReg[0] = cliID;
    arrCliReg[1] = cliNomb;
    arrCliReg[3] = cliLC;
    return arrCliReg;
}

                    /*  - / > [ - Pregunta #2 - ] < / -  */

// Modulo de Procesamiento por Datos de Atencion de Pedidos
void cargarpedidos(void *productos,void *clientes){
    // Apertura de Archivo && Declaracion de Variables
    ifstream archPed = abrirArchivo_IFS("Pedidos2.csv");
    void **arrProdRegs = (void **)productos,**arrCliRegs = (void **)clientes;
    char *prodID; int cliID,cliConsumo,posProd,posCli;
    // Iterativa del Proceso de Atencion de Pedidos
    while(1){
        prodID = obtenerCadenaExacta(archPed,',');
        if(prodID == nullptr) break;                                            // Validacion de Fin de Proceso
        archPed>>cliID;
        archPed.get();
        archPed>>cliConsumo;
        archPed.get();
        posCli = obtenerPosCli(cliID,arrCliRegs);
        posProd = obtenerPosProd(prodID,arrProdRegs);
        // Validacion de Existencia de Cliente y Producto
        if(posCli != XD and posProd != XD){
            actualizarListaDePedidos_Cli(arrProdRegs[posProd],
                                         arrCliRegs[posCli],cliConsumo);
        }
    }
    // Almacenamiento Compactado de SubRegistros Cargados
    compactarSubRegistros_Cli(clientes,arrCliRegs);
}
// Modulo de Actualizacion de Lista de Pedidos de Cliente
void actualizarListaDePedidos_Cli(void *prodRegs,void *cliRegs,int cliConsumo){
    // Declaracion & Inicializacion de Variables
    void **arrProdReg = (void **)prodRegs,**arrCliReg = (void **)cliRegs;
    void **cliPedReg; char *pedProdID,*prodUsaLC = (char *)arrProdReg[3];
    int *pedCant; double *pedMonto,*cliLC = (double *)arrCliReg[3];
    double *prodPrecio = (double *)arrProdReg[2];
    double monto = (*prodPrecio)*cliConsumo;
    // Validacion de Insercion de Nuevo Pedido
    if(*prodUsaLC != 'S' or monto < *cliLC){
        if(*prodUsaLC == 'S') *(double *)arrCliReg[3] -= monto;                 // Validacion Para Descuento de Linea de Credito
        pedProdID = new char[strlen((char *)arrProdReg[0]) + 1];
        strcpy(pedProdID,(char *)arrProdReg[0]);
        pedMonto = new double;
        *pedMonto = monto;
        pedCant = new int;
        *pedCant = cliConsumo;
        cliPedReg = new void *[3];
        cliPedReg[0] = pedProdID;
        cliPedReg[1] = pedCant;
        cliPedReg[2] = pedMonto;
        insertarRegistroDePedido(cliPedReg,arrCliReg[2]);
    }
}
// Modulo de Insercion de Registro de Pedido en Lista
void insertarRegistroDePedido(void *pedReg,void *&pedRegs){
    // Declaracion & Inicializacion de Variables
    void **arrPedReg = (void **)pedRegs; int posProx = 0;
    // Proceso de Insercion de Registro en Proxima Posicion de Lista
    if(!arrPedReg) arrPedReg = new void *[MAXPED_CLI]{};
    while(arrPedReg[posProx]) posProx++;
    arrPedReg[posProx] = pedReg;
    pedRegs = arrPedReg;
}
// Modulo de Compactacion de SubRegistros de Clientes
void compactarSubRegistros_Cli(void *&clientes,void **arrCliRegs){
    // Iterativa del Proceso de Compactacion de SubRegistros de Cliente
    for(int i = 0;arrCliRegs[i];i++){
        void **arrCliReg = (void **)arrCliRegs[i];
        compactarRegistrosDePedidos(arrCliReg[2]);
    }
    // Redireccionamiento de Hacia Datos Compactados
    clientes = arrCliRegs;
}
// Modulo de Compactacion de Lista de Registros de Pedidos
void compactarRegistrosDePedidos(void *&pedRegs){
    // Declaracion de Variables
    void **arrPedReg = (void **)pedRegs,**auxArrPedReg = nullptr;
    int numPed = 0;
    // Validacion de Existencia de Pedidos
    if(arrPedReg){
        while(arrPedReg[numPed]) numPed++;
        auxArrPedReg = new void *[numPed + 1]{};
        for(int i = 0;i < numPed;i++) auxArrPedReg[i] = arrPedReg[i];
    }
    // Redireccionamiento Hacia Datos Exactos
    pedRegs = auxArrPedReg;
}

                    /*  - / > [ - Pregunta #3 - ] < / -  */

// Modulo de Impresion de Reporte de Pedidos
void imprimereporte(void *clientes){
    // Apertura de Archivos && Declaracion de Variables
    ofstream archRep = abrirArchivo_OFS("ReporteDePedidos.txt");
    void **arrCliRegs = (void **)clientes; int medLinea = 96;
    // Inicializacion de Elementos
    archRep<<fixed; archRep.precision(2);
    // Prcoes de Emision de Reporte
    imprimirEncabezado(archRep,medLinea,'C');
    for(int i = 0;arrCliRegs[i];i++){
        imprimirEncabezado(archRep,medLinea,'D');
        imprimirRegistrosDeCliente(archRep,medLinea,arrCliRegs[i],true);
        imprimirLinea(archRep,medLinea,'=');
    }
}
// Modulo de Impresion de Lista de Pedidos Atendidos de Cliente
void imprimirPedidosAtendidosDeCliente(ofstream &archRep,void *cliRegs){
    // Declaracion & Inicializacion de Variables
    void **arrCliReg = (void **)cliRegs;
    void **arrPedRegs = (void **)arrCliReg[2];
    // Validacion de Existencia de Lista
    if(arrPedRegs){
        for(int i = 0;arrPedRegs[i];i++){
            imprimirSubRegistrosDeCliente_Ped(archRep,arrPedRegs[i]);
        }
    }
}

                  /*  - / > [ Funciones Auxiliares ] < / -  */

// Modulo Auxiliar de Apertura de Archivos IFSTREAM
ifstream abrirArchivo_IFS(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch;
    exit(1);
}
// Modulo Auxiliar de Apertura de Archivos OFSTREAM
ofstream abrirArchivo_OFS(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch;
    exit(1);
}
// Modulo de Lectura de Cadena Dinamica Exacta Delimitada
char *obtenerCadenaExacta(ifstream &archEntrada,char delimitador){
    char texto[MAXBUFF]{},*cadena;
    if(delimitador == ' ') archEntrada>>texto;
    else archEntrada.getline(texto,MAXBUFF,delimitador);
    if(archEntrada.eof()) return nullptr;
    cadena = new char[strlen(texto) + 1];
    strcpy(cadena,texto);
    return cadena;
}
// Modulo Auxiliar de Compactacion de Registros Cargados de Primer Nivel
void almacenarRegistrosExactos(void *&regsExactos,void **arrRegs,int numDat){
    // Declaracion & Inicializacion de Variables
    void **auxArrRegs = new void *[numDat + 1]{};
    // Iterativa del Proceso Compactacion Hacia Auxiliar
    for(int i = 0;i < numDat;i++) auxArrRegs[i] = arrRegs[i];
    // Redireccionamiento Hacia Datos Compactados
    regsExactos = auxArrRegs;
}
// Modulo Auxiliar de Busqueda de Cliente en Registros Almacenados
int obtenerPosCli(int cliID,void **arrCliRegs){
    for(int i = 0;arrCliRegs[i];i++)
        if(validarCliente(cliID,arrCliRegs[i])) return i;
    return XD;
}
// Modulo Auxiliar de Comparacion de Identificacion de Cliente por Registro
bool validarCliente(int cliID,void *cliRegs){
    void **arrCliReg = (void **)cliRegs;
    int *cliReg_ID = (int *)arrCliReg[0];
    return (cliID == *cliReg_ID);
}
// Modulo Auxiliar de Busqueda de Producto en Registros Almacenados
int obtenerPosProd(char *prodID,void **arrProdRegs){
    for(int i = 0;arrProdRegs[i];i++)
        if(validarProducto(prodID,arrProdRegs[i])) return i;
    return XD;
}
// Modulo Auxiliar de Comparacion de Identificacion de Producto por Registro
bool validarProducto(char *prodID,void *prodRegs){
    void **arrProdReg = (void **)prodRegs;
    char *prodReg_ID = (char *)arrProdReg[0];
    return (strcmp(prodID,prodReg_ID) == 0);
}
// Modulo de Impresion de Encabezados PREDETERMINADOS de Reportes
void imprimirEncabezado(ofstream &archRep,int dimLinea,char seleccion){
    if(seleccion == 'A'){
        archRep<<setw((dimLinea+35)/2)<<"REPORTE DE INFORMACION DE PRODUCTOS";
        archRep<<endl;
        imprimirLinea(archRep,dimLinea,'=');
        archRep<<setw(10)<<"Codigo"<<setw(9)<<' '<<left;
        archRep<<setw(MAXBUFF)<<"Descripcion"<<right;
        archRep<<setw(12)<<"Precio"<<setw(10)<<"Tipo";
        archRep<<endl;
        imprimirLinea(archRep,dimLinea,'-');
    } else if(seleccion == 'B'){
        archRep<<setw((dimLinea+34)/2)<<"REPORTE DE INFORMACION DE CLIENTES";
        archRep<<endl;
        imprimirLinea(archRep,dimLinea,'=');
        imprimirEncabezado(archRep,dimLinea,'D');
        imprimirLinea(archRep,dimLinea,'-');
    } else if(seleccion == 'C'){
        archRep<<setw((dimLinea+14)/2)<<"REPORTE DE PEDIDOS ATENDIDOS";
        archRep<<" POR CLIENTE"<<endl;
        imprimirLinea(archRep,dimLinea,'=');
    } else if(seleccion == 'D'){
        archRep<<setw(7)<<"DNI"<<setw(13)<<' '<<left<<setw(MAXBUFF)<<"Nombre";
        archRep<<right<<setw(12)<<"Credito"<<endl;
    } else{
        imprimirLinea(archRep,dimLinea,'-');
        archRep<<setw(22)<<"Pedidos atendidos:"<<endl;
        imprimirLinea(archRep,dimLinea,'-');
        archRep<<setw(10)<<"Codigo"<<setw(14)<<"Cantidad"<<setw(12)<<"Total";
        archRep<<endl;
        imprimirLinea(archRep,dimLinea,'-');
    }
}
// Modulo de Impresion de Simbolos en Linea
void imprimirLinea(ofstream &archRep,int medida,char simbolo){
    for(int i = 0;i < medida;i++) archRep.put(simbolo);
    archRep<<endl;
}
// Modulo Auxiliar de Impresion de Reporte de Registros de Productos
void imprimeProductos(void *productos){
    ofstream archRep = abrirArchivo_OFS("InformacionDeProductos.txt");
    int medLinea = 105; void **arrProdRegs = (void **)productos;
    archRep<<fixed; archRep.precision(2);
    imprimirEncabezado(archRep,medLinea,'A');
    for(int i = 0;arrProdRegs[i];i++)
        imprimirRegistrosDeProducto(archRep,arrProdRegs[i]);
    imprimirLinea(archRep,medLinea,'=');
}
// Modulo Auxiliar de Impresion de Registros de Producto
void imprimirRegistrosDeProducto(ofstream &archRep,void *prodRegs){
    void **arrProdReg = (void **)prodRegs; char *prodID = (char *)arrProdReg[0];
    char *prodDesc = (char *)arrProdReg[1],*prodTipo = (char *)arrProdReg[3];
    double *prodPrecio = (double *)arrProdReg[2];
    archRep<<setw(11)<<prodID<<setw(8)<<' '<<left<<setw(MAXBUFF)<<prodDesc;
    archRep<<right<<setw(12)<<*prodPrecio<<setw(9)<<*prodTipo<<endl;
}
// Modulo Auxiliar de Impresion de Reporte de Registros de Clientes
void imprimeClientes(void *clientes){
    ofstream archRep = abrirArchivo_OFS("InformacionDeClientes.txt");
    int medLinea = 96; void **arrCliRegs = (void **)clientes;
    archRep<<fixed; archRep.precision(2);
    imprimirEncabezado(archRep,medLinea,'B');
    for(int i = 0;arrCliRegs[i];i++)
        imprimirRegistrosDeCliente(archRep,medLinea,arrCliRegs[i],false);
    imprimirLinea(archRep,medLinea,'=');
}
// Modulo Auxiliar de Impresion de Registros de Cliente
void imprimirRegistrosDeCliente(ofstream &archRep,int medLinea,void *cliRegs,
                                bool imprimirSubRegistros){
    void **arrCliReg = (void **)cliRegs,**arrPedRegs = (void **)arrCliReg[2];
    int *cliID = (int *)arrCliReg[0]; char *cliNomb = (char *)arrCliReg[1];
    double *cliLC = (double *)arrCliReg[3];    
    archRep<<setw(12)<<*cliID<<setw(8)<<' '<<left<<setw(MAXBUFF)<<cliNomb;
    archRep<<right<<setw(12)<<*cliLC<<endl;
    if(imprimirSubRegistros){
        imprimirEncabezado(archRep,medLinea,'E');
        if(arrPedRegs){
            for(int i = 0;arrPedRegs[i];i++)
                imprimirSubRegistrosDeCliente_Ped(archRep,arrPedRegs[i]);
        } else{
            archRep<<endl<<setw((medLinea+9)/2)<<"> [NO SE CONCRETARON";
            archRep<<" PEDIDOS] <"<<endl<<endl;
        }
    }
}
// Modulo Auxiliar de Impresion de SubRegistros de Cliente [Pedidos]
void imprimirSubRegistrosDeCliente_Ped(ofstream &archRep,void *pedRegs){
    void **arrPedReg = (void **)pedRegs; char *pedProdID = (char *)arrPedReg[0];
    int *pedCliConsumo = (int *)arrPedReg[1];
    double *pedMonto = (double *)arrPedReg[2];
    archRep<<setw(11)<<pedProdID<<setw(10)<<*pedCliConsumo<<setw(15)<<*pedMonto;
    archRep<<endl;
}
