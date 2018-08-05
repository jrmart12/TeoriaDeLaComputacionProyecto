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
        vector<Estado*> estadosA;
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
        bool checkIfCadenaValida(char cadena[]);
};