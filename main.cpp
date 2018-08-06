#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "Arista.h"
#include "Automata.h"
#include "Estado.h"

using namespace std;

int main(){
    Automata * automa = new Automata();
    cout<<"DFA"<<endl;
    int cantidadEstados;
    int cantidadSimbolos;
    vector<string> simbolosA;
    string s;
    cout<<"cantidad de estados: ";
    cin>>cantidadEstados;
    cout<<"cantidad de simbolos: ";
    cin>>cantidadSimbolos;
    cout<<"simbolos: ";
    for(int x=0; x<cantidadSimbolos;x++){
        cin>>s;
        simbolosA.push_back(s);
    }
    automa->simbolosPossibles(cantidadSimbolos,simbolosA);
}