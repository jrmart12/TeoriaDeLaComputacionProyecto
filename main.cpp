#include "Automata.h"

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
    string **table;
    table = new string*[cantidadEstados];
    for(int a = 0; a<cantidadEstados; a++){
        table[a] = new string[cantidadSimbolos];
    }
    table[0][0] = "-";
}