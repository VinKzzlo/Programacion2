/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.cpp
 * Author: cueva.r
 * 
 * Created on 10 de septiembre de 2024, 10:23 AM
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "AperturaDeArchivos.h"
#define INC 5

using namespace std;

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,
    double *escalas,const char*nomcur,const char*nomesc){
    ifstream archcur,archesc;
    
    AperturaDeUnArchivoDeTextosParaLeer(archcur,nomcur);
    AperturaDeUnArchivoDeTextosParaLeer(archesc,nomesc);
    
    
    leecursos(cursos,cursos_cred,archcur);
    
}

void leecursos(char ***&cursos,double *&cursos_cred,ifstream &arch){
    char **registro;
    double creditos;
    int capacidad=0,numdat=0;
    cursos=nullptr;
    while(1){
        registro = leecurso(arch,creditos);
        if(arch.eof())break;
        if(capacidad==numdat)
            aumentarmemoria(cursos,cursos_cred,numdat,capacidad);
        cursos[numdat-1]=registro;
        cursos[numdat]=nullptr;
        cursos_cred[numdat-1] = creditos; 
        numdat++;
    }
}

void aumentarmemoria(char ***&cursos,double *&cursos_cred,
        int &numdat,int &capacidad){
    char ***auxcur;
    double *auxcred;
    capacidad+=INC;
    
    if(cursos==nullptr){
        cursos = new char**[capacidad];
        cursos_cred = new double[capacidad];
        cursos[0] = nullptr;
        numdat = 1;
    }
    else{
        auxcur = new char**[capacidad];
        auxcred = new double[capacidad];
        for(int i=0;i<numdat;i++){
            auxcur[i] = cursos[i];
            auxcred[i] = cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        
        cursos = auxcur;
        cursos_cred = auxcred;
    }
}
/*
INF263,Algoritmia,3.75,35030611,INGA FLORES CESAR ADOLFO
MEC270,Procesos De Manufactura,4,83265244,PAIRAZAMAN ALAMO MOISES MIGUEL
*/
char **leecurso(ifstream &arch,double &creditos){
    char *codigo,*nomcur,*nomprof,**curso,c;
    int codprof;
    
    codigo = leercadena(arch,10,',');
    if(arch.eof()) return nullptr;
    nomcur = leercadena(arch,100,',');
    arch >> creditos >> c >> codprof >> c;
    nomprof = leercadena(arch,100,'\n');
    curso = new char*[3];
    curso[0] = codigo;
    curso[1] = nomcur;
    curso[2] = nomprof;       
    return curso;
}


char *leercadena(ifstream &arch,int max,char deli){
    char buff[max],*cad;
    arch.getline(buff,max,deli);
    if(arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void cargarAlumnos(int* &alumnos_cod,int**&alumnos,
        char ***&alumnos_nom_mod,const char*nom){
    int codigo,*regent,capacidad=0,numdat=0;
    char **regcad;
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nom);
    alumnos_cod=nullptr;
    while(1){
        codigo=leealumno(arch,regent,regcad);
        if(arch.eof()) break;
        if(numdat==capacidad)
            aumentarespacio(alumnos_cod,alumnos,alumnos_nom_mod,
                    numdat,capacidad);
        alumnos_cod[numdat-1]=codigo;
        alumnos[numdat-1]=regent;
        alumnos_nom_mod[numdat-1]=regcad;
        alumnos_cod[numdat]=0;
        numdat++;
    }
}

void aumentarespacio(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,
                    int &numdat,int &capacidad){

    capacidad+=INC;
    int *auxcod,**auxalumnos;
    char ***auxnom;
    if(alumnos_cod==nullptr){
        alumnos_cod = new int[capacidad];
        alumnos = new int*[capacidad];
        alumnos_nom_mod =  new char**[capacidad];       
        alumnos_cod[0] = 0;
        numdat=1;
    }
    else{
        auxcod = new int[capacidad];
        auxalumnos = new int*[capacidad];
        auxnom = new char**[capacidad]; 
        for(int i=0;i<numdat;i++){
            auxcod[i]=alumnos_cod[i];
            auxalumnos[i]=alumnos[i];
            auxnom[i]=alumnos_nom_mod[i];
        }
        delete alumnos_cod;
        delete alumnos;
        delete alumnos_nom_mod;
        
        alumnos_cod = auxcod;
        alumnos = auxalumnos;
        alumnos_nom_mod = auxnom;
    }    
}


/*
202123703,GAMARRA TABORI PAUL RONAL,S,30,G5
202119153,MENDOZA ARIAS HENRY,G4
202214712,CASANOVA CHUMPITAZ ALONSO,V,G2
 */
int leealumno(ifstream &arch,int *&regent,char**&regcad){
    int cod,porc,escala;
    char *cadnom,mod,c;
    arch >> cod;
    if(arch.eof()) return 0;
    arch.get();
    cadnom=leercadena(arch,100,',');
    arch >> mod;
    if(mod=='S') arch >> c >> porc >> c >>c;
    if(mod=='V') arch >> c >> c;
    if(mod=='G') mod='P';
    arch >> escala;
    
    if(mod=='S'){
        regent=new int[3];
        regent[0]=cod;
        regent[1]=escala;
        regent[2]= porc;
    }else{
        regent=new int[2];
        regent[0]=cod;
        regent[1]=escala;
    }
    regcad = new char*[2];
    regcad[0]=cadnom;
    regcad[1]=new char{mod};
    return cod;
}
