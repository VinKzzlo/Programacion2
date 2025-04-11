
/* 
 * File:   Biblioteca.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de abril de 2024, 09:39 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Estructuras.h"
#include "Biblioteca.h"
#define NO_ENCONTRADO -1
 

bool operator >> (ifstream &arch,struct StMedico &medico){
    arch >> medico.codigo;
    if(arch.eof())return false;
    medico <<= arch;
    arch >> medico.tarifaPoxConsulta;
    return true;
}

void operator <<= (struct StMedico &medico,ifstream &arch){
    char cadena[200];
    arch >> cadena;
    int lon = strlen(cadena),i;
    for(i = lon; cadena[i]!='_';i--);
    strncpy(medico.nombre,cadena,i-1);
    strcpy(medico.especialidad,&cadena[i+1]);
}

bool operator >> (ifstream &arch,struct StPaciente &paciente){
    arch >> paciente.dni;
    if(arch.eof())return false;
    arch >> paciente.nombre >> paciente.telefono;
    paciente.totalGastado = 0.0;
    paciente.numeroDeCitas = 0;
    return true;
}

int operator >> (ifstream &arch,struct StCita &cita){
    int dni;
    arch >> dni;
    if(arch.eof())return -1;
    int dd,mm,aaaa;
    char c;
    arch >> cita.codigoDelMedico >> dd >> c >> mm >> c >> aaaa;
    cita.fecha = dd + 100*mm + 10000*aaaa;
    cita.tarifaPorConsulta = 0.0;
    return dni;
}

bool operator <= (struct StCita &cita,struct StMedico *medicos){
    for(int i=0;medicos[i].codigo;i++)
        if(medicos[i].codigo == cita.codigoDelMedico){
            cita.tarifaPorConsulta = medicos[i].tarifaPoxConsulta;
            strcpy(cita.especialidad,medicos[i].especialidad);
            return true;
        }
    return false;
}

void operator += (struct StPaciente &paciente,const struct StCita &cita){
    int &num =paciente.numeroDeCitas;
    paciente.citas[num] = cita;
    num++;
}

void operator ++ (struct StPaciente &paciente){
    for(int i=0;i<paciente.numeroDeCitas;i++)
        paciente.totalGastado += paciente.citas[i].tarifaPorConsulta;
}

void operator << (ofstream &arch,const struct StPaciente &paciente){
    arch << left<<setw(30)<<"DNI" << setw(30)<<"NOMBRE"<<right
            <<setw(20)<<"TELEFONO"<<endl;
    arch << left<<setw(25)<<paciente.dni << setw(35)<<paciente.nombre<<right
            <<setw(20)<<paciente.telefono<<endl;
    arch << "RELACION DE CITAS"<<endl;
    ImprimirCitasDeUnPaciente(arch,paciente.citas,paciente.numeroDeCitas);
    arch << "MONTO TOTAL GASTADO: "<<paciente.totalGastado<<endl;
}

void ImprimirCitasDeUnPaciente(ofstream &arch,const struct StCita *citas,int num){
    arch << left << setw(6)<<"No." << setw(20)<< "FECHA" <<setw(30) 
            << "CODIGO DEL MEDICO" << setw(20)<<"ESPECIALIDAD"<<right 
            << setw(10)<<"TARIFA"<<endl;
    for(int i=0;i<num;i++) {
        arch << right << setw(3) << i+1<< left<<setw(3)<<')'
                << right <<setfill('0')<<setw(2) << citas[i].fecha%100 <<'/'
                << setw(2)<<(citas[i].fecha/100)%100 << '/'
                << setw(4) << citas[i].fecha/10000 << setfill(' ')
                << left << setw(10) <<' '
                << setw(30)<< citas[i].codigoDelMedico 
                << setw(20) << citas[i].especialidad << right
                << setw(10) << citas[i].tarifaPorConsulta << endl;
    }
}



