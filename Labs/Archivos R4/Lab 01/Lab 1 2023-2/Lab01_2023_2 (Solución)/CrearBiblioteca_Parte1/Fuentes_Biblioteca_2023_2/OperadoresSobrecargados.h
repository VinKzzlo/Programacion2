/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 4 de abril de 2024, 15:51
 */
#include <fstream>
using namespace std;
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archCli,struct Cliente &cli);
bool operator >>(ifstream &archProd,struct Producto &prod);
bool operator >>(ifstream &archPed,struct Pedido &ped);
void operator +=(struct Cliente *arrCli,const struct Pedido ped);
bool operator +=(struct Producto *arrProd,struct Pedido &ped);
void operator <<(ofstream &archRepCli,const struct Cliente cli);
void operator <<(ofstream &archRepProd,const struct Producto prod);

#endif /* OPERADORESSOBRECARGADOS_H */
