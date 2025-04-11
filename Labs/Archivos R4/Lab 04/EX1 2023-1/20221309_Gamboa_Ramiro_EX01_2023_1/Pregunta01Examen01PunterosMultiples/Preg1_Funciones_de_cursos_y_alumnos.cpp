/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.cpp
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 21 de abril de 2024, 09:13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#define INCREMENTO 5
//Cargar cursos y escalas
void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
                          const char *nombArchCur,const char *nombArchEsc){
    ifstream archCur,archEsc;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCur,nombArchCur);
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,nombArchEsc);
    
    leerCursos(archCur,cursos,cursos_cred);
    leerEscalas(archEsc,escalas);
}
/*
INF263,Algoritmia,3.75,35030611,INGA FLORES CESAR ADOLFO
MEC270,Procesos De Manufactura,4,83265244,PAIRAZAMAN ALAMO MOISES MIGUEL
*/
void leerCursos(ifstream &archCur,char ***&cursos,double *&cursos_cred){
    int numDatos = 0,capacidad = 0;
    char **registroCur;
    double creditos;
    cursos = nullptr;
    while(1){
        registroCur = leerRegistroCur(archCur,creditos);
        if(archCur.eof()) break;
        if(numDatos==capacidad)
            aumentarCapCursos(cursos,cursos_cred,numDatos,capacidad);
        agregarCursos(cursos,cursos_cred,registroCur,creditos,numDatos);
    }
}

char **leerRegistroCur(ifstream &archCur,double &creditos){
    int codProf;
    char **registro,*codigo,c;
    
    codigo = LeeCadenaExacta(archCur,7,',');
    if(archCur.eof()) return nullptr;
    registro = new char*[3];
    registro[0] = codigo;
    registro[1] = LeeCadenaExacta(archCur,60,',');
    archCur>>creditos>>c>>codProf>>c;
    registro[2] = LeeCadenaExacta(archCur,40,'\n');
    return registro;
}

char *LeeCadenaExacta(ifstream &arch,int max,char delim){
    char buff[max],*cad;
    arch.getline(buff,max,delim);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void aumentarCapCursos(char ***&cursos,double *&cursos_cred,int &numDatos,
                       int &capacidad){
    char ***auxCur;
    double *auxCurCred;
    capacidad += INCREMENTO;
    if(cursos==nullptr){
        cursos = new char**[capacidad];
        cursos_cred = new double[capacidad];
        cursos[0] = nullptr;
        cursos_cred[0] = -1;
        numDatos++;
    }else{
        auxCur = new char**[capacidad];
        auxCurCred = new double[capacidad];
        for(int i=0;i<numDatos;i++){
            auxCur[i] = cursos[i];
            auxCurCred[i] = cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos = auxCur;
        cursos_cred = auxCurCred;
    }
}

void agregarCursos(char ***cursos,double *cursos_cred,char **registroCur,
                   double creditos,int &numDatos){
    cursos[numDatos-1] = registroCur;
    cursos[numDatos] = nullptr;
    cursos_cred[numDatos-1] = creditos;
    cursos_cred[numDatos] = -1;
    numDatos++;
}
/*
G5,666.90
G1,282.30
*/
void leerEscalas(ifstream &archEsc,double *escalas){
    int escala;
    char c;
    double costoXCred;
    while(1){
        archEsc>>c;
        if(archEsc.eof()) break;
        archEsc>>escala>>c>>costoXCred;
        escalas[escala-1] = costoXCred;
    }
}
//Prueba de carga de cursos
void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,
                           const char *nombArch){
    char **auxCur;
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<fixed<<setprecision(2);
    for(int i=0;cursos[i]!=nullptr;i++){
        auxCur = cursos[i];
        archRep<<left<<setw(10)<<auxCur[0]<<setw(60)<<auxCur[1]<<setw(40)
               <<auxCur[2]<<right<<setw(8)<<cursos_cred[i]<<endl;
    }
}
//Cargar alumnos
/*
202123703,GAMARRA TABORI PAUL RONAL,S,30,G5
202119153,MENDOZA ARIAS HENRY,G4
202318072,RIVERA MONTERO GLORIA OFELIA,V,G3
*/
void cargaAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,
                  const char *nombArch){
    int numDatos = 0,capacidad = 0,codigo,*registroAlumCod;
    char *nombre,**registroAlumNomb;
    ifstream archAlum;
    
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,nombArch);
    
    alumnos_cod = nullptr;
    while(1){
        archAlum>>codigo;
        if(archAlum.eof()) break;
        if(numDatos==capacidad)
            aumentarCapAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,numDatos,
                               capacidad);
        archAlum.get();
        modificarRegistro(archAlum,registroAlumCod,registroAlumNomb,codigo);
        agregarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,codigo,
                       registroAlumCod,registroAlumNomb,numDatos);
    }
}

void aumentarCapAlumnos(int *&alumnos_cod,int **&alumnos,
                        char ***&alumnos_nom_mod,int &numDatos,int &capacidad){
    capacidad += INCREMENTO;
    if(alumnos_cod==nullptr){
        alumnos_cod = new int[capacidad];
        alumnos = new int*[capacidad];
        alumnos_nom_mod = new char**[capacidad];
        alumnos_cod[0] = 0;
        alumnos[0] = nullptr;
        alumnos_nom_mod[0] = nullptr;
        numDatos++;
    }else
        cambiarAuxAPuntero(alumnos_cod,alumnos,alumnos_nom_mod,numDatos,
                           capacidad);
}

void cambiarAuxAPuntero(int *&alumnos_cod,int **&alumnos,
                        char ***&alumnos_nom_mod,int numDatos,int capacidad){
    int *auxAlumCod,**auxAlum;
    char ***auxAlumNomMod;
    auxAlumCod = new int[capacidad];
    auxAlum = new int*[capacidad];
    auxAlumNomMod = new char**[capacidad];
    for(int i=0;i<numDatos;i++){
        auxAlumCod[i] = alumnos_cod[i];
        auxAlum[i] = alumnos[i];
        auxAlumNomMod[i] = alumnos_nom_mod[i];
    }
    delete alumnos_cod;
    delete alumnos;
    delete alumnos_nom_mod;
    alumnos_cod = auxAlumCod;
    alumnos = auxAlum;
    alumnos_nom_mod = auxAlumNomMod;
}

void modificarRegistro(ifstream &archAlum,int *&registroAlumCod,
                       char **&registroAlumNomb,int codigo){
    char c;
    registroAlumNomb = new char*[2];
    registroAlumNomb[0] = LeeCadenaExacta(archAlum,60,',');
    registroAlumNomb[1] = new char[2];
    archAlum>>c;
    switch(c){
        case 'G':
            *registroAlumNomb[1] = 'P';
            registroAlumCod = new int[2];
            archAlum>>registroAlumCod[1];
            break;
        case 'V':
            *registroAlumNomb[1] = 'V';
            registroAlumCod = new int[2];
            archAlum>>c>>c>>registroAlumCod[1];
            break;
        case 'S':
            *registroAlumNomb[1] = 'S';
            registroAlumCod = new int[3];
            archAlum>>c>>registroAlumCod[2]>>c>>c>>registroAlumCod[1];
    }
    registroAlumCod[0] = codigo;
}

void agregarAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,
                    int codigo,int *registroAlumCod,char **registroAlumNomb,
                    int &numDatos){
    alumnos_cod[numDatos-1] = codigo;
    alumnos_cod[numDatos] = 0;
    alumnos[numDatos-1] = registroAlumCod;
    alumnos[numDatos] = nullptr;
    alumnos_nom_mod[numDatos-1] = registroAlumNomb;
    alumnos_nom_mod[numDatos] = nullptr;
    numDatos++;
}
//Prueba de carga de alumnos
void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,
                            char ***alumnos_nom_mod,const char *nombArch){
    int *auxAlum;
    char **auxAlumNom;
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    for(int i=0;alumnos_cod[i]!=0;i++){
        auxAlum = alumnos[i];
        auxAlumNom = alumnos_nom_mod[i];
        archRep<<left<<setw(10)<<auxAlum[0]<<setw(40)<<auxAlumNom[0]<<right
               <<setw(5)<<auxAlum[1]<<setw(5)<<*auxAlumNom[1];
        if(*auxAlumNom[1]=='S'){
            archRep<<setw(6)<<auxAlum[2]<<endl;
        }else archRep<<endl;
    }
}