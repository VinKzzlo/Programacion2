/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: ramir
 * 
 * Created on 8 de septiembre de 2024, 11:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
//Lectura
/*
AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
AP-410,ANTICUCHO,12.90,APERITIVO
*/
void operator >>(ifstream &archPla,struct Plato &plato){
    //archPla>>pla;
    char tipo[60];
    
    archPla.getline(plato.codigo,7,',');
    if(archPla.eof()) return;
    archPla.getline(plato.nombre,60,',');
    archPla>>plato.precio;
    archPla.get();
    archPla.getline(tipo,60);
    plato.totalDePedidos = 0;
    plato.totalRecaudado = 0.0;
}
/*
JNV387,Justino Norabuena Virginia Karina,Motocicleta
PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
*/
void operator >>(ifstream &archRpt,struct Repartidor &repar){
    //archRpt>>repar;
    archRpt.getline(repar.codigo,7,',');
    if(archRpt.eof()) return;
    archRpt.getline(repar.nombre,60,',');
    archRpt.getline(repar.tipoDeVehiculo,15);
    repar.pagoPorEntregas = 0.0;
    repar.cantidadDeOrdenes = 0;
}
/*
15290194  BR-283    1    MCE193    11.69
    80694546     BE-987    2    SRY667    1.01
*/
void operator >>(ifstream &archPed,struct Pedido &ped){
    //archPed>>ped;
    archPed>>ped.dniDelCliente;
    if(archPed.eof()) return;
    archPed>>ped.codigoDelPlato>>ped.cantidad
           >>ped.codigoDelRepartidor>>ped.distanciaARecorrer;
    ped.precio = 0.0;
}
//Operaciones
bool operator <=(struct Pedido &ped,struct Plato *arrPlatos){
    //ped<=arrPlatos;
    for(int i=0;strcmp(arrPlatos[i].codigo,"FIN")!=0;i++){
        if(strcmp(arrPlatos[i].codigo,ped.codigoDelPlato)==0){
            ped.precio = arrPlatos[i].precio;
            arrPlatos[i].totalDePedidos++;
            arrPlatos[i].totalRecaudado += arrPlatos[i].precio;
            return true;
        }
    }
    return false;
}

void operator <=(struct Repartidor *arrRepartidores,struct Pedido ped){
    //arrRepartidores<=ped;
    int cantPlatos,cantOrden;
    for(int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++){
        if(strcmp(arrRepartidores[i].codigo,ped.codigoDelRepartidor)==0){
            for(int j=0;j<arrRepartidores[i].cantidadDeOrdenes;j++){
                if(arrRepartidores[i].ordenesDeCompra[j].dniDelCliente
                        ==ped.dniDelCliente){
                    cantPlatos = arrRepartidores[i].ordenesDeCompra[j].
                                 cantidadDePlatos;
                    strcpy(arrRepartidores[i].ordenesDeCompra[j].
                       platosSolicitados[cantPlatos].codigo,ped.codigoDelPlato);
                    arrRepartidores[i].ordenesDeCompra[j].
                          platosSolicitados[cantPlatos].cantidad = ped.cantidad;
                    arrRepartidores[i].ordenesDeCompra[j].
                              platosSolicitados[cantPlatos].precio = ped.precio;
                    arrRepartidores[i].ordenesDeCompra[j].
                            montoPorCobrar += ped.cantidad*ped.precio;
                    arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos++;
                    return;
                }
            }
            cantOrden = arrRepartidores[i].cantidadDeOrdenes;
            arrRepartidores[i].ordenesDeCompra[cantOrden].
                    dniDelCliente = ped.dniDelCliente;
            arrRepartidores[i].ordenesDeCompra[cantOrden].
                    distancia = ped.distanciaARecorrer;
            arrRepartidores[i].ordenesDeCompra[cantOrden].cantidadDePlatos = 0;
            arrRepartidores[i].ordenesDeCompra[cantOrden].montoPorCobrar = 0.0;
            cantPlatos = arrRepartidores[i].ordenesDeCompra[cantOrden].
                                                               cantidadDePlatos;
            strcpy(arrRepartidores[i].ordenesDeCompra[cantOrden].
                       platosSolicitados[cantPlatos].codigo,ped.codigoDelPlato);
            arrRepartidores[i].ordenesDeCompra[cantOrden].
                          platosSolicitados[cantPlatos].cantidad = ped.cantidad;
            arrRepartidores[i].ordenesDeCompra[cantOrden].
                              platosSolicitados[cantPlatos].precio = ped.precio;
            arrRepartidores[i].ordenesDeCompra[cantOrden].
                            montoPorCobrar += ped.cantidad*ped.precio;
            arrRepartidores[i].cantidadDeOrdenes++;
            break;
        }
    }
}

void operator !(struct OrdenDeCompra &ord){
    //!ord;
    if(ord.distancia<8) ord.pagoPorEnvio = 10.5;
    if(ord.distancia>=8 and ord.distancia<12) ord.pagoPorEnvio = 14.8;
    if(ord.distancia>=12 and ord.distancia<20) ord.pagoPorEnvio = 23.6;
    else ord.pagoPorEnvio = 31.7;
}

void operator !(struct Repartidor &repar){
    for(int i=0;i<repar.cantidadDeOrdenes;i++)
        repar.pagoPorEntregas += repar.ordenesDeCompra[i].montoPorCobrar;
}
//Impresion
void operator <<(ofstream &archRep,struct Plato plato){
    archRep<<fixed<<setprecision(2);
    archRep<<left<<setw(10)<<plato.codigo<<setw(60)<<plato.nombre<<right
           <<setw(8)<<plato.precio<<setw(8)<<plato.totalDePedidos<<setw(8)
           <<plato.totalRecaudado<<endl;
}

void operator <<(ofstream &archRep,struct Repartidor repar){
    archRep<<fixed<<setprecision(2);
    archRep<<left<<setw(10)<<repar.codigo<<setw(60)<<repar.nombre<<setw(15)
           <<repar.tipoDeVehiculo<<right<<setw(8)<<repar.pagoPorEntregas<<endl;
    struct OrdenDeCompra orden;
    struct PlatoSolicitado platSoli;
    double total;
    for(int i=0;i<repar.cantidadDeOrdenes;i++){
        orden = repar.ordenesDeCompra[i];
        archRep<<"ORDENES ENTREGADAS:"<<endl;
        archRep<<right<<setw(13)<<orden.dniDelCliente<<setw(7)<<orden.distancia
             <<setw(8)<<orden.montoPorCobrar<<setw(8)<<orden.pagoPorEnvio<<endl;
        archRep<<setw(23)<<"Platos solicitados:"<<endl;
        for(int j=0;j<orden.cantidadDePlatos;j++){
            platSoli = orden.platosSolicitados[j];
            total = platSoli.cantidad*platSoli.precio;
            archRep<<right<<setw(5)<<'-'<<setw(6)<<platSoli.codigo<<setw(8)
                   <<platSoli.precio<<setw(8)<<platSoli.cantidad<<setw(8)
                   <<total<<endl;
        }
    }
}