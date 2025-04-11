/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  19 de septiembre de 2024, 20:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
                        double *&precios){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: El archivo "<<nombArch<<" no se pudo abrir"<<endl;
        exit(1);
    }
    int numDat=0, cap=0, cant;
    double precio;
    char **registro,c;
    productos = nullptr;
    while(true){
        registro = leerRegistro(arch);
        if(arch.eof())break;
        arch>>precio>>c>>cant;
        arch.get();
        if(cap==numDat)
            aumentarCapacidad(productos,stock,precios,numDat,cap);
        agregarProductos(productos,stock,precios,registro,precio,cant,numDat);
    }
    
}

char **leerRegistro(ifstream &arch){
    char **registro, *codigo;
    codigo = leeCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    registro = new char*[2];
    registro[0] = codigo;
    registro[1] = leeCadenaExacta(arch,',');
    return registro;
}

char *leeCadenaExacta(ifstream &arch,char delim){
    char buffer[60], *cadena;
    arch.getline(buffer,60,delim);
    if(arch.eof())return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void aumentarCapacidad(char ***&productos,int *&stock,double *&precios,
                       int &numDat,int &cap){
    char ***auxProd;
    int *auxStock;
    double *auxPrecios;
    cap += INCREMENTO;
    if(productos==nullptr){
        productos = new char **[cap]{};
        stock = new int[cap]{};
        precios = new double[cap]{};
        numDat++;
    }
    else{
        auxProd = new char **[cap]{};
        auxStock = new int[cap]{};
        auxPrecios = new double[cap]{};
        for(int i=0;i<numDat;i++){
            auxProd[i] = productos[i];
            auxStock[i] = stock[i];
            auxPrecios[i] = precios[i];
        }
        delete productos;
        delete stock;
        delete precios;
        productos = auxProd;
        stock = auxStock;
        precios = auxPrecios;
    }
}
void agregarProductos(char ***&productos,int *&stock,double *&precios,
                      char **registro,double precio,int cant,int &numDat){
    productos[numDat-1] = registro;
    stock[numDat-1] = cant;
    precios[numDat-1] = precio;
    numDat++;
}
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
                        double *precios){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: El archivo "<<nombArch<<" no se pudo abrir"<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    char **auxProd;
    arch<<left<<setw(10)<<"CODIGO"<<setw(60)<<"DESCRIPCION"<<setw(8)<<"STOCK"
        <<setw(10)<<"PRECIO"<<endl;
    for (int i = 0;productos[i]; i++) {
        auxProd = productos[i];
        arch<<left<<setw(10)<<auxProd[0]<<setw(60)<<auxProd[1]<<setw(8)<<stock[i]
            <<setw(10)<<precios[i]<<endl;
    }

}

void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos, int ***&dniCantPedidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: El archivo "<<nombArch<<" no se pudo abrir"<<endl;
        exit(1);
    }
    int numDat=0, cap=0, fecha, posFecha, *numPed, *cantPed;
    int *dniCant;
    char *codigo, c;
    fechaPedidos = nullptr;
    while(true){
        codigo = leeCadenaExacta(arch,',');
        if(arch.eof())break;
        dniCant = leeDNIyCant(arch);
        fecha = leeFecha(arch);
        posFecha = buscarFecha(fecha,fechaPedidos);
        if(posFecha==NO_ENCONTRADO){
            if(cap==numDat){
                aumentarCapFecha(fechaPedidos,codigoPedidos,dniCantPedidos,
                                 numPed,cantPed,numDat,cap);
            }
            fechaPedidos[numDat-1] = fecha;
            posFecha = numDat-1;
            numDat++;
        }
        agregarPedido(codigoPedidos[posFecha],dniCantPedidos[posFecha],
                      numPed[posFecha],cantPed[posFecha],dniCant,codigo);
    }
}
int *leeDNIyCant(ifstream &arch){
    int *dniCant = new int[2]{};
    char c;
    arch>>dniCant[0]>>c>>dniCant[1];
    arch.get();
    return dniCant;
}
int leeFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    arch.get();
    return (aa*10000+mm*100+dd);
}
int buscarFecha(int fecha,int *fechaPedidos){
    if(fechaPedidos!=nullptr){
        for(int i=0;fechaPedidos[i];i++)
            if(fecha == fechaPedidos[i]) return i;
    }
    return NO_ENCONTRADO;
}

void aumentarCapFecha(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&cantPed,
                      int &numDat,int &cap){
    cap += INCREMENTO;
    if(fechaPedidos==nullptr){
        fechaPedidos = new int[cap]{};
        codigoPedidos = new char**[cap]{};
        dniCantPedidos = new int**[cap]{};
        numPed = new int[cap]{};
        cantPed = new int[cap]{};
        numDat++;
    }
    else{
        pasarAuxAPuntero(fechaPedidos,codigoPedidos,dniCantPedidos,numPed,
                         cantPed,numDat,cap);
    }
}

void pasarAuxAPuntero(int *&fechaPedidos,char ***&codigoPedidos,
                      int ***&dniCantPedidos,int *&numPed,int *&cantPed,
                      int &numDat,int &cap){
    char ***auxCodPed;
    int *auxFecha, ***auxDniCant,*auxNumPed,*auxCantPed;
    auxFecha = new int[cap]{};
    auxDniCant = new int**[cap]{};
    auxNumPed = new int[cap]{};
    auxCantPed = new int[cap]{};
    auxCodPed = new char**[cap]{};
    for(int i=0;i<numDat;i++){
        auxFecha[i] = fechaPedidos[i];
        auxDniCant[i] = dniCantPedidos[i];
        auxNumPed[i] = numPed[i];
        auxCantPed[i] = cantPed[i];
        auxCodPed[i] = codigoPedidos[i];
    }
    delete fechaPedidos;
    delete dniCantPedidos;
    delete numPed;
    delete cantPed;
    delete codigoPedidos;
    fechaPedidos = auxFecha;
    dniCantPedidos = auxDniCant;
    numPed = auxNumPed;
    cantPed = auxCantPed;
    codigoPedidos = auxCodPed;
}

void agregarPedido(char **&codigoPedidos,int **&dniCantPedidos,
                   int &numPed,int &cantPed,int *dniCant,char *codigo){
    if(numPed==cantPed)
        aumentarCapPed(codigoPedidos,dniCantPedidos,numPed,cantPed);
    codigoPedidos[numPed-1] = codigo;
    dniCantPedidos[numPed-1] = dniCant;
    numPed++;
}
void aumentarCapPed(char **&codigoPedidos,int **&dniCantPedidos,
                   int &numPed,int &cantPed){
    char **auxCodPed;
    int **auxDniCant;
    cantPed+=INCREMENTO;
    if(codigoPedidos==nullptr){
        codigoPedidos = new char *[cantPed]{};
        dniCantPedidos = new int *[cantPed]{};
        numPed++;
    }
    else{
        auxCodPed = new char *[cantPed]{};
        auxDniCant = new int *[cantPed]{};
        for(int i=0;i<numPed;i++){
            auxCodPed[i] = codigoPedidos[i];
            auxDniCant[i] = dniCantPedidos[i];
        }
        delete codigoPedidos;
        delete dniCantPedidos;
        codigoPedidos = auxCodPed;
        dniCantPedidos = auxDniCant;
    }
}
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos, int ***&dniCantPedidos){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: El archivo "<<nombArch<<" no se pudo abrir"<<endl;
        exit(1);
    }
    char **auxCodPed;
    int **auxDniCant,*auxDni;
    for(int i=0;fechaPedidos[i];i++){
        arch<<left<<"Fecha de pedido: "<<right<<setw(10)<<fechaPedidos[i]<<endl;
        auxCodPed = codigoPedidos[i];
        auxDniCant = dniCantPedidos[i];
        for(int j=0;codigoPedidos[j];j++){
            auxDni = auxDniCant[j];
            arch<<left<<setw(10)<<auxCodPed[j]<<right<<setw(10)<<auxDni[0]
                <<setw(5)<<auxDni[1]<<endl;
        }
        arch<<endl;
    }
}