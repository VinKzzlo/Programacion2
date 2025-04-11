/* 
 * File:   FuncionesAuxiliares.h
 * Author: ramir
 *
 * Created on 4 de abril de 2024, 22:50
 */
#include <fstream>
using namespace std;
#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
//Parte A
void leerMedicos(struct StMedico *arrMed,const char *nombArch);
//Parte B
void leerPacientes(struct StPaciente *arrPac,const char *nombArch);
//Parte C
void completarCitas(struct StMedico *arrMed,struct StPaciente *arrPac,
                    const char *nombArch);
int buscarPaciente(struct StPaciente *arrPac,int dni);
//Parte D
void imprimirReporte(struct StPaciente *arrPac,const char *nombArch);
void imprimirLinea(ofstream &archRep,char c);
#endif /* FUNCIONESAUXILIARES_H */
