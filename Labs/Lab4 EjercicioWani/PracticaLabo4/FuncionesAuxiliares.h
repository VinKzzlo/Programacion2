/* 
 * Archivo:   FuncionesAuxiliares.h
 * Autor:     VinKzzlo
 *
 * Creado el  4 de octubre de 2024, 0:08
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarAlumnos(void*&alumnos, const char *nombArch);
void probarLaLectura(void*alumnos, const char *nombArch);
void *leerRegistro(ifstream &arch);
char*leeCadena(ifstream &arch, char delimitador = '\n');
void aumentamosEspacios(void *&alumnos, int &numDat, int &cap);
void imprimeAlumno(ofstream &arch, void *al);
int buscarAlumno(int cod, void **alumnos);
bool sonIguales(int cod, void *al);
void colocarCurso(ifstream& arch, void *al, int &nd, int &cap);
void *leerCurso(ifstream &arch);
void incrementarEspacios(void *&al, int &nd, int &cap);
void agregarCurso(void *cur, void *notas, int &nd);
void imprimirCursos(ofstream &arch, void *alNot);
void imprimeCurso(ofstream &arch, void *alNot);
void cargarNotas(void*al, const char *nombArch);
void calcularPromedios(void *alumnos);
void promedioDelAlumno(void *al);
void * promedio(void *al);
int obtenerNota(void *cur);
void ordenarAlumnos(void *alumnos);
void qSort(void **alumnos, int izq, int der);
void cambiar(void *&alumI, void *&alumK);
bool estanEnDesorden(void *alumI, void *alumK);
void liberarEspacios(void *alumnos);
void liberarAlumno(void *al);
void liberarNotas(void *alNotas);
void liberarCurso(void *alNot);


#endif /* FUNCIONESAUXILIARES_H */

