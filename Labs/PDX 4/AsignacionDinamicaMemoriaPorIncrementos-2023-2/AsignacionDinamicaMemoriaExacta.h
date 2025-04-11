
/*/ 
 * Projecto:  AsignacionDinamicaMemoriaPorIncrementos-2023-2
 * Nombre del Archivo:  AsignacionDinamicaMemoriaExacta.h
 * Autor: XxGatitaDinamica69xX
/*/

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProducto(const char *,char ***&,int *&,double *&);

void incrementarCapacidad(char ***&,int *&,double *&,int &,int &);

void pruebaDeLecturaDeProductos(const char *,char ***,int *,double *);

void lecturaDePedidos(const char *,int *&,char ***&,int ***&);

void incrementarCapacidad(char ***&,int ***&,int *&,int &,int &);

void insertarDatosDeFecha(char *,int,int,char **&,int **&,int &,int &);

void incrementarCapacidad(char **&,int **&,int &,int &);

void pruebaDeLecturaDePedidos(const char *,int *,char ***,int ***);

void reporteDeEnvioDePedidos(const char *,char ***,int *&,double *,int *,
                             char ***,int ***);

void procesarPedidosDeFecha(ofstream &,char ***,int *&,double *,char **,int **,
                            double &,double &);

void procesarResumen_Fecha(ofstream &,int,double,double);

void procesarResumen_Total(ofstream &,int,double,double);

ifstream abrirArchivo_IFS(const char *);

ofstream abrirArchivo_OFS(const char *);

char *obtenerCadenaExacta(ifstream &,char);

void imprimirEncabezado(ofstream &,char,int);

void imprimirLinea(ofstream &,int,char);

int obtenerFecha(ifstream &);

void imprimirFecha(ofstream &,int);

int obtenerPosFecha(int,int *,int);

int obtenerPosProd(char *,char ***);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
