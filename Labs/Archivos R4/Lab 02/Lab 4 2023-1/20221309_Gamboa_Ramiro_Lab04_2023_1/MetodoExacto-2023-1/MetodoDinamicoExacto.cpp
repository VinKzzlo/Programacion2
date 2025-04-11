/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 7 de abril de 2024, 13:48
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoExacto.h"
#define MAX_ALUM_CUR 200
#define MAX_LINEA 140
#define NO_ENCONTRADO -1
//Lectura de Alumnos
/*
5802,MINAYA AMEZQUITA RHONY JAIME,5
2050,LOYOLA HIJAR NICOLAS OSCAR,V,4
7660,CHANG ARGUEDAS HENRY ANTONIO,S,25,4
*/
void lecturaAlumnos(const char *nombArch,int *&alumno_Codigo,
                    char **&alumno_Nombre,char *&alumno_Modalidad,
                    int *&alumno_Porcentaje,int *&alumno_Escala){
    int buffCod[100],buffPorc[100],buffEsc[100],codigo;
    char *buffNomb[100],buffMod[100];
    
    ifstream archAlum(nombArch,ios::in);
    if(not archAlum.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int i=0;
    while(1){
        archAlum>>codigo;
        if(archAlum.eof()) break;
        buffCod[i] = codigo;
        archAlum.get();
        buffNomb[i] = leeCadena(archAlum,40,',');
        modificaModalidad(archAlum,buffMod[i],buffPorc[i],buffEsc[i]);
        i++;
    }
    cargarArrAlumnos(alumno_Codigo,alumno_Nombre,alumno_Modalidad,
                     alumno_Porcentaje,alumno_Escala,buffCod,buffNomb,buffMod,
                     buffPorc,buffEsc,i);
}
//Lectura de cadena al primer nivel del puntero
char *leeCadena(ifstream &archAlum,int max,char delim){
    char buffer[500],*cad;
    archAlum.getline(buffer,max,delim);
    if(archAlum.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void modificaModalidad(ifstream &archAlum,char &modalidad,int &porcentaje,
                       int &escala){
    char c;
    archAlum>>escala;
    porcentaje = 0;
    modalidad = 'P';
    if(archAlum.fail()){
        archAlum.clear();
        archAlum>>modalidad>>c;
        if(modalidad=='V'){
            archAlum>>escala;
            porcentaje = 0;
        }else
            archAlum>>porcentaje>>c>>escala;
    }
}

void cargarArrAlumnos(int *&alumno_Codigo,char **&alumno_Nombre,
                      char *&alumno_Modalidad,int *&alumno_Porcentaje,
                      int *&alumno_Escala,int *buffCod,char **buffNomb,
                      char *buffMod,int *buffPorc,int *buffEsc,int n){
    alumno_Codigo = new int[n+1];
    alumno_Nombre = new char*[n];
    alumno_Modalidad = new char[n];
    alumno_Porcentaje = new int[n];
    alumno_Escala = new int[n];
    
    for(int i=0;i<n;i++){
        alumno_Codigo[i] = buffCod[i];
        alumno_Nombre[i] = buffNomb[i];
        alumno_Modalidad[i] = buffMod[i];
        alumno_Porcentaje[i] = buffPorc[i];
        alumno_Escala[i] = buffEsc[i];
    }
    alumno_Codigo[n] = 0;
}
//Prueba de Lectura de Alumnos
void pruebaLecturaAlumnos(const char *nombArch,int *alumno_Codigo,
                          char **alumno_Nombre,char *alumno_Modalidad,
                          int *alumno_Porcentaje,int *alumno_Escala){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;alumno_Codigo[i]!=0;i++){
        archRep<<alumno_Codigo[i]<<" "<<left<<setw(40)<<alumno_Nombre[i]<<" "
               <<alumno_Modalidad[i]<<right<<setw(4)<<alumno_Porcentaje[i]
               <<setw(3)<<alumno_Escala[i]<<endl;
    }
}
//Lectura de Cursos
/*
8072,Aplicaciones de las Ciencias de la Computacion,3.5
6995,Lenguaje de Programacion 1,5
*/
void lecturaCursos(const char *nombArch,int *alumno_Codigo,int *alumno_Escala,
              char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos){
    int *buffCurAlum[110],numAlum[110]={},codAlum;
    char *buffCurNomb[110],nombCur[50];
    double buffCurCred[110],creditos;
    
    ifstream archCur(nombArch,ios::in);
    if(not archCur.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int i=0;
    while(1){
        archCur>>codAlum;
        if(archCur.eof()) break;
        archCur.get();
        archCur.getline(nombCur,50,',');
        archCur>>creditos;
        agregarAlumnoACurso(buffCurAlum,buffCurNomb,buffCurCred,alumno_Codigo,
                            alumno_Escala,codAlum,nombCur,creditos,numAlum,i);
    }
    cargaArrCursos(curso_Nombre,curso_Credito,curso_Alumnos,buffCurAlum,
                   buffCurNomb,buffCurCred,numAlum,i);
}

void agregarAlumnoACurso(int **buffCurAlum,char **buffCurNomb,double *buffCurCred,
                         int *alumno_Codigo,int *alumno_Escala,int codAlum,
                         char *nombCur,double creditos,int *numAlum,int &i){
    int j;
    bool nuevo = true;
    for(j=0;buffCurNomb[j]!=nullptr;j++){
        if(strcmp(buffCurNomb[j],nombCur)==0){
            nuevo = false;
            break;
        }
    }
    if(nuevo){
        buffCurNomb[i] = new char[strlen(nombCur)+1];
        strcpy(buffCurNomb[i],nombCur);
        buffCurCred[i] = creditos;
        buffCurAlum[i] = new int[MAX_ALUM_CUR];
        numAlum[i] = 0;
        buffCurNomb[i+1] = nullptr;
        i++;
    }
    int posAlum;
    for(posAlum=0;alumno_Codigo[posAlum]!=codAlum;posAlum++);
    int *aux;
    aux = buffCurAlum[j];
    aux[numAlum[j]*2] = alumno_Codigo[posAlum];
    aux[numAlum[j]*2+1] = alumno_Escala[posAlum];
    numAlum[j]++;
}

void cargaArrCursos(char **&curso_Nombre,double *&curso_Credito,
                    int **&curso_Alumnos,int **buffCurAlum,char **buffCurNomb,
                    double *buffCurCred,int *numAlum,int n){
    curso_Nombre = new char*[n+1];
    curso_Credito = new double[n];
    curso_Alumnos = new int*[n];
    
    for(int i=0;i<n;i++){
        curso_Nombre[i] = buffCurNomb[i];
        curso_Credito[i] = buffCurCred[i];
        curso_Alumnos[i] = new int[numAlum[i]*2+1];
        cargaAlumnosExacto(curso_Alumnos[i],buffCurAlum[i],numAlum[i]);
    }
    curso_Nombre[n] = nullptr;
}

void cargaAlumnosExacto(int *&curAlum,int *buffcuralum,int cantAlum){
    int i=0;
    while(i<cantAlum*2){
        curAlum[i] = buffcuralum[i];
        curAlum[i+1] = buffcuralum[i+1];
        i += 2;
    }
    curAlum[cantAlum*2] = 0;
}
//Prueba de Lectura de Cursos
void pruebaDeLecturaCursos(const char *nombArch,char **curso_Nombre,
                           double *curso_Credito,int **curso_Alumnos){
    int *auxCurAlum;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    for(int i=0;curso_Nombre[i]!=nullptr;i++){
        archRep<<right<<setw(27)<<"NOMBRE"<<setw(29)<<"CREDITOS"<<endl;
        archRep<<left<<setw(50)<<curso_Nombre[i]<<curso_Credito[i]<<endl;
        archRep<<right<<setw(9)<<"ALUMNOS"<<setw(9)<<"ESCALA"<<endl;
        auxCurAlum = curso_Alumnos[i];
        for(int j=0;auxCurAlum[j]!=0;j+=2){
            archRep<<right<<setw(8)<<auxCurAlum[j]<<setw(8)
                   <<auxCurAlum[j+1]<<endl;
        }
    }
}
//Reporte de Recaudacion por Modalidad
void reporteDeRecaudacionPorModalidad(const char *nombArch,int *alumno_Codigo,
            char *alumno_Modalidad,int *alumno_Porcentaje,char **alumno_Nombre,
            char **curso_Nombre,double *curso_Credito,int **curso_Alumnos){
    int *auxCurAlum,posAlum;
    double recauPre,recauSem,recauVir,recauTOTPre=0,recauTOTSem=0,recauTOTVir=0;
    double arrCostoXCred[5];
    leerEscalas("escalas.csv",arrCostoXCred);
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    archRep<<right<<setw(70)<<"ENTIDAD EDUCATIVA LP1"<<endl;
    archRep<<setw(68)<<"LISTADOS DE CLASE"<<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;curso_Nombre[i]!=nullptr;i++){
        archRep<<right;
        recauPre=0,recauSem=0,recauVir=0;
        archRep<<setfill('0')<<setw(2)<<i+1<<')'<<setfill(' ')<<setw(15)
               <<"Curso:"<<setw(50)<<curso_Nombre[i]<<setw(15)<<"Creditos:"
               <<setw(5)<<curso_Credito[i]<<endl;
        imprimirEncabezadoCursos(archRep);
        auxCurAlum = curso_Alumnos[i];
        for(int j=0;auxCurAlum[j]!=0;j+=2){
            posAlum = buscarPosicionAlumno(alumno_Codigo,auxCurAlum[j]);
            archRep<<right<<setfill('0')<<setw(2)<<j/2+1<<')'<<setfill(' ')
                   <<setw(6)<<alumno_Codigo[posAlum]<<setw(3)<<" "<<left
                   <<setw(60)<<alumno_Nombre[posAlum]<<setw(3)<<auxCurAlum[j+1];
            imprimirPagos(archRep,alumno_Modalidad[posAlum],curso_Credito[i],
                          alumno_Porcentaje[posAlum],auxCurAlum[j+1],
                          recauPre,recauSem,recauVir,arrCostoXCred);
        }
        imprimirLinea(archRep,'=');
        archRep<<left<<setw(40)<<"RECAUDACION POR MODALIDAD DE ESTUDIO"
               <<setw(55)<<right<<recauPre<<setw(20)<<recauSem<<setw(20)
               <<recauVir<<endl;
        imprimirLinea(archRep,'-');
        archRep<<left<<setw(40)<<"TOTAL RECAUDADO:"<<right<<setw(95)
               <<recauPre+recauSem+recauVir<<endl;
        imprimirLinea(archRep,'=');
        recauTOTPre += recauPre;
        recauTOTSem += recauSem;
        recauTOTVir += recauVir;
    }
    archRep<<left<<setw(45)<<"RECAUDACION TOTAL POR MODALIDAD DE ESTUDIO"
           <<right<<setw(50)<<recauTOTPre<<setw(20)<<recauTOTSem<<setw(20)
           <<recauTOTVir<<endl;
    imprimirLinea(archRep,'-');
    archRep<<left<<setw(45)<<"TOTAL GENERAL RECAUDADO:"<<right<<setw(90)
           <<recauTOTPre+recauTOTSem+recauTOTVir<<endl;
    imprimirLinea(archRep,'=');
}

void leerEscalas(const char *nombArch,double *arrCostoXCred){
    int numEsc;
    double costo;
    char c;
    ifstream archEsc(nombArch,ios::in);
    if(not archEsc.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(1){
        archEsc>>c;
        if(archEsc.eof()) break;
        archEsc>>numEsc>>c>>costo;
        arrCostoXCred[numEsc-1] = costo;
        archEsc.get();
    }
}

void imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void imprimirEncabezadoCursos(ofstream &archRep){
    imprimirLinea(archRep,'-');
    archRep<<"ALUMNOS Matriculados"<<endl;
    imprimirLinea(archRep,'-');
    archRep<<right<<setw(100)<<"PAGOS"<<endl;
    archRep<<right<<setw(9)<<"CODIGO"<<setw(10)<<"NOMBRE"<<setw(57)<<"ESCALA"
           <<setw(20)<<"PRESENCIAL"<<setw(23)<<"SEMI PRESENCIAL"<<setw(16)
           <<"VIRTUAL"<<endl;
    imprimirLinea(archRep,'-');
}

int buscarPosicionAlumno(int *alumno_Codigo,int codAlum){
    for(int i=0;alumno_Codigo[i]!=0;i++)
        if(alumno_Codigo[i]==codAlum) return i;
    return NO_ENCONTRADO;
}
/*
G5,666.90
*/
void imprimirPagos(ofstream &archRep,char modalidad,double creditos,
                   int porcentaje,int escala,double &recauPre,double &recauSem,
                   double &recauVir,double *arrCostoXCred){
    archRep<<right;
    if(modalidad=='P'){
        archRep<<setw(20)<<arrCostoXCred[escala-1]*creditos<<endl;
        recauPre += arrCostoXCred[escala-1]*creditos;
    }else if(modalidad=='S'){
        archRep<<setw(40)<<arrCostoXCred[escala-1]*creditos*
                           double(porcentaje)/100<<endl;
        recauSem += arrCostoXCred[escala-1]*creditos*double(porcentaje)/100;
    }else{
        archRep<<setw(60)<<arrCostoXCred[escala-1]*creditos<<endl;
        recauVir += arrCostoXCred[escala-1]*creditos;
    }
}