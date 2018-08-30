#include "leercadena.h"

void leercadena::leerCadenaDeArchivoDFA(Automata *automa,string filename){
    string cadena;
    char * cad;
    ifstream inFile(filename);
    while(inFile>>cadena){
        cad = new char[cadena.length()];
        for(int a = 0; a<cadena.length(); a++){
            cad[a] = cadena.at(a);
        }
        bool cc = automa->checkIfCadenaValidaDFA(cad);
        if(cc){
            cout<<cadena<<" es aceptada"<<endl;
        } else{
            cout<<cadena<<" no es aceptada"<<endl;
        }
    }
    inFile.close();
    for(int a = 0; a<automa->estadosA.size(); a++){
        automa->estadosA.at(a)->transiciones.clear();
    }
}

void leercadena::leerCadenaDeArchivoNFA(Automata *automa,string filename){
    string cadena;
    char * cad;
    ifstream inFile(filename);
    while(inFile>>cadena){
        bool cc = automa->checkIfCadenaValidaNFA(cadena);
        if(cc){
            cout<<cadena<<" es aceptada"<<endl;
            } else{
                cout<<cadena<<" no es aceptada"<<endl;
            }
    }
    inFile.close();
    for(int a = 0; a<automa->estadosA.size(); a++){
        automa->estadosA.at(a)->transiciones.clear();
    }
}