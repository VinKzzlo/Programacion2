/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaGenericaSimple.h
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 27 de abril de 2024, 02:27 PM
 */

#ifndef LISTAGENERICASIMPLE_H
#define LISTAGENERICASIMPLE_H
#include <fstream>
using namespace std;
void* inicializarLista(int tipo = 0);
bool esListaVacia(void *Lista,int tipo = 0);
void* crearNodo(void *dato,void *sig = nullptr);

void insertarComienzo(void *&Lista,void *elem,int tipo = 0,
        void(*actualizar)(void *&Lista,void *elem) = nullptr);
void eliminarComienzo(void *&Lista,void(*eliminar)(void *elem),int tipo = 0,
        void(*actualizar)(void *&Info,void *elem) = nullptr);
void* ObtenerPrimerElemento(void *Lista,void*(*copia)(void* elem),int tipo = 0);

void insertarFinal(void *&Lista,void *elem,int tipo = 0,
        void(*actualizar)(void *&Info,void *elem) = nullptr);
void eliminarFinal(void *&Lista,void(*eliminar)(void *elem),int tipo = 0,
        void(*actualizar)(void *&Info,void *elem) = nullptr);

void* obtenerPenultimoNodo(void *&Lista,int tipo = 0);
void* obtenerUltimoNodo(void *Lista,int tipo = 0);

void* ObtenerUltimoElemento(void *Lista,void*(*copia)(void* elem),int tipo = 0);
void* obtenerNodoAnterior(void *Lista,void *nodo_buscado,int tipo);

int BuscarElementoEnLista(void *Lista,bool(*equal)(void* I,void* K),void *elem,int tipo = 0);
void* ObtenerElementoPorPosicion(void *Lista,int pos,void*(*copia)(void* elem),int tipo = 0);
void* obtenerNodoPorPosicion(void *Lista,int pos,int tipo = 0);

int longitudLista(void *Lista,int tipo = 0,int(*longitud)(void* info) = nullptr);

void insertarOrdenado(void *&Lista,void *elem,int(*cmp)(void* datoI,void* datoK),
        int tipo = 0,void(*actualizar)(void *&Info,void *elem)= nullptr);
//void insertarOrdenadoNoVacio(void *&Lista,void *elem,void *nodo_elem,
//        int(*cmp)(void* datoI,void* datoK),int tipo);
void EliminarLista(void *&Lista,void(*eliminar)(void *elem),int tipo = 0,
        void(*eliminar_info)(void *&info) = nullptr);
void EliminarEnPosicion(void *&Lista,int pos,void(*eliminar)(void *elem),
        int tipo = 0,void(*actualizar)(void *&Info,void *elem) = nullptr);
void MostrarInfoLista(void *Lista,void (*imp)(void *elem),int tipo = 0,
        void (*reg)(void *Info) = nullptr);
void ImprimirInfoLista(ofstream &arch,void *Lista,
        void (*imp)(ofstream &arch,int pos,void *elem),int tipo = 0,
        void (*reg)(ofstream &arch,void *elem) = nullptr);
#endif /* LISTAGENERICASIMPLE_H */
