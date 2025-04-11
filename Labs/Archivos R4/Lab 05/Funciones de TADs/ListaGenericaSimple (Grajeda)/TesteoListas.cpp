/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TesteoListas.cpp
 * Author: ISA
 * 
 * Created on 28 de abril de 2024, 01:23 PM
 */
#include <iostream>
using namespace std;
#include "ListaGenericaSimple.h"
#include "BibliotecaEnteros.h"
#include "BibliotecaDuplas1.h"
#include <cassert>

void ListasV1(){
    void *ListaA;
    ListaA = inicializarLista();
    assert(esListaVacia(ListaA));
    insertarComienzo(ListaA,almacenaEntero(4));
    insertarComienzo(ListaA,almacenaEntero(7));
    insertarComienzo(ListaA,almacenaEntero(8));
    insertarComienzo(ListaA,almacenaEntero(6));
    cout <<"Lista A"<<endl;
    MostrarInfoLista(ListaA,mostrarEntero);
    
    void *ListaB;
    ListaB = inicializarLista(1);
    assert(esListaVacia(ListaB,1));
    insertarComienzo(ListaB,almacenaEntero(20),1);
    insertarComienzo(ListaB,almacenaEntero(30),1);
    insertarComienzo(ListaB,almacenaEntero(60),1);
    insertarComienzo(ListaB,almacenaEntero(50),1);
    cout <<"Lista B"<<endl;
    MostrarInfoLista(ListaB,mostrarEntero,1);
    
    void *ListaC;
    ListaC = inicializarLista(2);
    assert(esListaVacia(ListaC,2));
    insertarComienzo(ListaC,almacenaEntero(-39),2,incrementarCantidadEnteros);
    insertarComienzo(ListaC,almacenaEntero(40),2,incrementarCantidadEnteros);
    insertarComienzo(ListaC,almacenaEntero(0),2,incrementarCantidadEnteros);
    insertarComienzo(ListaC,almacenaEntero(-10),2,incrementarCantidadEnteros);
    insertarComienzo(ListaC,almacenaEntero(123),2,incrementarCantidadEnteros);
    cout <<"Lista C"<<endl;
    MostrarInfoLista(ListaC,mostrarEntero,2,mostrarInformacionCantidad);
    
    void *ListaD;
    ListaD = inicializarLista(2);
    assert(esListaVacia(ListaD,2));
    insertarComienzo(ListaD,almacenaEntero(9),2,incrementarSumaEnteros);
    insertarComienzo(ListaD,almacenaEntero(-15),2,incrementarSumaEnteros);
    insertarComienzo(ListaD,almacenaEntero(0),2,incrementarSumaEnteros);
    insertarComienzo(ListaD,almacenaEntero(45),2,incrementarSumaEnteros);
    insertarComienzo(ListaD,almacenaEntero(-3),2,incrementarSumaEnteros);
    cout <<"Lista D"<<endl;
    MostrarInfoLista(ListaD,mostrarEntero,2,mostrarInformacionSuma);
}

void ListasV2(){
//    void *ListaA;
//    ListaA = inicializarLista();
//    assert(esListaVacia(ListaA));
//    insertarFinal(ListaA,almacenaEntero(4));
//    eliminarFinal(ListaA,eliminarEntero);
//    cout << "Lista A" << endl;
//    MostrarInfoLista(ListaA, mostrarEntero);
//    
//    insertarFinal(ListaA,almacenaEntero(5));
//    insertarFinal(ListaA,almacenaEntero(6));
//    eliminarFinal(ListaA,eliminarEntero);
//    cout << "Lista A" << endl;
//    MostrarInfoLista(ListaA, mostrarEntero);
//    
//    eliminarFinal(ListaA,eliminarEntero);
//    insertarFinal(ListaA,almacenaEntero(4));
//    eliminarComienzo(ListaA,eliminarEntero);
//    cout << "Lista A" << endl;
//    MostrarInfoLista(ListaA, mostrarEntero);
//    
//    insertarFinal(ListaA,almacenaEntero(5));
//    insertarFinal(ListaA,almacenaEntero(6));
//    eliminarComienzo(ListaA,eliminarEntero);
//    cout << "Lista A" << endl;
//    MostrarInfoLista(ListaA, mostrarEntero);

//    void *ListaB;
//    ListaB = inicializarLista(1);
//    assert(esListaVacia(ListaB,1));
//    insertarFinal(ListaB, almacenaEntero(4),1);
//    eliminarFinal(ListaB, eliminarEntero,1);
//    cout << "Lista B" << endl;
//    assert(esListaVacia(ListaB,1));
//
//    insertarFinal(ListaB, almacenaEntero(7),1);
//    insertarFinal(ListaB, almacenaEntero(6),1);
//    eliminarFinal(ListaB, eliminarEntero,1);
//    cout << "Lista B" << endl;
//    MostrarInfoLista(ListaB, mostrarEntero,1);
//    
//    eliminarFinal(ListaB, eliminarEntero,1);
//    insertarFinal(ListaB, almacenaEntero(4),1);
//    eliminarComienzo(ListaB, eliminarEntero,1);
//    cout << "Lista B" << endl;
//    MostrarInfoLista(ListaB, mostrarEntero,1);
//
//    insertarFinal(ListaB, almacenaEntero(5),1);
//    insertarFinal(ListaB, almacenaEntero(6),1);
//    eliminarComienzo(ListaB, eliminarEntero,1);
//    cout << "Lista B" << endl;
//    MostrarInfoLista(ListaB, mostrarEntero,1);

//    void *ListaC;
//    ListaC = inicializarLista(2);
//    assert(esListaVacia(ListaC, 2));
//    insertarFinal(ListaC, almacenaEntero(4),2,incrementarCantidadEnteros);
//    eliminarFinal(ListaC, eliminarEntero,2,decrementarCantidadEnteros);
//    cout << "Lista C" << endl;
//    assert(esListaVacia(ListaC, 2));

//    insertarFinal(ListaC, almacenaEntero(7),2,incrementarCantidadEnteros);
//    insertarFinal(ListaC, almacenaEntero(6),2,incrementarCantidadEnteros);
//    eliminarFinal(ListaC, eliminarEntero,2,decrementarCantidadEnteros);
//    cout << "Lista C" << endl;
//    MostrarInfoLista(ListaC, mostrarEntero, 2, mostrarInformacionCantidad);
//    
//    eliminarFinal(ListaC, eliminarEntero,2,decrementarCantidadEnteros);
//    insertarFinal(ListaC, almacenaEntero(4),2,incrementarCantidadEnteros);
//    eliminarComienzo(ListaC, eliminarEntero,2,decrementarCantidadEnteros);
//    cout << "Lista C" << endl;
//    MostrarInfoLista(ListaC, mostrarEntero, 2, mostrarInformacionCantidad);
//
//    insertarFinal(ListaC, almacenaEntero(5),2,incrementarCantidadEnteros);
//    insertarFinal(ListaC, almacenaEntero(6),2,incrementarCantidadEnteros);
//    eliminarComienzo(ListaC, eliminarEntero,2,decrementarCantidadEnteros);
//    cout << "Lista C" << endl;
//    MostrarInfoLista(ListaC, mostrarEntero, 2, mostrarInformacionCantidad);

    void *ListaD;
    ListaD = inicializarLista(2);
    assert(esListaVacia(ListaD, 2));
    insertarFinal(ListaD, almacenaEntero(4),2,incrementarSumaEnteros);
//    eliminarFinal(ListaD, eliminarEntero,2,decrementarSumaEnteros);
//    cout << "Lista D" << endl;
//    assert(esListaVacia(ListaD, 2));

    insertarFinal(ListaD, almacenaEntero(7),2,incrementarSumaEnteros);
    insertarFinal(ListaD, almacenaEntero(6),2,incrementarSumaEnteros);
//    eliminarFinal(ListaD, eliminarEntero,2,decrementarSumaEnteros);
//     cout << "Lista D" << endl;
//    MostrarInfoLista(ListaD, mostrarEntero, 2, mostrarInformacionSuma);
    
//    eliminarFinal(ListaD, eliminarEntero,2,decrementarSumaEnteros);
    insertarFinal(ListaD, almacenaEntero(4),2,incrementarSumaEnteros);
//    cout << "Lista D" << endl;
//    MostrarInfoLista(ListaD, mostrarEntero, 2, mostrarInformacionSuma);
//    eliminarComienzo(ListaD, eliminarEntero,2,decrementarSumaEnteros);
//    cout << "Lista D" << endl;
//    MostrarInfoLista(ListaD, mostrarEntero, 2, mostrarInformacionSuma);

    insertarFinal(ListaD, almacenaEntero(5),2,incrementarSumaEnteros);
    insertarComienzo(ListaD, almacenaEntero(6),2,incrementarSumaEnteros);
//    eliminarComienzo(ListaD, eliminarEntero,2,decrementarSumaEnteros);
    cout << "Lista D" << endl;
    MostrarInfoLista(ListaD, mostrarEntero, 2, mostrarInformacionSuma);
//    void *elem;
//    cout << endl;
//    elem = ObtenerPrimerElemento(ListaD,copiaEntero,2);
//    mostrarEntero(elem);
//    cout << endl;
//    elem = ObtenerUltimoElemento(ListaD,copiaEntero,2);
//    mostrarEntero(elem);
//    cout << endl;
}

void ListasV3(){
//    void *ListaA = inicializarLista();
//    insertarComienzo(ListaA,almacenaEntero(3));
//    insertarComienzo(ListaA,almacenaEntero(4));
//    insertarComienzo(ListaA,almacenaEntero(5));
//    MostrarInfoLista(ListaA, mostrarEntero);
//    int *num = almacenaEntero(3);
//    int pos = BuscarElementoEnLista(ListaA,enterosIguales,num);
//    int *entero = (int*)ObtenerElementoPorPosicion(ListaA,pos,copiaEntero);
//    assert(entero);
//    cout << pos << " - "<<*entero <<endl;
//    delete num;
//    num = almacenaEntero(4);
//    pos = BuscarElementoEnLista(ListaA,enterosIguales,num);
//    void **nodo = (void**)obtenerNodoPorPosicion(ListaA,pos);
//    cout << pos << " - " << *((int*)(nodo[0]))<<endl;
//    delete num;
    void *ListaB = inicializarLista(1);
    insertarComienzo(ListaB, almacenaEntero(3),1);
    insertarComienzo(ListaB, almacenaEntero(4),1);
    insertarComienzo(ListaB, almacenaEntero(5),1);
    MostrarInfoLista(ListaB, mostrarEntero,1);
    cout << longitudLista(ListaB,1) << endl;
//    int *num = almacenaEntero(3);
//    int pos = BuscarElementoEnLista(ListaB, enterosIguales, num,1);
//    int *entero = (int*) ObtenerElementoPorPosicion(ListaB, pos, copiaEntero,1);
//    assert(entero);
//    cout << pos << " - " << *entero << endl;
//    delete num;
//    num = almacenaEntero(4);
//    pos = BuscarElementoEnLista(ListaB, enterosIguales, num,1);
//    void **nodo = (void**) obtenerNodoPorPosicion(ListaB, pos,1);
//    cout << pos << " - " << *((int*) (nodo[0])) << endl;
//    delete num;
    
}
void ListasV4(){
    void *ListaA = inicializarLista(2);
    insertarOrdenado(ListaA,almacenarDupla1("ABD","BRYAN"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    insertarOrdenado(ListaA,almacenarDupla1("CBC","JORGE"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
//    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    insertarOrdenado(ListaA,almacenarDupla1("FDA","FABRICIO"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
//    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    insertarOrdenado(ListaA,almacenarDupla1("HDW","SAYMON"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
//    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    insertarOrdenado(ListaA,almacenarDupla1("BDW","PATRICIA"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
//    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    insertarOrdenado(ListaA,almacenarDupla1("EDW","DIEGO"),comparardupla1Codigos,
            2,incrementarCantidadDuplas1);
    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    eliminarFinal(ListaA,eliminarDupla1,2,decrementarCantidadDuplas1);
    eliminarComienzo(ListaA,eliminarDupla1,2,decrementarCantidadDuplas1);
    MostrarInfoLista(ListaA,mostrarDupla1,2,mostrarInformacionCantidadDuplas1);
    void *ListaB = inicializarLista(2);
    insertarOrdenado(ListaB,almacenaEntero(3),compararEnteros,
            2,incrementarCantidadEnteros);
    insertarOrdenado(ListaB,almacenaEntero(6),compararEnteros,
            2,incrementarCantidadEnteros);
    insertarOrdenado(ListaB,almacenaEntero(10),compararEnteros,
            2,incrementarCantidadEnteros);
    insertarOrdenado(ListaB,almacenaEntero(5),compararEnteros,
            2,incrementarCantidadEnteros);
    insertarOrdenado(ListaB,almacenaEntero(8),compararEnteros,
            2,incrementarCantidadEnteros);
    insertarOrdenado(ListaB,almacenaEntero(4),compararEnteros,
            2,incrementarCantidadEnteros);
    MostrarInfoLista(ListaB,mostrarEntero,2,mostrarInformacionCantidad);
    EliminarEnPosicion(ListaB,3,eliminarEntero,2,decrementarCantidadEnteros);
    MostrarInfoLista(ListaB,mostrarEntero,2,mostrarInformacionCantidad);
//    EliminarLista(ListaA,eliminarDupla1,2,eliminarCantidadDuplas1);
//    EliminarLista(ListaB,eliminarEntero,2,eliminarCantidadEnteros);
//    assert(esListaVacia(ListaA,2));
//    assert(esListaVacia(ListaB,2));
}