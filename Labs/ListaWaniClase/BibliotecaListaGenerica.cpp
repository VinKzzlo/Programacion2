/* 
 * Archivo:   BibliotecaListaGenerica.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 15:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "BibliotecaListaGenerica.h"

enum REG { DATO, SIG };

void creaLista(const char*nombArch, void *&lista, void *(*lee)(ifstream&),
               int(*compara)(const void*, const void*)) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void *dato;
    lista = nullptr;
    while (true) {
        dato = lee(arch);
        if (arch.eof()) break;
        insertarEnLista(dato, lista, compara);
    }
}

void insertarEnLista(void *dato, void*&lista,
                     int(*compara)(const void*, const void*)) {
    
    void **p = (void**) lista, **ant = nullptr, **nuevo;
    nuevo = new void*[2]{};
    nuevo[DATO] = dato;
    while (p) {
        if (compara(p[DATO], nuevo[DATO]) > 0) break;
        ant = p;
        p = (void**) p[SIG];
    }
    nuevo[SIG] = p;
    if (ant) ant[SIG] = nuevo;
    else lista = nuevo;
}

void imprimirLista(const char*nombArch, void *lst,
                   void (*imprimeDato)(ofstream &arch, void*)) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }

    void **lista = (void **) lst;
    while (lista) {
        imprimeDato(arch, lista[DATO]);
        lista = (void**) lista[SIG];
    }
}

void eliminarLista(void *lst, void (*eliminarDato)(void*)) {
    void **lista = (void **) lst, **sale;
    while (lista) {
        sale = lista;
        eliminarDato(sale[DATO]);
        lista = (void **) lista[SIG];
        delete sale;
    }
}