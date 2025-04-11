/* 
 * Archivo:   main.cpp
 * Autor:     VinKzzlo
 *
 * Creado el  24 de septiembre de 2024, 8:22
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplica(int a, int b) {
    return a*b;
}

int divide(int a, int b) {
    return a / b;
}
int calcula(int x, int y){
    return x*x - y;
}

int operacion(int a, int b, int(*funcion)(int, int)){
    int q;
    q = funcion(a,b);
    return q;
}
int main(int argc, char** argv) {
    int a = 6, b = 5, c;
//    int (*pt) (int, int);
//
//    pt = multiplica;
//    cout << "C = " << pt(a, b) << endl;
//
//    pt = resta;
//    cout << "C = " << pt(a, b) << endl;
//
//    int(*arr[4])(int, int);
//    arr[0] = suma;
//    arr[1] = resta;
//    arr[2] = multiplica;
//    arr[3] = divide;
//    for (int i = 0; i<4; i++) {
//        cout << "El resultado es: "<<arr[i](a,b)<<endl;
//    }
    cout << "C = " << operacion (a,b,calcula)<< endl;
    
    return 0;
}

