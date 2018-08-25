#include "Automata.h"

using namespace std;

int main(){
    Automata * automa = new Automata(); //instancia de la clase de automata
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

    table = new string*[cantidadEstados+1]; //instancia de un apuntador de la tabla a los estados

    for(int a = 0; a<cantidadEstados+1; a++){ // for para agregar al otro apuntador de la tabla los simbolos
        table[a] = new string[cantidadSimbolos+1];
    }
    table[0][0] = "*";

    Estado *EstadoNuevo;//instancia para ingresar un estado nuevo al automata

    for(int a = 1; a<cantidadEstados+1; a++){ //for para poder colocar el estado a la tabla y ingresando el numero del estado asi como ingresandolo a vector de los estados del automata
        table[a][0] = to_string(a-1);
        EstadoNuevo = new Estado(to_string(a-1));
        automa->estadosA.push_back(EstadoNuevo); 
    }

    for(int b = 1; b<cantidadSimbolos+1; b++){ //for para colocar los simbolos a los estados
        table[0][b] = simbolosA[b-1];
    }
    for(int a = 1; a<=cantidadEstados; a++){ //los for son para colocar el los valore default de cada estado con el simbolo
        for(int b = 1; b<=cantidadSimbolos; b++){
            table[a][b] = "*";
        }
    }
    
    for(int a = 0; a<cantidadEstados+1; a++){ //for para la impresion de la tabla del automata
        for(int b = 0; b<cantidadSimbolos+1; b++){
            if(b!=cantidadSimbolos){
                cout<<table[a][b]<<' ';
            } else{
                cout<<table[a][b]<<endl;
            }
                        
        }
    }  

    int estadoInicial;
    int cantidadEstadoFinal;  
    vector<Estado *> estadoFinal;

    //Estado Inicial
    cout<<"Estado Inicial:";
    cin>>estadoInicial; //agarrar el estado inicial del usuario
    Estado * inicial = automa->getEstado(estadoInicial); //agarro el estado inicial y se lo agrego a una variable
    automa->setEstadoInicial(inicial); //seteo el estado del usuario final al automata

    //Estado Final
    cout<<"Cantidad de Estado Finales: ";
    cin>>cantidadEstadoFinal; //agarrar la cantidad estado final del usuario
    cout<<"Estado Finales: ";
    int temporal;
    for(int cont=0;cont<cantidadEstadoFinal;cont++){ //for para agregar los estados finales al vector finales
        cin>>temporal;
        Estado * finales= automa->getEstado(temporal);
        estadoFinal.push_back(finales);
    }
    automa->setEstadosFinal(estadoFinal);

    //DFA
    vector<int> EstadoSiguiente; //vector de estado siguiente
    int estadoDFA; 
    for (int a=1; a<=cantidadEstados;a++){
        for(int b=1;b<=cantidadSimbolos;b++){
            cout<<"Estado "<<to_string(a-1)<<"con simbolo "<<simbolosA[b-1]<<"va hacia que Estado?";
            cin>>estadoDFA;
            Arista *estadoArista= new Arista(estadoDFA,simbolosA[b-1]); //hago una arista con el estado y el simbolo para llegar a ella
            automa->getEstado(a-1)->addTransicion(estadoArista); //agrego la transicion a un estado con el simbolo
            table[a][b] = to_string(estadoDFA);//para cada estado con el simbolo puede llegar a que estado tabla
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