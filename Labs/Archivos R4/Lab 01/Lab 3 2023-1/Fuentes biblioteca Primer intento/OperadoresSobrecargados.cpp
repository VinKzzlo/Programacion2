/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 25 de marzo de 2024, 23:07
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
//Lectura
/*
INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO
MEC270   Procesos_De_Manufactura   4   83265244   PAIRAZAMAN_ALAMO_MOISES_MIGUEL 
*/
bool operator >>(ifstream &archCur,StCurso &cur){
    //archCur>>cur;
    archCur>>cur.codigoDelCurso;
    if(archCur.eof()) return false;
    archCur>>cur.nombreDelCurso>>cur.creditos>>cur.codigoDelCurso
            >>cur.nombreDelProfesor;
    cur.numeroDeAlumnos = 0;
    cur.ingresos = 0.0;
    return true;
}
/*
20211,1260   GORDILLO/CASTRO/RONAL          G2
20211,1397   ZEVALLOS/PRADO/RICARDO   S   50   G2
20212,7344   DEL_POZO/QUIO/CESAR   V      G3
*/
bool operator >>(ifstream &archAlum,StAlumno &alum){
    //archAlum>>alum;
    char c;
    archAlum>>alum.semestre;
    if(archAlum.eof()) return false;
    archAlum>>c>>alum.codigo>>alum.nombre>>c;
    switch (c){
        case 'G':
            archAlum>>alum.escala;
            strcpy(alum.modalidad,"Presencial");
            break;
        case 'S':
            archAlum>>alum.porcentaje>>c>>alum.escala;
            strcpy(alum.modalidad,"Semipresencial");
            break;
        case 'V':
            archAlum>>c>>alum.escala;
            strcpy(alum.modalidad,"Virtual");
            break;
    }
    alum.numeroDeCursos = 0;
    alum.costoTotal = 0.0;
    return true;
}
/*
INF263   20231,8320
*/
bool operator >>(ifstream archMat,StRegistroDeMatricula &matri){
    //archMat>>matri;
    char c;
    archMat>>matri.codigoDelCurso;
    if(archMat.eof()) return false;
    archMat>>matri.semestreDelAlumno>>c>>matri.codigodelAlumno;
    return true;
}
//Agregacion
void operator +=(StCurso *arrCur,const struct StCurso &cur){
    //arrCur += cur;
    int i;
    //Copiando los datos de la estructura al arreglo de estructuras
    //hasta copiarlo cuando encuentren el XXXXXX
    for(i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++);
    //Cambiamos el dato al siguiente elemento después del antiguo último
    //elemento, teniendo un nuevo último elemento (XXXXXX)
    arrCur[i] = cur;
    strcpy(arrCur[i+1].codigoDelCurso,"XXXXXX");
}
void operator +=(StAlumno *arrAlum,const struct StAlumno &alum){
    //arrAlum += alum;
    int i;
    for(i=0;arrAlum[i].semestre!=0;i++);
    arrAlum[i] = alum;
    //Cambiando el último dato
    arrAlum[i+1].semestre = 0;
}
void operator *=(StCurso *arrCur,const struct StRegistroDeMatricula &matri){
    //arrCur *= matri;
    int nuevo=1,numAlum;
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        if(strcmp(arrCur[i].codigoDelCurso,matri.codigoDelCurso)==0){
            //Hay que buscar al alumno en el arreglo primero para no repetir
            for(int j=0;j<arrCur[i].numeroDeAlumnos;j++)
                if(arrCur[i].alumnos[j]%10000==matri.codigodelAlumno &&
                   arrCur[i].alumnos[j]/10000==matri.semestreDelAlumno){
                    nuevo = 0;
                    break;
                }
            //Si es que ninguno coincide, se le agrega al arreglo
            if(nuevo){
                numAlum = arrCur[i].numeroDeAlumnos;
                arrCur[i].alumnos[numAlum] = matri.semestreDelAlumno*10000+
                                             matri.codigodelAlumno;
                arrCur[i].numeroDeAlumnos++;
            }
            break;
        }
}
void operator *=(StAlumno *arrAlum,const struct StRegistroDeMatricula &matri){
    //arrAlum *= matri;
    int nuevo=1,numCur;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        if(arrAlum[i].codigo == matri.codigodelAlumno &&
           arrAlum[i].semestre == matri.semestreDelAlumno){
            for(int j=0;j<arrAlum[i].numeroDeCursos;j++)
                if(strcmp(arrAlum[i].cursos[j],matri.codigoDelCurso)==0){
                    nuevo = 0;
                    break;
                }
            if(nuevo){
                numCur = arrAlum[i].numeroDeCursos;
                arrAlum[i].cursos[numCur] = 
                                       new char[strlen(matri.codigoDelCurso)+1];
                strcpy(arrAlum[i].cursos[numCur],matri.codigoDelCurso);
                arrAlum[i].numeroDeCursos++;
            }
            break;
        }
}
//Impresion
void operator <<(ofstream &archRepCur,const struct StCurso &cur){
    //archRepCur<<cur;
    archRepCur<<right<<setw(10)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(40)
            <<"CREDITOS"<<endl;
    archRepCur<<right<<setw(10)<<cur.codigoDelCurso<<setw(25)
            <<cur.nombreDelCurso<<setw(33)<<cur.creditos<<endl;
    archRepCur<<right<<setw(14)<<"PROFESOR: "<<cur.nombreDelProfesor<<" ["
            <<cur.codigoDelProfesor<<"]"<<endl;
    archRepCur<<setw(20)<<"Alumnos matriculados:"<<endl;
    archRepCur<<setw(12)<<"Semestre"<<setw(10)<<"Codigo"<<endl;
    for(int i=0;i<cur.numeroDeAlumnos;i++){
        archRepCur<<right<<setw(11)<<cur.alumnos[i]/10000<<setw(10)
                <<cur.alumnos[i]%10000<<endl;
    }
    archRepCur<<setw(4)<<' '<<"Numero de alumnos: "<<cur.numeroDeAlumnos<<endl;
    archRepCur<<setw(4)<<' '<<"Total ingresado: "<<cur.ingresos<<endl;
}
void operator <<(ofstream &archRepAlum,const struct StAlumno &alum){
    //archRepAlum<<alum;
    archRepAlum<<left<<setw(4)<<' '<<setw(10)<<"SEMESTRE"<<setw(10)<<"CODIGO"
            <<setw(30)<<"NOMBRE"<<setw(30)<<"MODALIDAD"<<"ESCALA"<<endl;
    archRepAlum<<setw(4)<<' '<<left<<setw(11)<<alum.semestre<<setw(9)
            <<alum.codigo<<left<<setw(30)<<alum.nombre<<" "<<alum.modalidad;
    if(strcmp(alum.modalidad,"Semipresencial")==0){
        archRepAlum<<" CON "<<alum.porcentaje<<'%'<<setw(10)<<' ';
    }else archRepAlum<<setw(30-strlen(alum.modalidad))<<' ';
    archRepAlum<<'G'<<alum.escala<<endl;
    archRepAlum<<setw(4)<<' '<<"Codigos de cursos matriculados:"<<endl;
    for(int i=0;i<alum.numeroDeCursos;i++){
        archRepAlum<<setw(4)<<' '<<setw(12)<<alum.cursos[i]<<endl;
    }
    archRepAlum<<setw(4)<<' '<<"Numero de Cursos: "<<alum.numeroDeCursos<<endl;
    archRepAlum<<setw(4)<<' '<<"Costo Total: "<<alum.costoTotal<<endl;
}