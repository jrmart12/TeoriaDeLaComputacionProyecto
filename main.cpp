#include "Automata.h"

using namespace std;

int main(){
    Automata * automa = new Automata(); //instancia de la clase de automata
    cout<<"DFA"<<endl;
    int cantidadEstados; //cantidad de estados
    int cantidadSimbolos; //cantidad de simbolos
    vector<string> simbolosA; // arreglo de vectores de los simbolos del alfabeto
    string s; 
    cout<<"cantidad de estados: ";
    cin>>cantidadEstados;
    cout<<"cantidad de simbolos: ";
    cin>>cantidadSimbolos;
    cout<<"simbolos: ";
    for(int x=0; x<cantidadSimbolos;x++){ //for de 0 a la cantidad de simbolos para meterlo al arreglo de simbolos
        cin>>s;
        simbolosA.push_back(s);
    }
    automa->simbolosPossibles(cantidadSimbolos,simbolosA); //llamo la funcion para agregar mi arreglo al arregle de simbolos del autoamta
    string **table; // instancia de tabla para el print del automata
    table = new string*[cantidadEstados]; //instancia de un apuntador de la tabla a los estados
    for(int a = 0; a<cantidadEstados; a++){ // for para agregar al otro apuntador de la tabla los simbolos
        table[a] = new string[cantidadSimbolos];
    }
    table[0][0] = "-";

    Estado *EstadoNuevo;//instancia para ingresar un estado nuevo al automata

    for(int a = 0; a<cantidadEstados; a++){ //for para poder colocar el estado a la tabla y ingresando el numero del estado asi como ingresandolo a vector de los estados del automata
        table[a][0] = to_string(a-1);
        EstadoNuevo = new Estado(to_string(a-1));
        automa->estadosA.push_back(EstadoNuevo); 
    }

    for(int b = 0; b<cantidadSimbolos; b++){ //for para colocar los simbolos a los estados
        table[0][b] = simbolosA[b-1];
    }
    for(int a = 1; a<=cantidadEstados; a++){ //los for son para colocar el los valore default de cada estado con el simbolo
        for(int b = 1; b<=cantidadSimbolos; b++){
            table[a][b] = "-";
        }
    }
        
    for(int a = 0; a<cantidadEstados+1; a++){
        for(int b = 0; b<cantidadSimbolos+1; b++){
            if(b!=cantidadSimbolos){
                cout<<table[a][b]<<' ';
            } else{
                cout<<table[a][b]<<endl;
            }
                        
        }
    }    



}