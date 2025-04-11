/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   Sobrecargas.h
 * Autor: VinKzzlo
 *
 * Creado el on 5 de septiembre de 2024, 21:45
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

bool operator >>(ifstream &archCli, struct Cliente &cliente);
bool operator >>(ifstream &archPro, struct Producto &producto);
bool operator >>(ifstream &archPed, struct Pedido &pedido);

void operator +=(struct Cliente *arrClientes, struct Pedido &pedido);
bool operator +=(struct Producto *arrProd, struct Pedido &pedido);
void operator <<(ofstream &archRep, const struct Cliente cliente);
void operator <<(ofstream &archRep, const struct Producto producto);

#endif /* SOBRECARGAS_H */

