/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: gabri
 * 
 * Created on 28 de noviembre de 2024, 09:15
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
using namespace std;
#include "Restaurante.h"

Restaurante::Restaurante() {
}

Restaurante::Restaurante(const Restaurante& orig) {
}

Restaurante::~Restaurante() {
}

void Restaurante::carga(){
    ifstream arch("atenciones.csv", ios::in);
    if(!arch){
        cout<<"No se puedo abrir el archivo atenciones";
        exit(1);
    }
    Comanda aux;
    while(1){
        aux.lee(arch);
        if(arch.eof())break;
//        cout << "Leyendo Comanda ID: " << aux.GetId() << endl;
        vector<Dato> vaux;
        mcomandas[aux]=vaux;
        cout << "Insertada Comanda ID: " << aux.GetId() << ", Tamaño actual del mapa: " << mcomandas.size() << endl;
    }
}

void Restaurante::setLineaBusqueda(string lineaBusqueda) {
    this->lineaBusqueda = lineaBusqueda;
}

string Restaurante::getLineaBusqueda() const {
    return lineaBusqueda;
}

void Restaurante::cargaPlato(string linea){
    ifstream arch("comandas3.txt", ios::in);
    if(!arch){
        cout<<"No se puedo abrir el archivo comandas3";
        exit(1);
    }
    string id;
    Dato aux;
    lineaBusqueda=linea;
    while(1){
        getline(arch, id, ',');
        if(arch.eof())break;
        lineaBusqueda=aux.generarMemoria(lineaBusqueda, id);
        aux.lee(arch);
        for(map<Comanda, vector<Dato>>::iterator it=mcomandas.begin(); it!=mcomandas.end(); it++){
            string mapId=it->first.GetId();
            if(mapId==id){
                it->second.push_back(aux);
                break;
            }
        }
    }
}

void Restaurante::muestra(){
    ofstream arch("Reporte.txt", ios::out);
    if(!arch){
        cout<<"No se puedo abrir el archivo Reporte";
        exit(1);
    }
    for(map<Comanda, vector<Dato>>::iterator it=mcomandas.begin(); it!=mcomandas.end(); it++){
        it->first.imprime(arch);
        arch<<endl;
        for(int i=0; i<it->second.size(); i++){
            arch<<setw(2)<<setfill('0')<<i+1<<setfill(' ')<<") ";
            it->second[i].imprime(arch);
            arch<<endl;
        }
        arch<<endl;
    }
}

void Restaurante::actualiza(int eliminar){
    map<Comanda, vector<Dato>> mcomandas_actualizado;
    Comanda aux;
    for(map<Comanda, vector<Dato>>::iterator it=mcomandas.begin(); it!=mcomandas.end(); it++){
        vector<Dato> vaux;
        aux=it->first;
        
        double total = 0.0;
        int tiempo_preparacion = 0;
        
        for(int i=0; i<it->second.size(); i++){
            if(!it->second[i].contiene(eliminar)){
                vaux.push_back(it->second[i]);
            }
            total += it->second[i].ObtenPrecio();
            tiempo_preparacion += it->second[i].tiempoPrep();
        }
         aux.VerificarTardanza();
         aux.SetTotal(total);
         aux.SetTiempo_preparacion(tiempo_preparacion);
         mcomandas_actualizado[aux] = vaux; 
    }
    mcomandas = move(mcomandas_actualizado);
}