/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 4 de abril de 2024, 08:53
 */
#include <fstream>
using namespace std;
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archCur,struct StCurso &cur);
bool operator >>(ifstream &archAlum,struct StAlumno &alum);
bool operator >>(ifstream &archMat,struct StRegistroDeMatricula &matri);
void operator +=(struct StCurso *arrCur,const struct StCurso &cur);
void operator +=(struct StAlumno *arrAlum,const struct StAlumno &alum);
void operator *=(struct StCurso *arrCur,
                 const struct StRegistroDeMatricula matri);
void operator *=(struct StAlumno *arrAlum,
                 const struct StRegistroDeMatricula matri);
void operator <<(ofstream &archRepCur,const struct StCurso cur);
void operator <<(ofstream &archRepAlum,const struct StAlumno alum);

#endif /* OPERADORESSOBRECARGADOS_H */
