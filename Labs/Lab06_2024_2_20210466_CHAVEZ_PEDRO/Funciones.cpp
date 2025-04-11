
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Funciones.h"
#include "Repartidor.h"
#include "Pedido.h"

void cargarepartidores(Repartidor *r){
    ifstream arch("RepartidoresContratados.csv", ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    int i=0;
    while(1){
        arch>>r[i];
        if(arch.eof())break;                //TODAS LAS CARGAS SE HAN HECHO EN LA CLASE DE PROGRA, SE HACEN SIEMPRE EXACTAMENTE IGUAL ESTO SI O SI VA A ESTAR EN EL LAB
        i++;
    }
}

void  cargaclientes(Cliente *c){
    ifstream arch("Clientes.csv", ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    int i=0;
    while(1){
        arch>>c[i];
        if(arch.eof())break;
        i++;
    }
}

void  cargaplatos(Plato *p){
    ifstream arch("PlatosOfrecidos.csv", ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    int i=0;
    while(1){
        arch>>p[i];
        if(arch.eof())break;
        i++;
    }
}

//12484697,2,AD-546,LAF361
//12484697,1,PO-751,LAF361
//12484697,3,EN-766,LAF361

void actualizar(Repartidor *r, Cliente *c, Plato *p){
    Pedido ped;
    ifstream arch("OrdenesDeCompra.txt", ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    char a[100];
    while(1){
        arch>>ped;
        if(arch.eof())break;
        ped.GetCodigorepartidor(a); //LEES PEDIDOS, UNA SOLA LINEA
        int posRep=buscarepartidor(r, a);
        if(posRep!=-1){
            r[posRep]+=ped;  //AGREGAS EL PEDIDO AL REPARTIDOR EN EL LAB 1 ERA <= NO  CAMBIA NADA, SI TE QUIERES SENTIR SEGURO LE CAMBIAS += por <=
            r[posRep].actualizarDatos(c, p);  //YA QUE EL PEDIDO SOLO TIENE LOS CODIGOS (DNI DEL CLIENTE Y CODIGO DEL PLATO) EN ESTA FUNCION VAS A AGREGAR LOS DATOS RESTANTES 
                                                                    //EN EL ARREGLO DE CLASES DE CLIENTE
        }
    }
    agregartotales(r);  //ACUTALIZAR LOS TOTALES, EL TOTAL POR DISTANCIA RECORRIDA DENTRO DEL LAB 1 Y LS TOTALES QUE PAGA EL CLIENTE POR TODOS LOS PLATOS
}
void agregartotales(Repartidor *r){
    for(int i=0; r[i].GetNumero(); i++)
        !r[i];          //ACTUALIZA LOS TOTALES POR DISTANCIA RECORRIDA NADA MAS FACIL
}

int buscarepartidor(Repartidor *r, char *b){
    char a[10];
    for(int i=0; a; i++){                                                   //ES UN SIMPLE BUSCA
        r[i].GetCodigo(a);
        if(strcmp(a, b)==0)
            return i;
    }
    return -1;
}

void imprimir(Repartidor *r){
    ofstream arch("Reporte.txt", ios::out);
    if(!arch){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    char a[10];
    arch<<setw(40)<<" "<<"ORDENES DE PEDIDOS"<<endl;
    arch<<setw(100)<<setfill('=')<<" "<<setfill(' ')<<endl;
    for(int i=0; r[i].GetNumero(); i++){
        arch>>r[i];
        arch<<setw(100)<<setfill('=')<<" "<<setfill(' ')<<endl;
    }
}