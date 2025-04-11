
/* 
 * Archivo:   Reloj1.cpp
 * Autor:     VinKzzlo
 * 
 * Creado el 22 de octubre de 2024, 18:30
 */

#include "Reloj1.h"

Reloj1::Reloj1(int h, int m, int s) {
    hora = h;
    minuto = m;
    segundo = s;
}  


void Reloj1::SetSegundo(int segundo) {
    this->segundo = segundo;
}

int Reloj1::GetSegundo() const {
    return segundo;
}

void Reloj1::SetMinuto(int minuto) {
    this->minuto = minuto;
}

int Reloj1::GetMinuto() const {
    return minuto;
}

void Reloj1::SetHora(int hora) {
    this->hora = hora;
}

int Reloj1::GetHora() const {
    return hora;
}

void Reloj1::operator ++(void){
    segundo++;
    if(segundo>59){
        segundo = 0;
        ++minuto;
    }
    if(minuto>59){
        minuto = 0;
        ++hora;
    }
    if (hora>23) hora = 0;
}