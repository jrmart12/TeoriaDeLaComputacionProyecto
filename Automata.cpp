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

void Automata::setEstadoInicial(Estado * estadoInicial){
    inicial=estadoInicial;
}

void Automata::setEstadosFinal(vector <Estado*> estadoFinal){
    int s =estadoFinal.size();
    for(int a=0;a<s;a++){
        aceptacion.push_back(estadoFinal[a]);
    }
    for(int x=0;x<s;x++){
        estadoFinal.at(x)->aceptacion=true;
    }
}

Estado* Automata::getEstado(int posicion){
    return estadosA.at(posicion);
}

void Automata::printArray(){
    cout<<"Estados"<<endl;
    for(int a = 0; a<estadosA.size(); a++){
        cout<<estadosA.at(a)->name<<endl;
    }
}

void Automata::printDFA(){
    int cantidad= estadosA.size();
    for(int a=0;a<cantidad;a++){
        cout<<getEstado(a)->name+" tiene transiciones a: ";
        for(int x=0;x<getEstado(a)->cant;x++){
            cout<<getEstado(a)->getTransicion(x)->estado;
            cout<<"con";
            cout<<getEstado(a)->getTransicion(x)->simbolo;
            if(x!= (getEstado(a)->cant-1)){
                cout<<"--";
            }
        }
        cout<<""<<endl;
    }
}

bool Automata::checkIfCadenaValida(char cadena[]){
    int a = strlen(cadena);
    int b= simbolos.size();
    Estado* temporal=inicial;

    

}
