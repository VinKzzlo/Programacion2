
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Restaurante.h"

using namespace std;

int main(int argc, char** argv) {
    Restaurante res;
    string linea;
    ifstream arch("lineaBusqueda.txt", ios::in);
    getline(arch, linea);
    
    res.carga();
    res.cargaPlato(linea);
    res.actualiza(3);
    res.muestra();  
    
    return 0;
}

