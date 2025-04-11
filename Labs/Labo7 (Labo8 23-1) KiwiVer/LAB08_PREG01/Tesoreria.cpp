/* 
 * Archivo:   Tesoreria.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  6 de noviembre de 2024, 20:29
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "Tesoreria.h"
#include "Escala.h"

Tesoreria::Tesoreria() {
    for(int i=0;i<10;i++)
        lescala[i].SetCodigo(0);
}

void Tesoreria::cargaescalas(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int codigo;
    double precio;
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        arch>>precio;
        lescala[codigo-1].SetCodigo(codigo);
        lescala[codigo-1].SetPrecio(precio);
    }
}

void Tesoreria::cargaalumnos(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char categoria;
    int cantP=0, cantS=0, cantV=0;
    while(true){
        arch>>categoria;
        if(arch.eof())break;
        arch.get();
        switch(categoria){
            case 'P':
                lpresencial[cantP].leerDatos(arch);
                cantP++;
                break;
            case 'S':
                lsemipresencial[cantS].leerDatos(arch);
                cantS++;
                break;
            case 'V':
                lvirtual[cantV].leerDatos(arch);
                cantV++;
                break;
        }
    }
    lpresencial[cantP].SetCodigo(0);
    lsemipresencial[cantS].SetCodigo(0);
    lvirtual[cantV].SetCodigo(0);
}

void Tesoreria::actualiza(int creditos) {
    int esc;
    double precioEsc;
    for(int i=0;lpresencial[i].GetCodigo();i++){
        esc = lpresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lpresencial[i].actualiza(precioEsc*creditos);
    }
    for(int i=0;lsemipresencial[i].GetCodigo();i++){
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lsemipresencial[i].actualiza(precioEsc*creditos);
    }
    for(int i=0;lvirtual[i].GetCodigo();i++){
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lvirtual[i].actualiza(precioEsc*creditos);
    }
}

void Tesoreria::imprime(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    for(int i=0;lpresencial[i].GetCodigo();i++)
        lpresencial[i].imprime(arch);
    for(int i=0;lsemipresencial[i].GetCodigo();i++)
        lsemipresencial[i].imprime(arch);
    for(int i=0;lvirtual[i].GetCodigo();i++)
        lvirtual[i].imprime(arch);
}
