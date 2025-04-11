
/*/ 
 * Projecto:  LAB05_FlotaCamiones
 * Nombre del Archivo:  PilaConEnteros.cpp
 * Autor: Redbull te da aaaaalas.jpg
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"
enum Reg_Num{RN_PESO};
enum Reg_Camion{RC_PESO_ACUM,RC_PILA};
enum Nodo_Pila{NP_PROX,NP_DATO};

                /*  - / > [ Definicion de Funciones ] < / -  */

// Modulo de Lectura de Numero
void *leenumero(ifstream &archNum){
    // Declaracion de Variables
    void **arrReg_Num;
    double num;
    // Proceso de Lectura
    archNum>>num;
    if(archNum.eof()) return nullptr;                                           // Validacion de Fin de Archivo
    // Proceso de Carga
    arrReg_Num = new void *[1]{};
    arrReg_Num[RN_PESO] = new double{num};
    return arrReg_Num;
}
// Modulo de Calculo de Peso en Numero
double *calculanumero(void *num){
    // Declaracion & Inicializacion de Variables
    void **arrReg_Num = (void **)num;
    double *peso = (double *)arrReg_Num[RN_PESO];
    // Retorno de Puntero Hacia Peso
    return peso;
}
// Modulo de Comparacion entre Punteros a Registros de Camion de Numeros
int cmpnumero(const void *ptrRegs_Camion_a,const void *ptrRegs_Camion_b){
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
// Modulo de Impresion de Camion de Numeros
void imprimenumero(ofstream &archSalida,void **arrRegs_Camion,int posRegs){
    // Declaracion de Variables
    void **arrReg_Camion = (void **)arrRegs_Camion[posRegs];
    void **ptrAux = (void **)arrReg_Camion[RC_PILA],**arrReg_Num;
    double *pesoAcumulado = (double *)arrReg_Camion[RC_PESO_ACUM];
    double *ptrNum;
    // Proceso de Impresion de Registros de Camion
    archSalida<<"Camion #"<<setfill('0')<<setw(2)<<posRegs+1<<setfill(' ')<<':';
    archSalida<<setw(9)<<"Peso:"<<setw(7)<<*pesoAcumulado<<endl;
    // Proceso de Impresion de Pila de Pesos de Numero
    while(ptrAux != nullptr){
        arrReg_Num = (void **)ptrAux[NP_DATO];
        ptrNum = (double *)arrReg_Num[RN_PESO];
        archSalida<<*ptrNum<<endl;
        ptrAux = (void **)ptrAux[NP_PROX];
    }
    archSalida<<endl;
}
