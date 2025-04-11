/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
/*
 * nombre: Jefferson Robles Cervantes
 * codigo: 20185878
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "metodoExacto.h"
using namespace std;

void leerLibros(const char*nombreArch,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombreArch);
    char car,*codLibro,*titulo,*autor,**bufferLibros[300]{};
    int *bufferStock[300]{};
    int cant,numDat=0;
    double precio;
    while(true){
        codLibro=leercadena(arch);
        if(arch.eof())break;
        titulo=leercadena(arch);
        autor=leercadena(arch);
        arch>>cant>>car>>precio;
        arch.get();
        asignarEspacioGuardarDatos(bufferLibros,bufferStock,numDat,codLibro,titulo,autor,cant);
        numDat++;
    }
    //asignar memoria
    libros=new char**[numDat+1]{};
    stock=new int*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        libros[i]=bufferLibros[i];
        stock[i]=bufferStock[i];
    }
}

char *leercadena(ifstream &arch){
    char *cad,cadena[100];
    arch.getline(cadena,100,',');
    cad=new char [strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
            
}

void asignarEspacioGuardarDatos(char ***bufferLibros,int **bufferStock,int numDat,char *codLibro,char *titulo,char *autor,int cant){
    bufferLibros[numDat]=new char*[3]{};
    bufferStock[numDat]=new int [2]{};
    char **auxLibros;
    int *auxstock;
    auxLibros=bufferLibros[numDat];
    auxLibros[0]=codLibro;
    auxLibros[1]=titulo;
    auxLibros[2]=autor;
    auxstock=bufferStock[numDat];
    auxstock[0]=cant;
    auxstock[1]=0;
}

void pruebaLecturaLibros(const char*nombreArch,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombreArch);
    arch<<"DATOS LIBROS"<<endl;
    arch<<"CODIGO"<<"TITULO"<<"AUTOR"<<"CANTIDAD"<<"CANTIDAD NO ATENDIDA"<<endl;
    for(int i=0;libros[i];i++){
        char **auxLibros;
        int *auxstock;
        auxLibros=libros[i];
        auxstock=stock[i];
        arch<<left<<setw(10)<<auxLibros[0]<<setw(60)<<auxLibros[1]<<setw(30)<<auxLibros[2]<<right<<setw(5)<<auxstock[0]<<setw(5)<<auxstock[1]<<endl;
    }
}

void leerPedidos(const char*nombreArch,char ***libros,int **&stock,int **&PedidosClientes,char ***&PedidosLibros,bool **&PedidoEstado){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombreArch);
    //variables
    int codPedido,dniCliente,posCliente,numDat=0,cantPedidos=0,cantLibros[150]{};
    char codLibro[8];
    //buffers
    int *bufferPedCli[150]{};
    char **bufferPedLibros[150]{};
    bool *bufferEstado[150]{};
    while(true){
        arch>>codPedido;
        if(arch.eof())break;
        arch.get();
        arch>>dniCliente;
        arch.get();
        posCliente=buscarCliente(dniCliente,bufferPedCli,numDat);
        agregarOActualizarClientes(bufferPedCli,dniCliente,codPedido,posCliente,numDat);
        bufferPedLibros[codPedido-1]=new char*[150]{};
        bufferEstado[codPedido-1]=new bool[150]{};
        int cantidadLibros=0;
        char **auxPedLibros=bufferPedLibros[codPedido-1];
        int posLibro;
        while(true){
            if(arch.get()=='\n')break;
            arch>>codLibro;
            auxPedLibros[cantidadLibros]=new char [strlen(codLibro)+1];
            strcpy(auxPedLibros[cantidadLibros],codLibro);
            posLibro=buscarLibro(libros,codLibro);
            actualizarStockYEstado(posLibro,stock,bufferEstado,cantidadLibros,codPedido);
            cantidadLibros++;
        }
        cantLibros[codPedido-1]=cantidadLibros;
        cantPedidos++;
    }
    asignarMemoriaYGuardatosPedClientesLibrosEstado(PedidosClientes,PedidosLibros,PedidoEstado,bufferPedCli,bufferPedLibros,bufferEstado,numDat,cantPedidos,cantLibros);
}

int buscarCliente(int dniCliente,int **bufferPedCli,int numDat){
    for(int i=0;i<numDat;i++){
        int *auxPedCliente;
        auxPedCliente=bufferPedCli[i];
        if(auxPedCliente[0]==dniCliente)
            return i;
    }
    return -1;
}

int buscarLibro(char ***libros,char *codLibro){
    for(int i=0;libros[i];i++){
        char **auxLibros;
        auxLibros=libros[i];
        if(strcmp(auxLibros[0],codLibro)==0)return i;
    }
    return -1;
}

void agregarOActualizarClientes(int **bufferPedCli,int dniCliente,int codPedido,int posCliente,int &numDat){
    int *auxPedCli;
    if(posCliente==-1){
        posCliente=numDat;
        bufferPedCli[posCliente]=new int [50]{};    
        auxPedCli=bufferPedCli[numDat];
        auxPedCli[0]=dniCliente;
        auxPedCli[1]=0;
        numDat++;
    }
    auxPedCli=bufferPedCli[posCliente];
    int cant=auxPedCli[1];
    auxPedCli[cant+2]=codPedido;
    auxPedCli[1]=auxPedCli[1]+1;
}

void actualizarStockYEstado(int posLibro,int **&stock,bool **bufferEstado,int cantidadLibros,int codPedido){
    int *auxStock;
    bool *auxEstados;
    auxStock=stock[posLibro];
    auxEstados=bufferEstado[codPedido-1];
    if(auxStock[0]>0){
       auxStock[0]--;
       auxEstados[cantidadLibros]=true;
    }
    else{
        auxStock[1]++;
        auxEstados[cantidadLibros]=false;
    }
}

void asignarMemoriaYGuardatosPedClientesLibrosEstado(int **&PedidosClientes,char ***&PedidosLibros,bool **&PedidoEstado,int **bufferPedCli,char ***bufferPedLibros,bool **bufferEstado,int numDat,int cantPedidos,int *cantLibros){
    PedidosClientes= new int *[numDat+1]{};
    PedidosLibros= new char**[cantPedidos+1]{};
    PedidoEstado=new bool *[cantPedidos+1]{};
    for(int i=0;i<numDat;i++){
        PedidosClientes[i]=bufferPedCli[i];
    }
    for(int i=0;i<cantPedidos;i++){
        char **auxPedLibrosDestino,**auxPedLibrosOrigen;
        bool *auxEstadoDestino,*auxEstadoOrigen;
        auxPedLibrosOrigen=bufferPedLibros[i];
        auxPedLibrosDestino=new char*[cantLibros[i]+1]{};
        auxEstadoOrigen=bufferEstado[i];
        auxEstadoDestino=new bool[cantLibros[i]+1]{};
        for(int j=0;j<cantLibros[i];j++){
            auxPedLibrosDestino[j]=auxPedLibrosOrigen[j];
            //cout<<auxPedLibrosDestino[j]<<endl;
            auxEstadoDestino[j]=auxEstadoOrigen[j];
        }
        PedidosLibros[i]=auxPedLibrosDestino;
        PedidoEstado[i]=auxEstadoDestino;
    }
}

void imprimirReporte(const char*nombreArch,char ***libros,int **stock,int **PedidosClientes,char ***PedidosLibros,bool **PedidoEstado){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombreArch);
    arch<<"REPORTE"<<endl;
    int *auxPedCli;
    char **auxPedidosLibros;
    bool *auxPedidoEstado;
    for(int i=0;PedidosClientes[i];i++){
        auxPedCli=PedidosClientes[i];
        imprimirLinea(arch,'=',100);
        arch<<"DNI cliente: "<<auxPedCli[0]<<setw(25)<<"Cantidad de Pedidos:"<<auxPedCli[1]<<endl;
        imprimirLinea(arch,'=',100);
        for(int j=2;j<auxPedCli[1]+2;j++){
            arch<<"Codigo de Pedido: "<<setw(3)<<" "<<setfill('0')<<setw(6)<<auxPedCli[j]<<setfill(' ')<<endl;
            imprimirLinea(arch,'-',100);
            auxPedidosLibros=PedidosLibros[auxPedCli[j]-1];
            auxPedidoEstado=PedidoEstado[auxPedCli[j]-1];
            arch<<setw(11)<<"Codigo"<<setw(15)<<"Estado"<<endl;
            imprimirLinea(arch,'-',100);
            for(int k=0;auxPedidosLibros[k];k++){
                arch<<k+1<<")"<<setw(10)<<auxPedidosLibros[k]<<" ";
                if(auxPedidoEstado[k]==true){
                    arch<<setw(15)<<"ATENDIDO"<<endl;
                }
                else{
                    arch<<setw(18)<<"NO ATENDIDO"<<endl;
                }
            }
            imprimirLinea(arch,'-',100);
        }
    }
}

void imprimirLinea(ofstream &arch,char car,int limite){
    for(int i=0;i<limite;i++)
        arch<<car;
    arch<<endl;
}