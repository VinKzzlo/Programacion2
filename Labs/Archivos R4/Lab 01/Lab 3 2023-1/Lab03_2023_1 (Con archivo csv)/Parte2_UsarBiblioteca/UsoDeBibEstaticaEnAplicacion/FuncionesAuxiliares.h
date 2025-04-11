/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 4 de abril de 2024, 14:51
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

//Parte A
void leerCursos(struct StCurso *arrCur,const char *nombArch);
//Parte B
void leerAlumnos(struct StAlumno *arrAlum,const char *nombArch);
//Parte C
void completarCursosYAlumnos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch);
//Parte D
void calcularIngresosYCostos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch);
void leerEscalas(double *arrCostoXEsc,const char *nombArch);
int buscarEscalaDelAlumno(int codAlum,struct StAlumno *arrAlum);
double buscarCredDelCurso(char *codCurso,struct StCurso *arrCur);
//Parte E
void imprimirReporte(struct StCurso *arrCur,struct StAlumno *arrAlum,
                     const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */
