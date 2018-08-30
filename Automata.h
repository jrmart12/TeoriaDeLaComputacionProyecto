#ifndef __AUTOMATA_H__
#define __AUTOMATA_H__
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
#include "Estado.h"


class Automata
{
    public:
        Automata();
        vector<Estado*> estadosA;
        vector<Estado*> estadosJuntadosA;
        Estado * inicial;
        vector<Estado*> aceptacion;
        vector<string> simbolos;
        int cantidadA;
        int cantidadE;
        void simbolosPossibles(int cantidad, vector<string> simbolo);
        void setEstadoInicial(Estado * estadoInicial);
        void setEstadosFinal(vector<Estado*> estadofinal);
        Estado * getEstado(int posicion);
        void printArray();
        void printDFA();
        bool checkIfCadenaValidaDFA(char cadena[]);
        bool checkIfCadenaValidaNFA(string cadena);
        int nfa(Estado *temp,vector<Arista*> transiciionesArreglo,string cadena,int cantidad);
};
#endif