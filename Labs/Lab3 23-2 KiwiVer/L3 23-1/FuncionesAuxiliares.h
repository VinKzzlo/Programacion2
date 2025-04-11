/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 20:20
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios);
char **leerRegistro(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,char delim);
void aumentarCapacidad(char ***&productos,int *&stock,double *&precios,
                       int &numDat,int &cap);
void agregarProductos(char ***&productos,int *&stock,double *&precios,
                      char **registro,double precio,int cant,int &numDat);
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
                        double *precios);

void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos);
int *leeDNIyCant(ifstream &arch);
int leeFecha(ifstream &arch);
int buscarFecha(int fecha,int *fechaPedidos);
void aumentarCapFecha(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&cantPed,
                      int &numDat,int &cap);
void pasarAuxAPuntero(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&cantPed,
                      int &numDat,int &cap);
void agregarPedido(char **&codigoPedidos,int **&dniCantPedidos,
                   int &numPed,int &cantPed,int *dniCant,char *codigo);
void aumentarCapPed(char **&codigoPedidos,int **&dniCantPedidos,
                   int &numPed,int &cantPed);
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos, int ***&dniCantPedidos);
#endif /* FUNCIONESAUXILIARES_H */

