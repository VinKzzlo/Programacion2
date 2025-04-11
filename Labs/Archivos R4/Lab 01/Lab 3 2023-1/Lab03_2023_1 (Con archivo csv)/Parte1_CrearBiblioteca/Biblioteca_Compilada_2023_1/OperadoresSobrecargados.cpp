/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 4 de abril de 2024, 08:53
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
INF263,Algoritmia,3.75,35030611,INGA FLORES CESAR ADOLFO
MEC270,Procesos De Manufactura,4,83265244,PAIRAZAMAN ALAMO MOISES MIGUEL
*/
bool operator >>(ifstream &archCur,struct StCurso &cur){
    //archCur>>cur;
    char c;
    archCur.getline(cur.codigoDelCurso,7,',');
    if(archCur.eof()) return false;
    archCur.getline(cur.nombreDelCurso,60,',');
    archCur>>cur.creditos>>c>>cur.codigoDelProfesor>>c;
    archCur.getline(cur.nombreDelProfesor,60,'\n');
    cur.numeroDeAlumnos = 0;
    cur.ingresos = 0.0;
    return true;
}
/*
20211,1260,GORDILLO/CASTRO/RONAL,G2
20211,1397,ZEVALLOS/PRADO/RICARDO,S,50,G2
20212,7344,DEL_POZO/QUIO/CESAR,V,G3
*/
bool operator >>(ifstream &archAlum,struct StAlumno &alum){
    //archAlum>>alum;
    char modalidad,c;
    archAlum>>alum.semestre;
    if(archAlum.eof()) return false;
    archAlum.get();
    archAlum>>alum.codigo>>c;
    archAlum.getline(alum.nombre,60,',');
    modalidad = archAlum.get();
    switch(modalidad){
        case 'G':
            archAlum>>alum.escala;
            strcpy(alum.modalidad,"PRESENCIAL");
            break;
        case 'S':
            archAlum>>c>>alum.porcentaje>>c>>c>>alum.escala;
            strcpy(alum.modalidad,"SEMIPRESENCIAL");
            break;
        case 'V':
            archAlum>>c>>c>>alum.escala;
            strcpy(alum.modalidad,"VIRTUAL");
            break;
    }
    alum.numeroDeCursos = 0;
    alum.costoTotal = 0.0;
    return true;
}
/*
INF263,20231,8320
MEC289,20231,2000
*/
bool operator >>(ifstream &archMat,struct StRegistroDeMatricula &matri){
    //archMat>>matri;
    char c;
    archMat.getline(matri.codigoDelCurso,7,',');
    if(archMat.eof()) return false;
    archMat>>matri.semestreDelAlumno>>c>>matri.codigodelAlumno;
    archMat.get();
    return true;
}
//Agregacion
void operator +=(struct StCurso *arrCur,const struct StCurso &cur){
    //arrCur += cur;
    int i;
    for(i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++);
    arrCur[i] = cur;
    strcpy(arrCur[i+1].codigoDelCurso,"XXXXXX");
}

void operator +=(struct StAlumno *arrAlum,const struct StAlumno &alum){
    //arrAlum += alum;
    int i;
    for(i=0;arrAlum[i].semestre!=0;i++);
    arrAlum[i] = alum;
    arrAlum[i+1].semestre = 0;
}

void operator *=(struct StCurso *arrCur,
                 const struct StRegistroDeMatricula matri){
    //arrCur *= matri;
    int numAlum;
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        if(strcmp(arrCur[i].codigoDelCurso,matri.codigoDelCurso)==0){
            numAlum = arrCur[i].numeroDeAlumnos;
            arrCur[i].alumnos[numAlum] = matri.semestreDelAlumno*10000 +
                                         matri.codigodelAlumno;
            arrCur[i].numeroDeAlumnos++;
        }
}

void operator *=(struct StAlumno *arrAlum,
                 const struct StRegistroDeMatricula matri){
    //arrAlum *= matri;
    int numCur;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        if(arrAlum[i].semestre==matri.semestreDelAlumno &&
           arrAlum[i].codigo==matri.codigodelAlumno){
            numCur = arrAlum[i].numeroDeCursos;
            //Crear espacio de memoria porque char*[7] es puntero
            arrAlum[i].cursos[numCur] = new char[strlen(matri.codigoDelCurso)+1];
            strcpy(arrAlum[i].cursos[numCur],matri.codigoDelCurso);
            arrAlum[i].numeroDeCursos++;
        }
}
//Impresion
void operator <<(ofstream &archRepCur,const struct StCurso cur){
    //archRepCur<<cur;
    archRepCur<<fixed<<setprecision(2);
    archRepCur<<left<<setw(20)<<"CODIGO"<<setw(30)<<"NOMBRE"<<"CREDITOS"<<endl;
    archRepCur<<left<<setw(20)<<cur.codigoDelCurso<<setw(25)
            <<cur.nombreDelCurso<<right<<setw(5)<<cur.creditos<<endl;
    archRepCur<<left<<setw(15)<<"PROFESOR"<<cur.nombreDelProfesor<<" ["
            <<cur.codigoDelProfesor<<"]"<<endl;
    archRepCur<<"Alumnos matriculados:"<<endl;
    archRepCur<<left<<setw(15)<<"Semestre"<<"Codigo"<<endl;
    for(int i=0;i<cur.numeroDeAlumnos;i++){
        archRepCur<<left<<setw(2)<<" "<<setw(13)<<cur.alumnos[i]/10000
                <<cur.alumnos[i]%10000<<endl;
    }
    archRepCur<<setw(2)<<" "<<left<<setw(25)<<"Numero de alumnos: "<<right
            <<setw(10)<<cur.numeroDeAlumnos<<endl;
    archRepCur<<setw(2)<<" "<<left<<setw(25)<<"Total ingresado: "<<right
            <<setw(10)<<cur.ingresos<<endl;
}

void operator <<(ofstream &archRepAlum,const struct StAlumno alum){
    //archRepAlum<<alum;
    archRepAlum<<left<<setw(15)<<"SEMESTRE"<<setw(15)<<"CODIGO"<<setw(50)
            <<"NOMBRE"<<setw(35)<<"MODALIDAD"<<"ESCALA"<<endl;
    archRepAlum<<left<<setw(15)<<alum.semestre<<setw(15)<<alum.codigo
            <<setw(50)<<alum.nombre<<setw(20)<<alum.modalidad;
    if(alum.modalidad[0]=='S'){
        archRepAlum<<" CON "<<alum.porcentaje<<'%';
    }else archRepAlum<<setw(8)<<' ';
    archRepAlum<<right<<setw(10)<<alum.escala<<endl;
    archRepAlum<<"Codigos de cursos matriculados:"<<endl;
    for(int i=0;i<alum.numeroDeCursos;i++)
        archRepAlum<<setw(15)<<" "<<alum.cursos[i]<<endl;
    archRepAlum<<setw(2)<<" "<<left<<setw(25)<<"Numero de cursos: "<<right
            <<setw(10)<<alum.numeroDeCursos<<endl;
    archRepAlum<<setw(2)<<" "<<left<<setw(25)<<"Costo total: "<<right
            <<setw(10)<<alum.costoTotal<<endl;
}