/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bibliotecasComunes.hpp"

char *leeCadena(ifstream &arch,char delimitador){
    char buffer[100],*cadena;
    arch.getline(buffer,100,delimitador);
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}