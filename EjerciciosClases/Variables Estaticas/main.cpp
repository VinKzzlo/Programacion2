/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 20 de agosto de 2024, 9:39
 */

#include <iostream>
#include <iomanip>
using namespace std;

void f(){
    int local =1;
    static int estatica = 1;
    local++;
    estatica++;
    cout<<"Local = "<<local<<endl;
    cout<<"Estatica = "<<estatica<<endl;
}

void imprimeFecha(int = 1, int = 1, int = 2000);

int main(int argc, char** argv) {
//    for(int i=0;i<5;i++){
//        f();
//    }
    imprimeFecha(21,8,2024);
    imprimeFecha(21,8);
    imprimeFecha(21);
    imprimeFecha();
    return 0;
}

void imprimeFecha(int dd, int mm, int aaaa){
    cout<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'
        <<setw(4)<<aaaa<<setfill(' ')<<endl;
}
