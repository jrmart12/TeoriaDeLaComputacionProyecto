#include "Automata.h"

Automata::Automata(){
    cantidadA = 0; 
    cantidadE=0;
}

void Automata::simbolosPossibles(int cantidad, vector<string> simbolo){
    for(int a=0;a<cantidad;a++){
        simbolos.push_back(simbolo[a]);
    }
}
