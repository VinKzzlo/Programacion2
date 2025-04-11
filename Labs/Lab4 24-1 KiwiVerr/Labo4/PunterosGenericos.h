/* 
 * Archivo:   PunterosGenericos.h
 * Autor:     VinKzzlo
 *
 * Creado el  23 de septiembre de 2024, 23:55
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaclientes(void *&clientes);
void *leerRegistro(ifstream &arch);
char *leeCadenaExacta(ifstream &arch, char delim='\n');
void creareserva(void *&reserva);
void* leeReserva(ifstream &arch);
void* crearEspaciosExactos(int stock);
void cargareservar(void *clientes,void *reserva);
void stockParaManejarlo(void *res, int *&stockActual);
int buscaCliente(void *cli,int dni);
int buscaLibro(void *res,char *codLib);
void agregarPedido(void *cli,void *res,int &stockActual);
#endif /* PUNTEROSGENERICOS_H */

