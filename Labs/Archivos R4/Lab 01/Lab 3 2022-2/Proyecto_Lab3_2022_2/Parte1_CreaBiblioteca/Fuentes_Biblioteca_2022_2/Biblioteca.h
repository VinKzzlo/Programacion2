
/* 
 * File:   Biblioteca.h
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 09:39 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

bool operator >> (ifstream &arch,struct StMedico &medico);
void operator <<= (struct StMedico &medico,ifstream &arch);
bool operator >> (ifstream &arch,struct StPaciente &paciente);
int operator >> (ifstream &arch,struct StCita &cita);
bool operator <= (struct StCita &cita,struct StMedico *medicos);
void operator += (struct StPaciente &paciente,const struct StCita &cita);
void operator ++ (struct StPaciente &paciente);
void operator << (ofstream &arch,const struct StPaciente &paciente);
void ImprimirCitasDeUnPaciente(ofstream &arch,const struct StCita *citas,int num);


#endif /* BIBLIOTECA_H */

