#include "Automata.h"

Automata::Automata()
{
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

Estado *Automata::getEstado(int posicion){
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

bool Automata::checkIfCadenaValidaDFA(char cadena[]){
    Estado* temporal=inicial;
    for(int x=0;x<strlen(cadena);x++){
        for(int y=0;y<simbolos.size();y++){
            stringstream s;
            string siguiente;
            char current=cadena[x];
            s<<current;
            s>>siguiente;
            if(temporal->getTransicion(y)->simbolo==siguiente){
                temporal=getEstado(temporal->getTransicion(y)->estado);
            }
        }
    }
    int size = aceptacion.size();
    for(int a = 0; a<size; a++){
        if(aceptacion.at(a)->name == temporal->name)
            return true;
        }
        return false;    
}

bool Automata::checkIfCadenaValidaNFA(string cadena){
    Estado *temp=inicial;
    if(nfa(temp,inicial->transiciones,cadena,0)==0){
        return true;
    }else{
        return false;
    }
}

int Automata::nfa(Estado *temp,vector<Arista*> transiciionesArreglo,string cadena,int cantidad){
    int cont=0;
    if(cantidad==cadena.size()){
        if(temp->aceptacion){
            return 0;
        }else
            return 1;
    }
    for(cont=0;cont<transiciionesArreglo.size();cont++){
        int x=-1;
        Arista *temporalArreglo=transiciionesArreglo.at(cont);
        string es =temporalArreglo->simbolo;
        if(es.at(0)== cadena.at(cantidad)){
            x=nfa(getEstado(temporalArreglo->estado),getEstado(temporalArreglo->estado)->transiciones,cadena,cantidad+1);
            if(x==2){
                continue;
            }else if(x==1){
                continue;
            }else if(x==0){
                return x;
            }
        }
    }
    return 2;
}

int Automata::NFAtoDFA(int cantidadEstados,int cantidadSimbolos){
    vector<string> namesDFA;
    int contador[cantidadSimbolos];
    int numEstados[cantidadSimbolos];
    string nameNFA[cantidadSimbolos];
    bool masTransiciones=false;

    cout<<to_string(cantidadEstados)<<endl;
    cout<<to_string(cantidadSimbolos)<<endl;
    
    for(int x=0;x<cantidadEstados;x++){
        masTransiciones=false;
        for(int y=0;y<cantidadSimbolos;y++){ //inicializador todo en zero
            contador[y]=0;
            nameNFA[y]="";
        }
    cout<<to_string(getEstado(x)->cant)<<endl;
        for(int a=0;a<cantidadSimbolos;a++){
            cout<<"a";
            for(int b=0;b<getEstado(x)->cant;b++){//recorrer los estados
            cout<<"b";
            }
        }
    }
}

bool Automata::checkIfCadenaValidaNFAe(string cadena){
    Estado *temp=inicial;
    if(nfa(temp,inicial->transiciones,cadena,0)==0){
        return true;
    }else{
        return false;
    }
}

int Automata::nfae(Estado *temp,vector<Arista*> transiciionesArreglo,string cadena,int cantidad){
    int cont=0;
    if(cantidad==cadena.size()){
        if(temp->aceptacion){
            return 0;
        }else
            return 1;
    }
    for(cont=0;cont<transiciionesArreglo.size();cont++){
        int x=-1;
        Arista *temporalArreglo=transiciionesArreglo.at(cont);
        string es =temporalArreglo->simbolo;
        if(es.at(0)== cadena.at(cantidad)){
            x=nfa(getEstado(temporalArreglo->estado),getEstado(temporalArreglo->estado)->transiciones,cadena,cantidad+1);
            if(x==2){
                continue;
            }else if(x==1){
                continue;
            }else if(x==0){
                return x;
            }
        }
    }
    return 2;
}



