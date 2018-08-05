#include <iostream>
#include <string>
#include "Estado.h"
using namespace std;

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
        bool checkIfCadenaValidaDFA(char cadena[]);
};