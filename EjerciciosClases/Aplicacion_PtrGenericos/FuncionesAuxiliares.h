/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor:     VinKzzlo
 *
 * Creado el  17 de septiembre de 2024, 8:32
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarAlumno(void *&alumno,const char *nombArch);
void *leerRegistro(ifstream &arch);
char* leeCadena(ifstream &arch,char delimitador='\n');
void aumentamosEspacios(void **&alumnos,int &numDat,int &cap);
void cargarNotas(void *al,const char *nombArch);
int buscarAlumno(void **alumnos, int cod);
bool sonIguales(int cod, void *alumno);
void probarLaLectura(void *alumno,const char *nombArch);
void imprimeAlumno(void *al,ofstream &arch);
void ordenarAlumnos(void *al);
void qSort(void **alumnos,int izq,int der);
void cambiar(void *&alumI,void*&alumK);
bool estanEnDesorden(void *alI, void* alK);
#endif /* FUNCIONESAUXILIARES_H */

