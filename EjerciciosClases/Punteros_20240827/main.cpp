/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Archivo:   main.cpp
 * Autor: VinKzzlo
 *
 * Creado el on 27 de agosto de 2024, 8:33
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a[50];
    int *p;
    p = new int[100];
    
    cout<<"A - "<<sizeof(a)<<endl;
    cout<<"P - "<<sizeof(*p)<<endl;
    
    p=a;
    p[3]=54;
    
    
    return 0;
}

