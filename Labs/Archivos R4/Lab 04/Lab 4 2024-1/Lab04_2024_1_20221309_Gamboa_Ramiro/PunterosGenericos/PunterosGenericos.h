/* 
 * File:   PunterosGenericos.h
 * Author: ramir
 *
 * Created on 11 de mayo de 2024, 22:56
 */
#include <fstream>
using namespace std;
#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

//Carga de clientes
void cargaclientes(void *&clientes);
void *leerClientes(ifstream &archCli);
char *LeeCadenaExacta(ifstream &arch,int max,char delim);
//Creacion de reserva
void creareserva(void *&reserva);
void *leerReserva(ifstream &archRes);
void *crearMemoriaExacta(int stock);
//Carga de reserva
void cargareservar(void *clientes,void *reserva);
void calcularStockActual(void *reserva,int *&stockActual);
int buscarPosCliente(void *clientes,int dni);
int buscarPosLibro(void *reserva,char *codigo);
void agregarPedido(void *registroRes,void *registroCli,int &stockActual);

#endif /* PUNTEROSGENERICOS_H */
