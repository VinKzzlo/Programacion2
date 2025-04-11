#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
#include "OperadoresSobrecargados.h"
#define NO_ENCONTRADO -1
//Parte A
void leerCursos(struct StCurso *arrCur,const char *nombArch){
    ifstream archCur;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCur,nombArch);
    
    struct StCurso cur;
    
    strcpy(arrCur[0].codigoDelCurso,"XXXXXX");
    
    while(1){
        if(!(archCur>>cur)) break;
        arrCur += cur;
    }
}
//Parte B
void leerAlumnos(struct StAlumno *arrAlum,const char *nombArch){
    ifstream archAlum;
    
    AperturaDeUnArchivoDeTextosParaLeer(archAlum,nombArch);
    
    struct StAlumno alum;
    
    arrAlum[0].semestre = 0;
    
    while(1){
        if(!(archAlum>>alum)) break;
        arrAlum += alum;
    }
}
//Parte C
void leerMatricula(struct StCurso *arrCur,struct StAlumno *arrAlum,
                   const char *nombArch){
    ifstream archMat;
    
    AperturaDeUnArchivoDeTextosParaLeer(archMat,nombArch);
    
    struct StRegistroDeMatricula matri;
    
    while(1){
        if(!(archMat>>matri)) break;
        arrCur *= matri;
        arrAlum *= matri;
    }
}
//Parte D
void calcularIngresosYCostos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch){
    double arrCostoXCred[5],credCur;
    leerEscalas(arrCostoXCred,nombArch);
    int escAlum;
    //Calculo de ingresos
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        for(int j=0;j<arrCur[i].numeroDeAlumnos;j++){
            escAlum = buscarEscalaDelAlumno(arrAlum,arrCur[i].alumnos[j]);
            if(escAlum!=NO_ENCONTRADO)
                arrCur[i].ingresos += arrCostoXCred[escAlum-1]*
                                      arrCur[i].creditos;
        }
    //Calculo de costo total
    for(int i=0;arrAlum[i].semestre!=0;i++)
        for(int j=0;j<arrAlum[i].numeroDeCursos;j++){
            credCur = buscarCreditoDelCurso(arrCur,arrAlum[i].cursos[j]);
            if(escAlum!=NO_ENCONTRADO)
                arrAlum[i].costoTotal += arrCostoXCred[arrAlum[i].escala-1]*
                                         credCur;
        }
}
void leerEscalas(double *arrCostoXCred,const char *nombArch){
    ifstream archEsc;
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,nombArch);
    char c;
    int escala;
    double costo;
    for(int i=0;!(archEsc.eof());i++){
        archEsc>>c>>escala>>costo;
        arrCostoXCred[escala-1] = costo;
    }
}
int buscarEscalaDelAlumno(struct StAlumno *arrAlum,int codAlum){
    int semestre = codAlum/10000;
    int codigo = codAlum%10000;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        if(arrAlum[i].semestre==semestre && arrAlum[i].codigo==codigo) 
            return arrAlum[i].escala;
    return NO_ENCONTRADO;
}
double buscarCreditoDelCurso(struct StCurso *arrCur,char *codCurso){
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        if(strcmp(arrCur[i].codigoDelCurso,codCurso)==0) 
            return arrCur[i].creditos;
    return NO_ENCONTRADO;
}
//Parte E
void imprimirReporte(struct StCurso *arrCur,struct StAlumno *arrAlum,
                     const char *nombArch){
    ofstream archRep;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nombArch);
    
    archRep<<"REPORTE DE CURSOS"<<endl;
    for(int i=0;strcmp(arrCur[i].codigoDelCurso,"XXXXXX")!=0;i++)
        archRep<<arrCur[i];
    archRep<<"REPORTE DE ALUMNOS"<<endl;
    for(int i=0;arrAlum[i].semestre!=0;i++)
        archRep<<arrAlum[i];
}