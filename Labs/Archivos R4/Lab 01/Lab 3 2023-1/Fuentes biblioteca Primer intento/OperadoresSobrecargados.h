/* 
 * File:   OperadoresSobrecargados.h
 * Author: ramir
 *
 * Created on 25 de marzo de 2024, 23:07
 */
#include <fstream>
using namespace std;
#include "Estructuras.h"
#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &archCur,StCurso &cur);
bool operator >>(ifstream &archAlum,StAlumno &alum);
bool operator >>(ifstream archMat,StRegistroDeMatricula &matri);
void operator +=(StCurso *arrCur,const struct StCurso cur);
void operator +=(StAlumno *arrAlum,const struct StAlumno alum);
void operator *=(StCurso *arrCur,const struct StRegistroDeMatricula matri);
void operator *=(StAlumno *arrAlum,const struct StRegistroDeMatricula matri);
void operator <<(ofstream &archRepCur,const struct StCurso cur);
void operator <<(ofstream &archRepAlum,const struct StAlumno alum);

#endif /* OPERADORESSOBRECARGADOS_H */
