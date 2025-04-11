/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  4 de octubre de 2024, 0:08
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>
#include "FuncionesAuxiliares.h"

enum REG {
    COD, NOM, NOTA, PROM
};
#define INCREMENTO 5

void cargarAlumnos(void*&al, const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void **alumnos, *reg;
    int numDat = 0, cap = 0;
    alumnos = nullptr;
    while (true) {
        reg = leerRegistro(arch);
        if (arch.eof())break;
        if (numDat == cap) aumentamosEspacios(alumnos, numDat, cap);
        alumnos[numDat - 1] = reg;
        numDat++;
    }
    al = alumnos;
}

void *leerRegistro(ifstream &arch) {
    void **registro;
    int *codigo, cod;
    char *nombre;

    arch >> cod;
    if (arch.eof()) return nullptr;
    codigo = new int;
    *codigo = cod;
    arch.get();
    nombre = leeCadena(arch);
    registro = new void*[4] {
    };
    registro[COD] = codigo;
    registro[NOM] = nombre;
    return registro;
}

char*leeCadena(ifstream &arch, char delimitador) {
    char buffer[60], *cad;
    arch.getline(buffer, 60, delimitador);
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void aumentamosEspacios(void **&alumnos, int &numDat, int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (alumnos == nullptr) {
        alumnos = new void*[cap] {
        };
        numDat = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < numDat; i++) {
            aux[i] = alumnos[i];
        }
        delete alumnos;
        alumnos = aux;
    }
}

void cargarNotas(void*al, const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void **alumnos = (void**) al;
    int nd[50]{}, cap[50]{}, cod, pos;
    while (true) {
        arch>>cod;
        if (arch.eof())break;
        arch.get();
        pos = buscarAlumno(cod, alumnos);
        if (pos != -1)
            colocarCurso(arch, alumnos[pos], nd[pos], cap[pos]);
        else while (arch.get() != '\n');
    }
}

int buscarAlumno(int cod, void **alumnos) {
    for (int i = 0; alumnos[i]; i++)
        if (sonIguales(cod, alumnos[i])) return i;
    return -1;

}

bool sonIguales(int cod, void *al) {
    void **alumno = (void**) al;
    int *codigo = (int*) alumno[COD];
    return cod == *codigo;
}

void colocarCurso(ifstream& arch, void *al, int &nd, int &cap) {
    void ** alumno = (void**) al;
    void *cur;
    cur = leerCurso(arch);
    if (nd == cap) incrementarEspacios(alumno[NOTA], nd, cap);
    agregarCurso(cur, alumno[NOTA], nd);
}

void *leerCurso(ifstream &arch) {
    char*codigo;
    int *nota = new int;
    void **registro = new void *[2];
    codigo = leeCadena(arch, ',');
    arch>>*nota;
    registro[0] = codigo;
    registro[1] = nota;
    return registro;
}

void incrementarEspacios(void *&al, int &nd, int &cap) {
    void **aux, **alumno = (void**) al;
    cap += INCREMENTO;
    if (alumno == nullptr) {
        alumno = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = alumno[i];
        delete alumno;
        alumno = aux;
    }
    al = alumno;
}

void agregarCurso(void *cur, void *alNot, int &nd) {
    void **notas = (void**) alNot;
    notas[nd - 1] = cur;
    nd++;
}

void calcularPromedios(void *al) {
    void **alumnos = (void **) al;
    for (int i = 0; alumnos[i]; i++)
        promedioDelAlumno(alumnos[i]);
}

void promedioDelAlumno(void *al) {
    void **alumno = (void **) al;
    if (alumno[NOTA])
        alumno[PROM] = promedio(alumno[NOTA]);
}

void * promedio(void *alNot) {
    void **notas = (void **) alNot;
    int suma = 0, numDat = 0;
    double *prom;
    for (int i = 0; notas[i]; i++) {
        suma += obtenerNota(notas[i]);
        numDat++;
    }
    prom = new double;
    *prom = (double) suma / numDat;
    return prom;
}

int obtenerNota(void *cur) {
    void **curso = (void**) cur;
    int *nota = (int*) curso[1];
    return *nota;
}

void probarLaLectura(void*al, const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    void **alumnos = (void **) al;
    for (int i = 0; alumnos[i]; i++)
        imprimeAlumno(arch, alumnos[i]);
}

void imprimeAlumno(ofstream &arch, void *al) {
    void **alumno = (void **) al;
    int *codigo = (int *) alumno[COD];
    char*nombre = (char*) alumno[NOM];
    double *promedio;
    arch.precision(2);
    arch << fixed;
    arch << right << setw(10) << *codigo << " " << left << nombre << endl;
    if (alumno[NOTA]) {
        imprimirCursos(arch, alumno[NOTA]);
    }
    if (alumno[PROM]) {
        promedio = (double*) alumno[PROM];
        arch << " PROMEDIO = " << setw(10) << *promedio << endl << endl;
    }
}

void imprimirCursos(ofstream &arch, void *alNot) {
    void **notas = (void**) alNot;
    for (int i = 0; notas[i]; i++)
        imprimeCurso(arch, notas[i]);
}

void imprimeCurso(ofstream &arch, void *alNot) {
    void **nota = (void **) alNot;
    char*codCur = (char*) nota[0];
    int*notaCur = (int*) nota[1];
    arch << right << setw(15) << codCur << setw(5) << *notaCur << endl;
}

void ordenarAlumnos(void *al) {
    void **alumnos = (void**) al;
    int numDat = 0;
    for (numDat = 0; alumnos[numDat]; numDat++);
    qSort(alumnos, 0, numDat - 1);
}

void qSort(void **alumnos, int izq, int der) {
    int limite;
    if (izq >= der)return;
    cambiar(alumnos[izq], alumnos[(izq + der) / 2]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (estanEnDesorden(alumnos[i], alumnos[izq]))
            cambiar(alumnos[++limite], alumnos[i]);
    cambiar(alumnos[izq], alumnos[limite]);
    qSort(alumnos, izq, limite - 1);
    qSort(alumnos, limite + 1, der);
}

void cambiar(void *&alumI, void *&alumK) {
    void *aux;
    aux = alumI;
    alumI = alumK;
    alumK = aux;
}

bool estanEnDesorden(void *alI, void *alK) {
    void **alumI = (void**) alI, **alumK = (void**) alK;
    char*nombreI = (char*) alumI[NOM], *nombreK = (char*) alumK[NOM];
    return strcmp(nombreI, nombreK) < 0;
}

void liberarEspacios(void *al) {
    void **alumnos = (void **) al;
    for (int i = 0; alumnos[i]; i++)
        liberarAlumno(alumnos[i]);
    delete alumnos;
}

void liberarAlumno(void *al) {
    void **alumno = (void **) al;
    int* codigo = (int *) alumno[COD];
    char* nombre = (char*) alumno[NOM];
    double *promedio = (double*) alumno[PROM];

    delete codigo;
    delete nombre;
    if (promedio) delete promedio;
    if (alumno[NOTA])liberarNotas(alumno[NOTA]);
    delete alumno;
}

void liberarNotas(void *alNotas) {
    void **notas = (void**) alNotas;
    for (int i = 0; notas[i]; i++)
        liberarCurso(notas[i]);
    delete notas;
}

void liberarCurso(void *alNot) {
    void **curso = (void **) alNot;
    char* codigo = (char*) curso[0];
    int* nota = (int*) curso[1];
    delete codigo;
    delete nota;
    delete curso;
}
