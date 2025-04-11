/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  17 de septiembre de 2024, 8:32
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "FuncionesAuxiliares.h"
enum REG{COD,NOM,A,B};
#define INCREMENTO 5

void cargarAlumno(void *&al,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    void **alumnos, *reg;
    int numDat=0, cap=0;
    alumnos = nullptr;
    while(true){
        reg = leerRegistro(arch);
        if(arch.eof())break;
        if(numDat==cap) aumentamosEspacios(alumnos,numDat,cap);
        alumnos[numDat-1] = reg;
        numDat++;
    }
    
    
    
    al = alumnos;
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *codigo, cod;
    char *nombre;
    arch >> cod;
    if(arch.eof())return nullptr;
    codigo = new int;
    *codigo = cod;
    arch.get();
    nombre = leeCadena(arch);
    registro = new void*[4]{};
    registro[COD] = codigo;
    registro[NOM] = nombre;
    return registro;    
}

char* leeCadena(ifstream &arch,char delimitador){
    char buffCadena[100], *cadena;
    arch.getline(buffCadena,100,delimitador);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffCadena)+1];
    strcpy(cadena,buffCadena);
    return cadena;
}

void aumentamosEspacios(void **&alumnos,int &numDat,int &cap){
    void **aux;
    cap += INCREMENTO;
    if(alumnos == nullptr){
        alumnos = new void *[cap]{};
        numDat=1;
    }
    else{
        aux = new void *[cap]{};
        for(int i=0;i<numDat;i++){
            aux[i] = alumnos[i];
        }
        delete alumnos;
        alumnos = aux;
    }
}

void cargarNotas(void *al,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **alumnos = (void**)al;
    int nd[50]{}, cap[50]{}, cod, pos;
    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        pos = buscarAlumno(alumnos,cod);
        if(pos!=-1){
//            colocarCurso(arch,alumnos[pos],nd[pos],cap[pos]);
        }
        else while(arch.get()!='\n');
    }
    
}
int buscarAlumno(void **alumnos, int cod){
    for (int i=0;alumnos[i];i++){
        if(sonIguales(cod,alumnos[i]))return i;
    }
    return -1;
}
bool sonIguales(int cod, void *al){
    void **alumno = (void**)al;
    int *codigo = (int*)alumno[COD];
    return cod == *codigo;
}
void probarLaLectura(void *al,const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **alumnos = (void**)al;
    for(int i=0;alumnos[i];i++){
        imprimeAlumno(alumnos[i],arch);
    }
}

void imprimeAlumno(void *al,ofstream &arch){
    void **alumno = (void**)al;
    int *codigo = (int*)alumno[COD];
    char *nombre = (char*)alumno[NOM];
    
    
    arch<<right<<setw(10)<<*codigo<<setw(5)<<' '<<left<<setw(60)<<nombre<<endl;
    

}

void ordenarAlumnos(void *al){
    void **alumnos = (void**)al;
    int numDat=0;
    for (numDat = 0; alumnos[numDat]; numDat++);
    qSort(alumnos,0,numDat-1);

}

void qSort(void **alumnos,int izq,int der){
    int limite;
    if(izq>=der)return;
    cambiar(alumnos[izq],alumnos[(izq+der)/2]);
    limite = izq;
    for(int i=izq;i<=der;i++){
        if(estanEnDesorden(alumnos[i],alumnos[izq])){
            cambiar(alumnos[++limite],alumnos[i]);
        }
    }
    cambiar(alumnos[izq],alumnos[limite]);
    qSort(alumnos,izq,limite-1);
    qSort(alumnos,limite+1,der);
}
void cambiar(void *&alumI, void*&alumK){
    void *aux;
    aux = alumI;
    alumI = alumK;
    alumK = aux;
}

bool estanEnDesorden(void *alI, void* alK){
    void **alumI = (void**)alI, **alumK = (void**)alK;
    char *nombreI = (char*)alumI[NOM];
    char *nombreK = (char*)alumK[NOM];
    return strcmp(nombreI,nombreK)<0;
}