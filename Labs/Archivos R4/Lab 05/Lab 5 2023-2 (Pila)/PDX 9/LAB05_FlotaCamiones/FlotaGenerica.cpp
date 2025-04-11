
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  FlotaGenerica.cpp
 * Autor: Redbull te da aaaaalas.jpg
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FlotaGenerica.h"
enum RegCamion{RC_PESO_ACUM,RC_PILA};
enum NodoPila{NP_PROX,NP_DATO};

                /*  - / > [ Definicion de Funciones ] < / -  */

// Modulo de Carga Generica de Datos de Camiones
void cargaCamiones(void *&flota,const int numcamiones,const double pesomaximo,
                   void *(*obtenerDato)(ifstream &),
                   double *(*calculaPeso)(void *),const char *nombArch){
    // Declaracion de Variables && Apertura de Archivos
    void *dato,**arrRegs_Camion = new void *[numcamiones]{},**arrReg_Camion;
    int posCamion = 0;
    ifstream archDatos(nombArch,ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
        exit(1);
    }
    // Inicializacion de Elementos de Camion
    for(int i = 0;i < numcamiones;i++){
        arrReg_Camion = new void *[2]{};
        arrReg_Camion[RC_PESO_ACUM] = new double{};
        arrRegs_Camion[i] = arrReg_Camion;
    }
    // Iterativa del Proceso de Carga Generica de Datos de Camion
    while(posCamion < numcamiones){
        dato = obtenerDato(archDatos);
        if(dato == nullptr) break;
        push(dato,arrRegs_Camion,numcamiones,pesomaximo,posCamion,calculaPeso);
    }
    // Validacion por Carga Incompleta
//    if(dato != nullptr){
//        cout<<"El peso de los pedidos excedieron a la capcidad de ";
//        cout<<"los camiones!"<<endl;
//    }
    // Redireccion hacia Datos Cargados
    flota = arrRegs_Camion;
}
// Modulo de Validacion & Insercion Generica de Dato hacia Pila
void push(void *dato,void **arrRegs_Camion,const int numcamiones,
          const double pesomaximo,int &posCamion,
          double *(*calculaPeso)(void *)){
    // Declaracion de Variables
    void **arrReg_Camion = (void **)arrRegs_Camion[posCamion];
    double *pesoAcumulado = (double *)arrReg_Camion[RC_PESO_ACUM];
    double *pesoAgregado = calculaPeso(dato);
    // Validaciones por Capacidad de Peso & Posicion de Nuevo Camion
    if(*pesoAcumulado + *pesoAgregado > pesomaximo) posCamion++;
    if(posCamion >= numcamiones) return;
    // Proceso de Insercion Generica de Datos en Pila
    agregarDatosHaciaPila(dato,arrRegs_Camion[posCamion],pesoAgregado);
}
// Modulo de Insercion Generica de Dato Hacia Pila
void agregarDatosHaciaPila(void *dato,void *regs_Camion,double *pesoAgregado){
    // Declaracion de Variables
    void **arrReg_Dato = (void **)dato;
    void **arrReg_Camion = (void **)regs_Camion;
    double *pesoAcumulado = (double *)arrReg_Camion[RC_PESO_ACUM];
    void **nodoAux = (void **)arrReg_Camion[RC_PILA];
    void **nodoNuevo = new void *[2]{};
    nodoNuevo[NP_DATO] = arrReg_Dato;
    if(!pilavacia(nodoAux)) nodoNuevo[NP_PROX] = nodoAux;
    arrReg_Camion[RC_PILA] = nodoNuevo;
    *pesoAcumulado += *pesoAgregado;
}
// Modulo de Validacion de Pila Vacia
bool pilavacia(void **pila){
    return pila == nullptr;
}
// Modulo de Impresion Generica de Datos de Camion
void muestraCamiones(void *flota,const int numcamiones,
                     void (*imprimeElemento)(ofstream &,void **,int),
                     const char *nombArch){
    // Declaracion de Variables && Apertura de Archivos
    void **arrRegs_Camion = (void **)flota;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
        exit(1);
    }
    // Inicializacion de Elementos
    archRep<<fixed;
    archRep.precision(2);
    // Iterativa del Proceso de Impresion Generica
    for(int i=0;i < numcamiones;i++) imprimeElemento(archRep,arrRegs_Camion,i);
}
