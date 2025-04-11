/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de octubre de 2024, 17:13
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos1, *pedidos2, *pedidosfinal;
    
    crealista(pedidos1,leenum,"RegistroNum1.txt");
    imprimelista(pedidos1,imprimenum,"Repnum1.txt");
    crealista(pedidos2,leenum,"RegistroNum2.txt");
    imprimelista(pedidos2,imprimenum,"Repnum2.txt");
    combinalista(pedidos1,pedidos2,pedidosfinal,cmpnum);
    imprimelista(pedidosfinal,imprimenum,"RepnumFInal.txt");
    
    crealista(pedidos1,leeregistro,"Pedidos31.csv");
    imprimelista(pedidos1,imprimeregistro,"Repreg1.txt");
    crealista(pedidos2,leeregistro,"Pedidos32.csv");
    imprimelista(pedidos2,imprimeregistro,"Repreg2.txt");
    combinalista(pedidos1,pedidos2,pedidosfinal,cmpregistro);
    imprimelista(pedidosfinal,imprimeregistro,"RepregFInal.txt");
    return 0;
}

