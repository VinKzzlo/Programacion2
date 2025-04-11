/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 10 de abril de 2024, 00:18
 */
#include <fstream>
using namespace std;
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archLib,struct Libro &lib);
bool operator >>(ifstream &archCli,struct Cliente &cli);
bool operator >>(struct LibroSolicitado &libPed,struct Libro *arrLib);
bool operator <<(struct Cliente &cli,const struct LibroSolicitado libPed);
void operator ++(struct Cliente &cli);
void operator <<(ofstream &archRepLib,const struct Libro lib);
void operator <<(ofstream &archRepCli,const struct Cliente cli);

#endif /* OPERADORESSOBRECARGADOS_H */
