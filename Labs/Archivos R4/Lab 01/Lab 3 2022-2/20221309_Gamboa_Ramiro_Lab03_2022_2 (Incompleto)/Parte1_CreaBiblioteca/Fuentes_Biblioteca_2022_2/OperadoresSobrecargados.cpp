/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 29 de marzo de 2024, 23:17
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1
//Lectura
/*
codigo             nombre_especialidad      tarifaPoxConsulta
506117         EDGAR_MUNOZ_VERGEL_Urologia       337.03
150928   LUZ_SOFIA_JAUREGUI_BRAVO_Dermatologia   756.45
*/
bool operator >>(ifstream &archMed,struct StMedico &med){
    //archMed>>med;
    archMed>>med.codigo;
    if(archMed.eof()) return false;
    archMed>>med.nombre;
    int i,cont=0;
    //Buscamos la posicion del ultimo '_' y la cantidad de caracteres a agregar
    for(i=strlen(med.nombre);med.nombre[i]!='_';i--,cont++);
    //Guardamos el i porque lo usaremos despues como aux
    int aux = i,j;
    //Copiamos la especialidad (Se supone que med.nombre[i] = '_')
    for(j=0;j<cont;j++,i++)
        med.especialidad[j] = med.nombre[i+1];
    //Agregamos un '\0' a la especialidad para asegurarnos que tenga uno 
    med.especialidad[j] = '\0';
    //Cortamos el nombre hasta donde el ultimo '_' (med.nombre[aux])
    med.nombre[aux] = '\0';
    archMed>>med.tarifaPoxConsulta;
    return true;
}
/*
86988155   Cerna/Cinthia   745522518
90367684   Sinche/Yvonne   783649119
*/
bool operator >>(ifstream &archPac,struct StPaciente &pac){
    //archPac>>pac;
    archPac>>pac.dni;
    if(archPac.eof()) return false;
    archPac>>pac.nombre>>pac.telefono;
    pac.numeroDeCitas = 0;
    pac.totalGastado = 0.0;
    return true;
}
/*
43704548   892133   9/09/2022
36471787   600493   16/01/2023
*/
int operator >>(ifstream &archCit,struct StCita &cit){
    //archCit>>cit;
    int dni,dd,mm,aa;
    char c;
    archCit>>dni;
    if(archCit.eof()) return NO_ENCONTRADO;
    archCit>>cit.codigoDelMedico>>dd>>c>>mm>>c>>aa;
    cit.fecha = aa*10000+mm*100+dd;
    cit.tarifaPorConsulta = 0.0;
    return dni;
}
//Busqueda
bool operator <=(struct StCita &cit,struct StMedico *arrMed){
    //cit<=arrMed
    for(int i=0;arrMed[i].codigo!=0;i++)
        if(arrMed[i].codigo == cit.codigoDelMedico){
            strcpy(cit.especialidad,arrMed[i].especialidad);
            cit.tarifaPorConsulta = arrMed[i].tarifaPoxConsulta;
            return true;
        }
    return false;
}
//Agregacion
void operator +=(struct StPaciente &pac,const struct StCita cit){
    //pac += cit;
    int numCit = pac.numeroDeCitas;
    pac.citas[numCit] = cit;
    pac.numeroDeCitas++;
}
//Gastos
void operator ++(struct StPaciente &pac){
    //++pac;
    for(int i=0;i<pac.numeroDeCitas;i++)
        pac.totalGastado += pac.citas[i].tarifaPorConsulta;
}
//Impresion
void operator<<(ofstream &archRep, const struct StPaciente pac){
    //archRep<<pac;
    archRep<<left<<setprecision(2)<<fixed; //Configuracion base de la salida
    archRep<<setw(30)<<"  DNI"<< setw(30)<<"NOMBRE"<<"TELEFONO"<<endl;
    archRep<<setw(25)<<pac.dni<<setw(35)<<pac.nombre<<pac.telefono<<endl;
    archRep<<"RELACION DE CITAS"<<endl;
    archRep<<setw(5)<<"No."<<setw(15)<<"FECHA"<<setw(20)<<"CODIGO DEL MEDICO"
           <<setw(20)<<"ESPECIALIDAD"<<"TARIFA"<<endl;
    int fecha[3];
    for (int i = 0; pac.citas[i].codigoDelMedico != 0; i++) {
        archRep<<(i + 1)<<')';
        obtenerFecha(fecha,pac.citas[i].fecha);
        archRep<<setfill('0')<<right;
        archRep<<setfill('0')<<right<<setw(2)<<fecha[0]<<'/'<<right<<setw(2)
               <<fecha[1]<<'/'<<setfill(' ')<<left<<setw(17)<<fecha[2];
        archRep<<left<<setprecision(2)<<fixed; //Configuracion base de la salida
        archRep<<setw(15)<<pac.citas[i].codigoDelMedico<<setw(20)
               <<pac.citas[i].especialidad<<pac.citas[i].tarifaPorConsulta<<endl;
    }
    archRep<<"MONTO TOTAL GASTADO: "<<pac.totalGastado<<endl;
}

void obtenerFecha(int *fecha, int fechaCompuesta){
    fecha[0] = fechaCompuesta % 100;
    fecha[1] = ((fechaCompuesta / 100) % 100);
    fecha[2] = fechaCompuesta / 10000;
}