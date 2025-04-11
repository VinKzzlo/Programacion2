/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaGenericaSimple.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 27 de abril de 2024, 02:27 PM
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "ListaGenericaSimple.h"
#include "BibliotecaDuplas1.h"
#define NO_ENCONTRADO -1
enum NODE{NODE_DATO,NODE_SIG};
enum LIST{LIST_START,LIST_END,LIST_INFO};
enum TYPE{TYPE_UNIT,TYPE_RANGE,TYPE_COMPLEX};
//Solo un puntero, Solo inicio y fin, Con informacion extra en un espacio mas
void* inicializarLista(int tipo){
    void **gestor;
    switch(tipo){
        case TYPE_UNIT:{
            gestor = nullptr;
            break;
        }
        case TYPE_RANGE:{
            gestor = new void*[TYPE_RANGE+1]{};
            break;
        }
        case TYPE_COMPLEX:{
            gestor = new void*[TYPE_COMPLEX+1]{};
            break;
        }
    }
    return gestor;
}
bool esListaVacia(void *Lista,int tipo){
    bool vacia;
    if(tipo == TYPE_UNIT){
        vacia = (Lista == nullptr);
    }else if (tipo == TYPE_RANGE or tipo == TYPE_COMPLEX) {
        void **gestor = (void**) Lista;
        vacia = (gestor[LIST_START] == nullptr);
    } else {
        cout << "Tipo no existente" << endl;
        exit(1);
    }
    return vacia;
}
void* crearNodo(void *dato,void *sig){
    void **nodo = new void*[2];
    nodo[NODE_DATO] = dato;
    nodo[NODE_SIG] = sig;
    return nodo;
}
void insertarComienzo(void *&Lista,void *elem,int tipo,
        void(*actualizar)(void *&Info,void *elem)){
    void *nodo;
    if(tipo == TYPE_UNIT) {
        nodo = crearNodo(elem, Lista);
        Lista = nodo;
    }else{
        void **gestor = (void**)Lista;
        nodo = crearNodo(elem,gestor[LIST_START]);
        if (gestor[LIST_START] == nullptr)gestor[LIST_END] = nodo;
        gestor[LIST_START] = nodo;
        if (tipo == TYPE_COMPLEX and actualizar != nullptr)
            actualizar(gestor[LIST_INFO], elem);
    }
}
void eliminarComienzo(void *&Lista,void(*eliminar)(void *elem),int tipo,
        void(*actualizar)(void *&Info,void *elem)){
    void **primernodo;
    if(esListaVacia(Lista,tipo)){
        cout << "No se puede eliminar nada de una lista vacia" << endl;
    }else if(tipo == TYPE_UNIT){
        primernodo = (void**)Lista;
        Lista = primernodo[NODE_SIG];
        eliminar(primernodo[NODE_DATO]);
        delete primernodo;
    }else{
        void **gestor = (void**)Lista;
        primernodo = (void**)gestor[LIST_START];
        if(gestor[LIST_START] == gestor[LIST_END])gestor[LIST_END] = nullptr;
        gestor[LIST_START] = primernodo[NODE_SIG];
        if(actualizar != nullptr and tipo == TYPE_COMPLEX)
            actualizar(gestor[LIST_INFO],primernodo[NODE_DATO]);
        eliminar(primernodo[NODE_DATO]);
        delete primernodo;
    }
}
void insertarFinal(void *&Lista,void *elem,int tipo,
        void(*actualizar)(void *&Info,void *elem)){
    void *nodo = crearNodo(elem);
    void *ultimo = obtenerUltimoNodo(Lista,tipo),**ultimoNodo;
    if (tipo == TYPE_UNIT) {
        if (esListaVacia(Lista,TYPE_UNIT))Lista = nodo;
        else {
            ultimoNodo = (void**) ultimo;
            ultimoNodo[NODE_SIG] = nodo;
        }
    } else {
        void **gestor = (void**) Lista;
        if (ultimo == nullptr){
            gestor[LIST_START] = nodo;
        }else{
            ultimoNodo = (void**) ultimo;
            ultimoNodo[NODE_SIG] = nodo;
        }
        gestor[LIST_END] = nodo;
        if (tipo == TYPE_COMPLEX and actualizar != nullptr)
            actualizar(gestor[LIST_INFO], elem);
    }
}
void eliminarFinal(void *&Lista,void(*eliminar)(void *elem),int tipo,
        void(*actualizar)(void *&Info,void *elem)){
    void *ultimo,**ultimonodo,*nuevoultimo;
    if(esListaVacia(Lista,tipo)){
        cout << "No se puede eliminar nada de una lista vacia" << endl;
    }else if(tipo == TYPE_UNIT){
        ultimo = obtenerUltimoNodo(Lista,tipo);
        ultimonodo = (void**)ultimo;
        nuevoultimo = obtenerPenultimoNodo(Lista,tipo);
        eliminar(ultimonodo[NODE_DATO]);
        delete ultimonodo;
        if(nuevoultimo != nullptr) {
            ultimonodo = (void**) nuevoultimo;
            ultimonodo[NODE_SIG] = nullptr;
        }else Lista = nullptr;
    }else{
        void **gestor = (void**)Lista;
        ultimo = gestor[LIST_END];
        ultimonodo = (void**)ultimo;
        nuevoultimo = obtenerPenultimoNodo(Lista,tipo);
        if(actualizar != nullptr and tipo == TYPE_COMPLEX)
            actualizar(gestor[LIST_INFO],ultimonodo[NODE_DATO]);
        eliminar(ultimonodo[NODE_DATO]);
        delete ultimonodo;
        if(nuevoultimo != nullptr){
            ultimonodo = (void**) nuevoultimo;
            ultimonodo[NODE_SIG] = nullptr;
            gestor[LIST_END] = nuevoultimo;
        }else{
            gestor[LIST_END] = gestor[LIST_START] = nullptr;
        }
    }
}
void* obtenerPenultimoNodo(void *&Lista,int tipo){
    void *ant = nullptr,**nodo = (void**)Lista;
    if(tipo != TYPE_UNIT)nodo = (void**)nodo[LIST_START];
    while(nodo[NODE_SIG] != nullptr){
        ant = nodo;
        nodo = (void**)nodo[NODE_SIG];
    }
    return ant;
}
void* obtenerUltimoNodo(void *Lista,int tipo){
    void *ultimo;
    if(tipo == TYPE_UNIT){
        if(Lista == nullptr)ultimo = nullptr;
        else{
            void **nodo = (void**)Lista;
            while (nodo[NODE_SIG] != nullptr) nodo = (void**)nodo[NODE_SIG];
            ultimo = nodo;
        }
    }else{
        void **gestor = (void**)Lista;
        ultimo = gestor[LIST_END];
    }
    return ultimo;
}
void* ObtenerPrimerElemento(void *Lista,void*(*copia)(void* elem),int tipo){
    void **first,*elem;
    if(esListaVacia(Lista,tipo))elem = nullptr;
    else if(tipo == TYPE_UNIT){
        first = (void**)Lista;
        elem = copia(first[NODE_DATO]);
    }else{
        void **gestor = (void**)Lista;
        first = (void**)gestor[LIST_START];
        elem = copia(first[NODE_DATO]);
    }
    return elem;
}
void* ObtenerUltimoElemento(void *Lista,void*(*copia)(void* elem),int tipo){
    void *last = obtenerUltimoNodo(Lista,tipo),*elem;
    if(esListaVacia(Lista,tipo))elem = nullptr;
    else{
        void **nodo = (void**)last;
        elem = copia(nodo[NODE_DATO]);
    }
    return elem;
}
int BuscarElementoEnLista(void *Lista,bool(*equal)(void* I,void* K),void *elem,int tipo){
    int i=0;
    void *buscar,**nodo;
    if(tipo == TYPE_UNIT)buscar = Lista;
    else{
        void **gestor = (void**)Lista;
        buscar = gestor[LIST_START];
    }
    while(buscar != nullptr){
        nodo = (void**)buscar;
        if(equal(nodo[NODE_DATO],elem))return i;
        buscar = nodo[NODE_SIG];
        i++;
    }
    return NO_ENCONTRADO;
}
void* ObtenerElementoPorPosicion(void *Lista,int pos,void*(*copia)(void* elem),int tipo){
    void *iter,**nodo;
    if (tipo == TYPE_UNIT)iter = Lista;
    else {
        void **gestor = (void**) Lista;
        iter = gestor[LIST_START];
    }
    while(pos != 0 and iter != nullptr){
        nodo = (void**)iter;
        iter = nodo[NODE_SIG];
        pos--;
    }
    if(iter == nullptr)return nullptr;
    nodo = (void**)iter;
    return copia(nodo[NODE_DATO]);
}
void* obtenerNodoPorPosicion(void *Lista,int pos,int tipo){
    void *iter, **nodo;
    if (tipo == TYPE_UNIT)iter = Lista;
    else {
        void **gestor = (void**) Lista;
        iter = gestor[LIST_START];
    }
    while (pos != 0 and iter != nullptr) {
        nodo = (void**) iter;
        iter = nodo[NODE_SIG];
        pos--;
    }
    return iter;
}
void* obtenerNodoAnterior(void *Lista,void *nodo_buscado,int tipo){
    void *iter,**nodo,*ant = nullptr;
    if (tipo == TYPE_UNIT)iter = Lista;
    else {
        void **gestor = (void**) Lista;
        iter = gestor[LIST_START];
    }
    while (iter != nullptr) {
        if(nodo_buscado == iter)break;
        ant = iter;
        nodo = (void**) iter;
        iter = nodo[NODE_SIG];
    }
    return ant;
}
int longitudLista(void *Lista,int tipo,int(*longitud)(void* info)){
    void *recorrido,**nodo,**gestor;
    int i;
    if(esListaVacia(Lista,tipo))i = 0;
    else if(longitud == nullptr){
        if(tipo == TYPE_RANGE){
            gestor = (void**)Lista;
            recorrido = gestor[LIST_START];
        }else recorrido = Lista;
        for(i = 0;recorrido!=nullptr;i++){
            nodo = (void**)recorrido;
            recorrido = nodo[NODE_SIG];
        }
    }else{
        gestor = (void**)Lista;
        i = longitud(gestor[LIST_INFO]);
    }
    return i;
}
void insertarOrdenado(void *&Lista,void *elem,int(*cmp)(void* datoI,void* datoK),
        int tipo,void(*actualizar)(void *&Info,void *elem)){
    void *nodo = crearNodo(elem);
    void *actual,**gestor,*ant = nullptr,**nodoA,**nodoE,**nodoP;
    if(tipo == TYPE_UNIT)actual = Lista;
    else{
        gestor = (void**)Lista;
        actual = gestor[LIST_START];
    }
    if(esListaVacia(Lista,tipo)){
        if(tipo == TYPE_UNIT)Lista = nodo;
        else gestor[LIST_START] = gestor[LIST_END] = nodo;
    }else{
        nodoA = (void**) actual;
        nodoE = (void**) nodo;
        while (nodoA != nullptr) {
            if (cmp(elem, nodoA[NODE_DATO]) < 0)break;
            nodoP = nodoA;
            nodoA = (void**)nodoA[NODE_SIG];
        }
        nodoE[NODE_SIG] = nodoA;
        if (nodoP == nullptr) {
            if (tipo == TYPE_UNIT)Lista = nodoE;
            else gestor[LIST_START] = nodoE;
        } else {
            nodoP[NODE_SIG] = nodo;
        }
        if (nodoA == nullptr and tipo != TYPE_UNIT) {
            gestor[LIST_END] = nodo;
        }
    }
    if(tipo == TYPE_COMPLEX and actualizar != nullptr)
        actualizar(gestor[LIST_INFO],elem);
}

void EliminarLista(void *&Lista,void(*eliminar)(void *elem),int tipo,
        void(*eliminar_info)(void *&info)){
    void *recorrer,*aux,**gestor,**nodo;
    if(esListaVacia(Lista,tipo))cout << "No se puede eliminar una lista vacia"<<endl;
    else{
        if (tipo == TYPE_UNIT)Lista = recorrer;
        else {
            gestor = (void**) Lista;
            recorrer = gestor[LIST_START];
        }
        while (recorrer != nullptr) {
            nodo = (void**)recorrer;
            aux = nodo[NODE_SIG];
            eliminar(nodo[NODE_DATO]);
            delete nodo;
            recorrer = aux;
        }
        if(tipo == TYPE_UNIT)Lista = nullptr;
        else{
            gestor[LIST_START] = gestor[LIST_END] = nullptr;
            if (tipo == TYPE_COMPLEX and eliminar_info != nullptr)
                eliminar_info(gestor[LIST_INFO]);
        }
        
    }
}
void EliminarEnPosicion(void *&Lista,int pos,void(*eliminar)(void *elem),
        int tipo,void(*actualizar)(void *&Info,void *elem)){
    if(tipo < 0){
        cout << "No existen posiciones negativas" << endl;
    }else if(esListaVacia(Lista,tipo)){
        cout << "No se pueden eliminar datos de una lista vacia" << endl;
    }else{
        void **nodoA, **gestor;
        if (tipo == TYPE_UNIT) {
            nodoA = (void**) Lista;
        } else {
            gestor = (void**) Lista;
            nodoA = (void**) gestor[LIST_START];
        }
        void **nodoP = nullptr;
        for (int i = 0; i < pos; i++) {
            nodoP = nodoA;
            nodoA = (void**)nodoA[NODE_SIG];
        }
        if(nodoP == nullptr){
            eliminarComienzo(Lista,eliminar,tipo,actualizar);
        }else if(nodoA[NODE_SIG] == nullptr){
            eliminarFinal(Lista,eliminar,tipo,actualizar);
        }else{
            nodoP[NODE_SIG] = nodoA[NODE_SIG];
            if(actualizar != nullptr and tipo == TYPE_COMPLEX)
                actualizar(gestor[LIST_INFO],nodoA[NODE_DATO]);
            eliminar(nodoA[NODE_DATO]);
            delete nodoA;
        }
    }
}
//void UnirListas(void *&ListaPrincipal,void *&ListaSecundaria,int tipoP,int tipoS,
//        void(*plancha)(void *P,void *&S)){
//    void **gestorP,**gestorS;
//    void **ultimoP = (void**)obtenerUltimoNodo(ListaPrincipal,tipoP),
//            **ultimoS = (void**)obtenerUltimoNodo(ListaSecundaria,tipoS);
//    if(esListaVacia(ListaSecundaria,tipoS)){
//        cout << "No se modifica la lista secundaria"<< endl;
//    }else if(tipoP == TYPE_UNIT){
//        
//        if(tipoS == TYPE_UNIT){
//            
//            tipoS = ListaSecundaria;
//        }else{
//            gestorS = (void**)ListaSecundaria;
//        }
//        if(esListaVacia(ListaPrincipal,tipoP)){
//            
//        }
//    }else if(tipoP == TYPE_RANGE){
//        if(esListaVacia(ListaPrincipal,tipoP)){
//            
//        }
//    }else{
//        if(esListaVacia(ListaPrincipal,tipoP)){
//            
//        }
//    }
//}
void MostrarInfoLista(void *Lista,void (*imp)(void *elem),int tipo,
        void (*reg)(void *Info)){
    void *recorrido,**gestor,**nodo;
    if(tipo == TYPE_UNIT)recorrido = Lista;
    else{
        gestor = (void**)Lista;
        recorrido = gestor[LIST_START];
    }
    if(not esListaVacia(Lista,tipo)){
        cout << '[';
        while (recorrido != nullptr) {
            nodo = (void**) recorrido;
            imp(nodo[NODE_DATO]);
            if (nodo[NODE_SIG] != nullptr)cout << ", ";
            recorrido = nodo[NODE_SIG];
        }
        cout << ']' << endl;
        if (reg != nullptr and tipo == TYPE_COMPLEX)reg(gestor[LIST_INFO]);
    }else cout << "Es una lista vacia" << endl;
}
void ImprimirInfoLista(ofstream &arch,void *Lista,
        void (*imp)(ofstream &arch,int pos,void *elem),int tipo,
        void (*reg)(ofstream &arch,void *elem)){
    void *recorrido, **gestor, **nodo;
    if (tipo == TYPE_UNIT)recorrido = Lista;
    else {
        gestor = (void**) Lista;
        recorrido = gestor[LIST_START];
    }
    if (not esListaVacia(Lista, tipo)) {
        arch << "Elementos de la lista: "<<endl;
        int i=0;
        while (recorrido != nullptr) {
            nodo = (void**) recorrido;
            imp(arch,i,nodo[NODE_DATO]);
            arch << endl;
            recorrido = nodo[NODE_SIG];
            i++;
        }
        if (reg != nullptr and tipo == TYPE_COMPLEX)reg(arch,gestor[LIST_INFO]);
    } else cout << "Es una lista vacia" << endl;
}



