/* 
 * File:   PriorityQueu.cpp
 * Author: ramir
 * 
 * Created on 13 de mayo de 2024, 22:07
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PriorityQueu.h"
void creaCola(void *&cola,void*(*lee)(ifstream &),int(*prioridad)(void *),
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
        encolar(cola,dato,prioridad);
    }
}

void generacola(void *&cola){
    void **dupla = new void*[2];
    dupla[0] = nullptr;
    dupla[1] = nullptr;
    cola = dupla;
}

void encolar(void *cola,void *dato,int(*prioridad)(void *)){
    void **dupla = (void**)cola;
    void **nuevo,**aux,**siguiente,**ultimo;
    int prioridadDato,prioridadAux;
    nuevo = new void*[3];
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    nuevo[2] = nullptr;
    if(colavacia(cola)){
        //No existe nada agregado aun
        dupla[0] = nuevo;
        dupla[1] = nuevo;
    }else{
        //Existe ya algo agregado
        aux = (void**)dupla[1];
        prioridadDato = prioridad(dato);
        //Se recorre desde el final de la cola
        while(aux){
            prioridadAux = prioridad(aux[0]);
            //Compara si la prioridad del dato anterior es menor a el para
            //encolarlo despues de el
            if(prioridadDato<=prioridadAux){
                //Cuando ya encontro su prioridad, se enlaza con el dato
                //anterior a el
                ultimo = (void**)dupla[1];
                aux[2] = nuevo;
                nuevo[1] = aux;
                //Se verifica si es el ultimo de la cola, ya que, ya estando
                //enlazado con el ultimo de la cola, solo tendria la cabeza
                //fincola enlazarse a el y ahi muere
                if(prioridadAux==prioridad(ultimo[0])){
                    dupla[1] = nuevo;
                }else{
                    //Sino entonces se enlaza con el que esta siguiente a el
                    //y la cabeza ya no tendria por que cambiar porque ya no
                    //es el ultimo nodo
                    nuevo[2] = siguiente;
                    siguiente[1] = nuevo;
                }
                return;
            }
            //Si todavia no encuentra su prioridad, entonces sigue recorriendo
            //hacia adelante de la cola y guardamos el nodo que esta siguiente
            //a el
            siguiente = aux;
            aux = (void**)aux[1];
        }
        nuevo[2] = siguiente;
        siguiente[1] = nuevo;
        dupla[0] = nuevo;
    }
}

bool colavacia(void *cola){
    void **dupla = (void**)cola;
    if(dupla[0]==nullptr) return true;
    return false;
}

void prueba(void *cola,void(*imprime)(ofstream &,void *),const char *nombArch){
    void *dato;
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(1){
        dato = desencola(cola);
        if(dato==nullptr) break;
        imprime(archRep,dato);
    }
}

void *desencola(void *cola){
    
    if(colavacia(cola)) return nullptr;
    
    void **dupla = (void**)cola;
    void **colaIni = (void**)dupla[0];
    void **segundo,*dato;
    if(dupla[0]==dupla[1]){
        dupla[0] = nullptr;
        dupla[1] = nullptr;
    }else{
        segundo = (void**)colaIni[2];
        dupla[0] = segundo;
        colaIni[2] = nullptr;
        segundo[1] = nullptr;
    }
    dato = colaIni[0];
    delete colaIni;
    return dato;
}