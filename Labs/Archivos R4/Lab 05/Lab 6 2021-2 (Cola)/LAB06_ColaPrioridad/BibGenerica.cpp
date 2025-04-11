/* 
 * File:   BibGenerica.cpp
 * Author: ramir
 * 
 * Created on 27 de abril de 2024, 21:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibGenerica.h"
void creacola(void *&cola,void*(*lee)(ifstream &),int(*prioridad)(void*),
              const char *nombArch){
    void *dato;
    ifstream archReg(nombArch,ios::in);
    if(not archReg.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    generacola(cola);
    while(1){
        dato = lee(archReg);
        if(archReg.eof()) break;
        encola(cola,dato,prioridad);
    }
}

void generacola(void *&cola){
    void **quinpleta = new void*[5];
    quinpleta[0] = nullptr;
    quinpleta[1] = nullptr;
    quinpleta[2] = nullptr;
    quinpleta[3] = nullptr;
    quinpleta[4] = nullptr;
    cola = quinpleta;
}

void encola(void *cola,void *dato,int(*buscarPosPrioridad)(void*)){
    int prioridad;
    //Casteamos la cola a la quinpleta para acceder a las dir. de memoria
    void **quinpleta = (void**)cola;
    void **nuevo,**aux;
    
    nuevo = new void*[2];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    
    prioridad = buscarPosPrioridad(dato);
    
    if(colavacia(cola)){
        quinpleta[0] = nuevo;
        quinpleta[prioridad] = nuevo;
        quinpleta[4] = nuevo;
    }else{
        if(prioridad==1) encolaprioridad1(cola,nuevo);
        else if(prioridad==2) encolaprioridad2(cola,nuevo);
        else encolaprioridad3(cola,nuevo);
    }
}

bool colavacia(void *cola){
    void **quinpleta = (void**)cola;
    if(quinpleta[0]==nullptr) return true;
    return false;
}

void encolaprioridad1(void *cola,void **nuevo){
    void **quinpleta = (void**)cola;
    void **aux,**sig;
    if(quinpleta[1]==nullptr){
        aux = (void**)quinpleta[0];
        nuevo[1] = aux;
        quinpleta[0] = nuevo;
        quinpleta[1] = nuevo;
    }else{
        aux = (void**)quinpleta[1];
        if(aux[1]==nullptr){
            quinpleta[4] = nuevo;
        }else{
            sig = (void**)aux[1];
            nuevo[1] = sig;
        }
        aux[1] = nuevo;
        quinpleta[1] = nuevo;
    }
}

void encolaprioridad2(void *cola,void **nuevo){
    void **quinpleta = (void**)cola;
    void **aux,**sig;
    if(quinpleta[2]==nullptr){
        if(quinpleta[1]==quinpleta[4]){
            aux = (void**)quinpleta[4];
            aux[1] = nuevo;
            quinpleta[2] = nuevo;
            quinpleta[4] = nuevo;
        }else if(quinpleta[3]==quinpleta[4]){
            if(quinpleta[1]==nullptr){
                aux = (void**)quinpleta[0];
                nuevo[1] = aux;
                quinpleta[2] = nuevo;
                quinpleta[0] = nuevo;
            }else{
                sig = (void**)quinpleta[1];
                aux = (void**)sig[1];
                nuevo[1] = aux;
                sig[1] = nuevo;
                quinpleta[2] = nuevo;
            }
        }
    }else{
        aux = (void**)quinpleta[2];
        if(quinpleta[2]==quinpleta[4]){
            quinpleta[4] = nuevo;
        }else{
            sig = (void**)aux[1];
            nuevo[1] = sig;
        }
        aux[1] = nuevo;
        quinpleta[2] = nuevo;
    }
}

void encolaprioridad3(void *cola,void **nuevo){
    void **quinpleta = (void**)cola;
    void **aux;
    aux = (void**)quinpleta[4];
    aux[1] = nuevo;
    quinpleta[3] = nuevo;
    quinpleta[4] = nuevo;
}

void *desencola(void *cola){
    
    if(colavacia(cola)) return nullptr;
    
    void **dupla = (void**)cola;
    void **colaIni = (void**)dupla[0];
    void **penultimo,*dato;
    
    if(dupla[0]==dupla[1]){
        dupla[0] = nullptr;
        dupla[1] = nullptr;
    }else{
        penultimo = (void**)colaIni[1];
        dupla[0] = penultimo;
        colaIni[1] = nullptr;
    }
    dato = colaIni[0];
    delete colaIni;
    return dato;
}