
/* 
 * File:   Funciones.h
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 11:50 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LecturaDeMedicos(struct StMedico *medicos, const char* nomArch);
void LecturaDePacientes(struct StPaciente *pacientes, const char* nomArch);
void ProcesarCitas(struct StMedico *medicos,struct StPaciente *pacientes,
        const char* nomArch);
int BuscarPaciente(struct StPaciente *pacientes,int dni);
void EmitirReporte(struct StPaciente *pacientes, const char* nomArch);
void ImprimirLinea(ofstream &arch,char c,int n);

#endif /* FUNCIONES_H */

