
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  PilaConRegistros.cpp
 * Autor: Redbull te da aaaaalas.jpg
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConRegistros.h"
#define MAXBUFF 100
enum Reg_Ped{RP_PRODID,RP_CANTSOL,RP_PESO};
enum Reg_Camion{RC_PESO_ACUM,RC_PILA};
enum Nodo_Pila{NP_PROX,NP_DATO};

                /*  - / > [ Definicion de Funciones ] < / -  */

// Modulo de Lectura de Registro de Pedido
void *leeregistro(ifstream &archPed){
    // Declaracion de Variables
    void **arrReg_Ped;
    int *pedCantSol;
    double *pedPeso;
    char *prodID;
    // Proceso de Lectura
    prodID = obtenerCadenaExacta(archPed,',');
    if(prodID == nullptr) return nullptr;
    while(archPed.get() != ',');                                                // Descarte de Identificador de Cliente
    pedCantSol = new int;
    archPed>>*pedCantSol;
    archPed.get();                                                              // Descarte de Coma
    pedPeso = new double;
    archPed>>*pedPeso;
    archPed.get();                                                              // Descarte de Coma
    // Proceso de Carga
    arrReg_Ped = new void *[3]{};
    arrReg_Ped[RP_PRODID] = prodID;
    arrReg_Ped[RP_CANTSOL] = pedCantSol;
    arrReg_Ped[RP_PESO] = pedPeso;
    return arrReg_Ped;
}
// Modulo de Calculo de Peso en Registro
double *calcularegistro(void *reg_Ped){
    // Declaracion & Inicializacion de Variables
    void **arrReg_Ped = (void **)reg_Ped;
    double *peso = (double *)arrReg_Ped[RP_PESO];
    // Retorno de Puntero Hacia Peso
    return peso;
}
// Modulo de Comparacion entre Punteros a Registros de Camion de Registros
int cmpregistro(const void *ptrRegs_Camion_a,const void *ptrRegs_Camion_b){
    // Declaracion & Inicializacion de Variables
    void **auxPtrRegs_Camion_a = (void **)ptrRegs_Camion_a;
    void **auxPtrRegs_Camion_b = (void **)ptrRegs_Camion_b;
    void **arrReg_Camion_a = (void **)auxPtrRegs_Camion_a[0];
    void **arrReg_Camion_b = (void **)auxPtrRegs_Camion_b[0];
    double *pesoAcum_a = (double *)arrReg_Camion_a[RC_PESO_ACUM];
    double *pesoAcum_b = (double *)arrReg_Camion_b[RC_PESO_ACUM];
    // Validacion de Retorno
    if(*pesoAcum_a < *pesoAcum_b) return 1;
    if(*pesoAcum_a > *pesoAcum_b) return -1;
    return 0;
}
// Modulo de Impresion de Camion de Registros
void imprimeregistro(ofstream &archSalida,void **arrRegs_Camion,int posRegs){
    // Declaracion de Variables
    void **arrReg_Camion = (void **)arrRegs_Camion[posRegs];
    void **ptrAux = (void **)arrReg_Camion[RC_PILA],**arrReg_Ped;
    int *pedCantSol;
    double *pesoAcumulado = (double *)arrReg_Camion[RC_PESO_ACUM],*pedPeso;
    char *prodID;
    // Proceso de Impresion de Registros de Camion
    archSalida<<"Camion #"<<setfill('0')<<setw(3)<<posRegs+1<<setfill(' ')<<':';
    archSalida<<setw(8)<<"Peso:"<<setw(10)<<*pesoAcumulado<<endl;
    // Proceso de Impresion de Pila de Registros
    while(ptrAux != nullptr){
        arrReg_Ped = (void **)ptrAux[NP_DATO];
        prodID = (char *)arrReg_Ped[RP_PRODID];
        pedCantSol = (int *)arrReg_Ped[RP_CANTSOL];
        pedPeso = (double *)arrReg_Ped[RP_PESO];
        archSalida<<setw(22)<<prodID<<setw(9)<<*pedCantSol<<setw(12)<<*pedPeso;
        archSalida<<endl;
        ptrAux = (void **)ptrAux[NP_PROX];
    }
    archSalida<<endl;
}
// Modulo Auxiliar de Lectura de Cadena Exacta
char *obtenerCadenaExacta(ifstream &archEntrada,char delimitador){
    char buff[MAXBUFF]{},*cadExacta;
    if(delimitador == ' ') archEntrada>>buff;
    else archEntrada.getline(buff,MAXBUFF,delimitador);
    cadExacta = new char[strlen(buff) + 1];
    strcpy(cadExacta,buff);
    return cadExacta;
}
