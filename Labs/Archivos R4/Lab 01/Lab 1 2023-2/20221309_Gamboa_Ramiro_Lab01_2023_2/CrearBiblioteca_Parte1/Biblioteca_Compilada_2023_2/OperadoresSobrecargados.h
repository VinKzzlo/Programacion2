/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 26 de marzo de 2024, 13:54
 */
#include <fstream>
using namespace std;
#include "Estructuras.h"
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archCli,struct Cliente &cli);
bool operator >>(ifstream &archProd,struct Producto &prod);
bool operator >>(ifstream &archPed,struct Pedido &ped);
void operator +=(struct Cliente *arrCli,const struct Pedido &ped);
bool operator +=(struct Producto *arrProd,struct Pedido &ped);
void operator <<(ofstream &archRepCli,const struct Cliente cli);
void operator <<(ofstream &archRepProd,const struct Producto prod);

#endif /* OPERADORESSOBRECARGADOS_H */
