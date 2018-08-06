#ifndef __ESTADO_H__
#define __ESTADO_H__
#include <iostream>
#include <string>
#include <vector>
#include "Arista.h"
using namespace std;

class Estado
{
    public:
        string name;
        int cant;
        bool aceptacion;
        vector<Arista *> transiciones;
        Estado(string n);
        void addTransicion(Arista * n);
        Arista * getTransicion(int n);
};
#endif