/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 8 de abril de 2024, 15:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoExacto.h"
#define MAX_MED_PAC 200
#define MAX_LINEA 140
//Lectura de Medicos
/*
506117,EDGAR MUNOZ VERGEL Urologia,337.03
150928,LUZ SOFIA JAUREGUI BRAVO Dermatologia,756.45
*/
void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
                      char **&med_Especialidad,double *&med_Tarifa){
    int buffCod[50],cod;
    char *buffNomb[50],*buffEsp[50];
    double buffTar[50];
    
    ifstream archMed(nombArch,ios::in);
    if(not archMed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        archMed>>cod;
        if(archMed.eof()) break;
        buffCod[i] = cod;
        archMed.get();
        buffNomb[i] = leeCadenaExacta(archMed,60,',');
        asignaNombreYEspecialidad(archMed,buffNomb[i],buffEsp[i]);
        archMed>>buffTar[i];
        i++;
    }
    cargaArrMedicos(med_Codigo,med_Nombre,med_Especialidad,med_Tarifa,
                    buffCod,   buffNomb,  buffEsp,         buffTar,   i);
}

char *leeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[500],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void asignaNombreYEspecialidad(ifstream &archMed,char *nombre,char *&buffEspI){
    char especialidad[60];
    int i,cont=0;
    for(i=strlen(nombre);nombre[i]!=' ';i--,cont++);
    //Importante: nombre[i] == ' '
    int aux=i,j;
    for(j=0;j<cont;i++,j++)
        especialidad[j] = nombre[i+1];
    especialidad[j] = '\0';
    nombre[aux] = '\0';
    buffEspI = new char[strlen(especialidad)+1];
    strcpy(buffEspI,especialidad);
}

void cargaArrMedicos(int *&med_Codigo,char **&med_Nombre,
                     char **&med_Especialidad,double *&med_Tarifa,int *buffCod,
                     char **buffNomb,char **buffEsp,double *buffTar,int n){
    med_Codigo = new int[n+1];
    med_Nombre = new char*[n];
    med_Especialidad = new char*[n];
    med_Tarifa = new double[n];
    
    for(int i=0;i<n;i++){
        med_Codigo[i] = buffCod[i];
        med_Nombre[i] = buffNomb[i];
        med_Especialidad[i] = buffEsp[i];
        med_Tarifa[i] = buffTar[i];
    }
    
    med_Codigo[n] = 0;
}
//Prueba de Lectura de Medicos
void pruebaDeLecturaDeMedicos(const char *nombArch,int *med_Codigo,
                  char **med_Nombre,char **med_Especialidad,double *med_Tarifa){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;med_Codigo[i]!=0;i++){
        archRep<<left<<setw(10)<<med_Codigo[i]<<setw(40)<<med_Nombre[i]
               <<setw(20)<<med_Especialidad[i]<<right<<setw(8)<<med_Tarifa[i]
               <<endl;
    }
}
//Lectura de Citas
/*
71422479,Lozada/Felicita,802270,1/10/2022
51642949,Miranda/Alfonso,600493,9/02/2023
*/
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,
                    int **&pac_Citas){
    int buffDni[300]={},*buffCit[300],numCit[100]={},dni,codMed,fecha,dd,mm,aa;
    char *buffNomb[300],nombre[30],c;
    
    ifstream archCit(nombArch,ios::in);
    if(not archCit.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        archCit>>dni;
        if(archCit.eof()) break;
        archCit.get();
        archCit.getline(nombre,30,',');
        archCit>>codMed>>c>>dd>>c>>mm>>c>>aa;
        fecha = juntarFecha(dd,mm,aa);
        agregarMedAPac(buffDni,buffCit,buffNomb,dni,nombre,codMed,fecha,numCit,i);
    }
    cargaArrPacientes(pac_Dni,pac_Nombre,pac_Citas,buffDni,buffNomb,buffCit,
                      numCit,i);
}

int juntarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

void agregarMedAPac(int *buffDni,int **buffCit,char **buffNomb,int dni,
                    char *nombre,int codMed,int fecha,int *numCit,int &i){
    int j;
    bool nuevo = true;
    for(j=0;buffDni[j]!=0;j++)
        if(buffDni[j]==dni){
            nuevo = false;
            break;
        }
    if(nuevo){
        buffDni[i] = dni;
        buffNomb[i] = new char[strlen(nombre)+1];
        strcpy(buffNomb[i],nombre);
        buffCit[i] = new int[MAX_MED_PAC];
        buffDni[i+1] = 0;
        numCit[i] = 0;
        i++;
    }
    int *aux;
    aux = buffCit[j];
    aux[numCit[j]*2] = codMed;
    aux[numCit[j]*2+1] = fecha;
    numCit[j]++;
}

void cargaArrPacientes(int *&pac_Dni,char **&pac_Nombre,int **&pac_Citas,
                  int *buffDni,char **buffNomb,int **buffCit,int *numCit,int n){
    pac_Dni = new int[n+1];
    pac_Nombre = new char*[n];
    pac_Citas = new int*[n];
    
    for(int i=0;i<n;i++){
        pac_Dni[i] = buffDni[i];
        pac_Nombre[i] = buffNomb[i];
        pac_Citas[i] = new int[numCit[i]*2+1];
        agregarMedicosExactos(pac_Citas[i],buffCit[i],numCit[i]);
    }
    pac_Dni[n] = buffDni[n];  //pac_Dni[n] = 0;
}

void agregarMedicosExactos(int *&pacCitas,int *buffcitas,int cantCit){
    for(int i=0;i<cantCit*2;i+=2){
        pacCitas[i] = buffcitas[i];
        pacCitas[i+1] = buffcitas[i+1];
    }
    pacCitas[cantCit*2] = 0;
}
//Prueba de Lectura de Citas
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,char **pac_Nombre,
                            int **pac_Citas){
    int *auxCitas;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(int i=0;pac_Dni[i]!=0;i++){
        archRep<<left<<setw(10)<<pac_Dni[i]<<setw(60)<<pac_Nombre[i]<<endl;;
        archRep<<right<<setw(11)<<"MEDICO"<<setw(9)<<"FECHA"<<endl;
        auxCitas = pac_Citas[i];
        for(int j=0;auxCitas[j]!=0;j+=2){
            archRep<<right<<setfill('0')<<setw(2)<<j/2+1<<')'<<setfill(' ')
                   <<setw(8)<<auxCitas[j]<<setw(10)<<auxCitas[j+1]<<endl;
        }
    }
}
//Reporte de Ingresos Medicos y Gastos de los Pacientes
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
            double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas){
    double totIngresado = 0;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    imprimirEncabezadoMedicos(archRep);
    for(int i=0;med_Codigo[i]!=0;i++){
        archRep<<right<<setw(2)<<i+1<<')'<<setw(8)<<med_Codigo[i]<<setw(2)<<" "
               <<left<<setw(56)<<med_Nombre[i]<<setw(30)<<med_Especialidad[i]
               <<right<<setw(12)<<med_Tarifa[i];
        imprimirTotalDeIngresos(archRep,pac_Citas,pac_Dni,med_Codigo[i],
                                med_Tarifa[i],totIngresado);
    }
    imprimirLinea(archRep,'-');
    archRep<<left<<setw(30)<<"Total ingresado:"<<right<<setw(104)<<totIngresado
           <<endl;
    imprimirLinea(archRep,'=');
    imprimirEncabezadoPacientes(archRep);
    for(int i=0;pac_Dni[i]!=0;i++){
        archRep<<right<<setw(2)<<i+1<<')'<<setw(11)<<pac_Dni[i]<<setw(2)<<" "
               <<setw(30)<<pac_Nombre[i];
        imprimirTotalDeGastos(archRep,pac_Citas[i],med_Codigo,med_Tarifa);
    }
    imprimirLinea(archRep,'=');
}

void imprimirEncabezadoMedicos(ofstream &archRep){
    archRep<<setw(80)<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<"INGRESOS DE LOS MEDICOS POR LAS CITAS:"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<right<<"No."<<setw(9)<<"Codigo"<<setw(9)<<"Nombre"<<setw(60)
           <<"Especialidad"<<setw(30)<<"Tarifa"<<setw(28)<<"Total de ingresos"
           <<endl;
    imprimirLinea(archRep,'-');
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void imprimirTotalDeIngresos(ofstream &archRep,int **pac_Citas,int *pac_Dni,
                             int codMed,double tarifa,double &totIngresado){
    int *auxCitas,cantCitas = 0;
    for(int i=0;pac_Dni[i]!=0;i++){
        auxCitas = pac_Citas[i];
        for(int j=0;auxCitas[j]!=0;j+=2){
            if(auxCitas[j]==codMed) cantCitas++;
        }
    }
    archRep<<right<<setw(23)<<tarifa*cantCitas<<endl;
    totIngresado += tarifa*cantCitas;
}

void imprimirEncabezadoPacientes(ofstream &archRep){
    archRep<<"GASTOS DE LOS PACIENTES POR LAS CITAS"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<right<<"No."<<setw(5)<<"DNI"<<setw(15)<<"Nombre"<<setw(60)
           <<"Numero de citas"<<setw(30)<<"Total de gastos"<<endl;
    imprimirLinea(archRep,'-');
}

void imprimirTotalDeGastos(ofstream &archRep,int *arrCitas,int *arrCodMed,
                           double *arrTarifa){
    int cantCitas = 0;
    double gastoTotal = 0;
    for(int i=0;arrCitas[i]!=0;i+=2)
        for(int j=0;arrCodMed[j]!=0;j++)
            if(arrCitas[i]==arrCodMed[j]){
                cantCitas++;
                gastoTotal += arrTarifa[j];
            }
    archRep<<right<<setw(30)<<cantCitas<<setw(33)<<gastoTotal<<endl;
}