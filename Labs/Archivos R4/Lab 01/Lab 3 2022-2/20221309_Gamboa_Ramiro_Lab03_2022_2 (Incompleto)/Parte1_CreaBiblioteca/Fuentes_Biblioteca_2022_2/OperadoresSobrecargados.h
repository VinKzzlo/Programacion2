/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 29 de marzo de 2024, 23:17
 */
#include <fstream>
using namespace std;
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archMed,struct StMedico &med);
bool operator >>(ifstream &archPac,struct StPaciente &pac);
int operator >>(ifstream &archCit,struct StCita &cit);
bool operator <=(struct StCita &cit,struct StMedico *arrMed);
void operator +=(struct StPaciente &pac,const struct StCita cit);
void operator ++(struct StPaciente &pac);
void operator<<(ofstream &archRep, const struct StPaciente pac);
void obtenerFecha(int *fecha, int fechaCompuesta);

#endif /* OPERADORESSOBRECARGADOS_H */
