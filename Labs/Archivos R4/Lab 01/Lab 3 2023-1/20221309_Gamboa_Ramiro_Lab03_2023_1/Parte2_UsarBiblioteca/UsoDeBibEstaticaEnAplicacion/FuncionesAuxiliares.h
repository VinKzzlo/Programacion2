/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 30 de marzo de 2024, 20:34
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerCursos(struct StCurso *arrCur,const char *nombArch);
void leerAlumnos(struct StAlumno *arrAlum,const char *nombArch);
void leerMatricula(struct StCurso *arrCur,struct StAlumno *arrAlum,
                   const char *nombArch);
void calcularIngresosYCostos(struct StCurso *arrCur,struct StAlumno *arrAlum,
                             const char *nombArch);
void leerEscalas(double *arrCostoXCred,const char *nombArch);
int buscarEscalaDelAlumno(struct StAlumno *arrAlum,int codAlum);
double buscarCreditoDelCurso(struct StCurso *arrCur,char *codCurso);
void imprimirReporte(struct StCurso *arrCur,struct StAlumno *arrAlum,
                     const char *nombArch);

#endif /* FUNCIONESAUXILIARES_H */
