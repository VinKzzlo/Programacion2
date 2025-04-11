/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 8 de septiembre de 2024, 11:17 PM
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H
//Lectura
void operator >>(ifstream &archPla,struct Plato &plato);
void operator >>(ifstream &archRpt,struct Repartidor &repar);
void operator >>(ifstream &archPed,struct Pedido &ped);
//Operaciones
bool operator <=(struct Pedido &ped,struct Plato *arrPlatos);
void operator <=(struct Repartidor *arrRepartidores,struct Pedido ped);
void operator !(struct OrdenDeCompra &ord);
void operator !(struct Repartidor &repar);
//Impresion
void operator <<(ofstream &archRep,struct Plato plato);
void operator <<(ofstream &archRep,struct Repartidor repar);
#endif /* OPERADORESSOBRECARGADOS_H */
