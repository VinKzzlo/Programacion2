/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * Archivo:   Sobrecargas.h
 * Autor: VinKzzlo
 *
 * Creado el on 3 de septiembre de 2024, 17:37
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

bool operator >>(ifstream &archLib, struct Libro &libro);
bool operator >>(ifstream &archCli, struct Cliente &cliente);

bool operator >>(struct LibroSolicitado &libroPedido, struct Libro *arrLib);
bool operator <<(struct Cliente &cli, struct LibroSolicitado libPed);
void operator ++(struct Cliente &cli);

void operator <<(ofstream &arch,const struct Libro lib);
void operator <<(ofstream &arch, const struct Cliente cli);
#endif /* SOBRECARGAS_H */

