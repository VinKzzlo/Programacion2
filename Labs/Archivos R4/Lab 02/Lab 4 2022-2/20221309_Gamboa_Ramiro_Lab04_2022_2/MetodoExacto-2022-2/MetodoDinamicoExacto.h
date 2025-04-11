/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Ramiro Gamboa
 * Codigo: 20221309
 * 
 * Created on 8 de abril de 2024, 15:33
 */
#include <fstream>
using namespace std;
#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
//Lectura de Medicos
void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
                      char **&med_Especialidad,double *&med_Tarifa);
char *leeCadenaExacta(ifstream &arch,int max,char delim);
void asignaNombreYEspecialidad(ifstream &archMed,char *nombre,char *&buffEspI);
void cargaArrMedicos(int *&med_Codigo,char **&med_Nombre,
                     char **&med_Especialidad,double *&med_Tarifa,int *buffCod,
                     char **buffNomb,char **buffEsp,double *buffTar,int n);
//Prueba de Lectura de Medicos
void pruebaDeLecturaDeMedicos(const char *nombArch,int *med_Codigo,
                  char **med_Nombre,char **med_Especialidad,double *med_Tarifa);
//Lectura de Citas
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,
                    int **&pac_Citas);
int juntarFecha(int dd,int mm,int aa);
void agregarMedAPac(int *buffDni,int **buffCit,char **buffNomb,int dni,
                    char *nombre,int codMed,int fecha,int *numCit,int &i);
void cargaArrPacientes(int *&pac_Dni,char **&pac_Nombre,int **&pac_Citas,
                  int *buffDni,char **buffNomb,int **buffCit,int *numCit,int n);
void agregarMedicosExactos(int *&pacCitas,int *buffcitas,int cantCit);
//Prueba de Lectura de Citas
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,char **pac_Nombre,
                            int **pac_Citas);
//Reporte de Ingresos Medicos y Gastos de los Pacientes
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
            double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas);
void imprimirEncabezadoMedicos(ofstream &archRep);
void imprimirLinea(ofstream &archRep,char c);
void imprimirTotalDeIngresos(ofstream &archRep,int **pac_Citas,int *pac_Dni,
                             int codMed,double tarifa,double &totIngresado);
void imprimirEncabezadoPacientes(ofstream &archRep);
void imprimirTotalDeGastos(ofstream &archRep,int *arrCitas,int *arrCodMed,
                           double *arrTarifa);

#endif /* METODODINAMICOEXACTO_H */
