/* 
 * Archivo:   MetodoPorIncrementos.h
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 18:35
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock);
char **leerLibro(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,int max,char delim);
int *leerStock(ifstream &arch);
void aumentarEspacios(char ***&libros,int **&stock,int &numDat,int &cap);
void agregarRegs(char ***libros,int **stock,
                 char **regLibro,int *regStock,int &numDat);
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock);
#endif /* METODOPORINCREMENTOS_H */

