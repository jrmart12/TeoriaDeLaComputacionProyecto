#include "Estado.h"

Estado::Estado(string n){
    name = n;
    cant = 0;
    aceptacion = false;
}

void Estado::addTransicion(Arista * n){
        transiciones.push_back(n);
        cant++;
}

Arista* Estado::getTransicion(int n){
    return transiciones.at(n);
}