#include "Automata.h"
#include "leercadena.h"
using namespace std;

int main(){
    cout<< "1) DFA\n";
    cout<< "2) NFA\n";
    cout<< "3) NFAe\n";
    int eleccion;
    cin >> eleccion;
    switch (eleccion)
    {
case 1: //DFA
{
    Automata * automa = new Automata(); //instancia de la clase de automata
    int cantidadEstados; //cantidad de estados
    int cantidadSimbolos; //cantidad de simbolos
    vector<string> simbolosA; // arreglo de vectores de los simbolos del alfabeto
    string s; 
    cout<<"cantidad de estados: ";
    cin>>cantidadEstados;
    cout<<"cantidad de simbolos: ";
    cin>>cantidadSimbolos;
    cout<<"simbolos: \n";
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

    for(int a = 0; a<cantidadEstados+1; a++){//for para imprimir la tabla DFA
        for(int b = 0; b<cantidadSimbolos+1; b++){
            if(b!=cantidadSimbolos){
                cout<<table[a][b]<<' ';
            } else{
                cout<<table[a][b]<<endl;
            }                
        }
    }

    //leere el txt con las cadenas para ver si la cadena es aceptada por el dfa
    string filename;
    leercadena *leer = new leercadena();
    cout<<"Ingrese nombre del archivo: ";
    cin>>filename;
    leer->leerCadenaDeArchivoDFA(automa,filename);
    break;
}
    case 2:
    {
    Automata * automa = new Automata(); //instancia de la clase de automata
    int cantidadEstados; //cantidad de estados
    int cantidadSimbolos; //cantidad de simbolos
    vector<string> simbolosA; // arreglo de vectores de los simbolos del alfabeto
    string s; 
    cout<<"cantidad de estados: ";
    cin>>cantidadEstados;
    cout<<"cantidad de simbolos: ";
    cin>>cantidadSimbolos;
    cout<<"simbolos: \n";
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
                
    vector<Arista *> crearEstados; //nuevos estados juntados
    int cantidadTransiciones; //cuantas transiciones hay en la nfs
    string ss;
    int cantEstadosJuntados;  //cuantos estados estan juntados para hacer una arista nueva
    vector<string> estadosJuntos;  //estados juntados para hacer la arista   
    string estadosjuntostable;
    for(int x=0;x<cantidadEstados;x++){ //el estado actual
        for(int y=0;y<cantidadSimbolos;y++){    //el simbolo actual
            cout<<"cuantos estados iria el simbolo "<<simbolosA[y]<<" con el estado "<<to_string(x)<<endl;
            cin>>cantidadTransiciones; //a cuantas ira esa transicion
            cout<<"cuales: \n"; //cuales serian esos estados
            for(int a=0;a<cantidadTransiciones;a++){ //poner los estados juntos
                cin>>ss;
                estadosJuntos.push_back(ss); //juntar los estados para luego hacer un nuevo estado
            }
            for(int a=0;a<estadosJuntos.size();a++){ //for para poder imprimir el nuevo estado   
                estadosjuntostable+=estadosJuntos[a];
            }
            for(int a=0;a<estadosJuntos.size();a++){ //for para crear la nueva arista con los estados ya juntados y con el simbolo en el cual un estado llegara a ellos
                Arista * nuevaArista = new Arista(stoi(estadosJuntos[a]),automa->simbolos.at(y)); //instanciar la arista con la funcion string to int y su simbolo
                automa->getEstado(x)->addTransicion(nuevaArista); //agrego una nueva transicion de ese estado a una nueva arista
                table[x+1][y+1]=estadosjuntostable;  //poner el nuevo estado junto a la table para imprimirla
            }
            if(cantidadTransiciones==1){ //si solo hay una transicion la posicion del estadojuntado es 0 
                Arista * nuevaArista = new Arista(stoi(estadosJuntos[0]),automa->simbolos.at(y)); //creo la nueva arista con el estado juntado en la posicion 0 y el simbolo al que se va a acceder
                automa->getEstado(x)->addTransicion(nuevaArista);    //agarro el estado y le agrego la transicion con la arista
            }else{ //sino busco que el nuevo estado no este en el nfa si es asi exite 
                string nuevoEstado;
                bool existe = false;
                for(int x=0;x<automa->estadosA.size();x++){
                    if(automa->estadosA.at(x)->name==nuevoEstado){
                        existe=true;
                        break;
                    }
                }
                if(existe==false){ //si no existe entonces creo un nuevo estado y lo junto a el arreglo de estados juntados y sumo uno a la cantidad de estadosjuntados
                    Estado * nfaEstado= new Estado(nuevoEstado);
                    automa->estadosJuntadosA.push_back(nfaEstado);
                    cantEstadosJuntados++;
                }
            }
            estadosJuntos.clear(); //clear para pasar a otro estado
            estadosjuntostable.clear(); ///cleear para pasar a otro estado
        }
    }

    for(int a = 0; a<cantidadEstados+1; a++){//for para imprimir la tabla NFA
        for(int b = 0; b<cantidadSimbolos+1; b++){
            if(b!=cantidadSimbolos){
                cout<<table[a][b]<<' ';
            } else{
                cout<<table[a][b]<<endl;
            }                
        }
    }
    //leere el txt con las cadenas para ver si la cadena es aceptada por el nfa
    string filename;
    leercadena *leer = new leercadena();
    cout<<"Ingrese nombre del archivo: ";
    cin>>filename;
    leer->leerCadenaDeArchivoNFA(automa,filename);
    
    //automa->NFAtoDFA(cantidadEstados,cantidadSimbolos);



    break;
    }

    case 3:
    {
Automata * automa = new Automata(); //instancia de la clase de automata
    int cantidadEstados; //cantidad de estados
    int cantidadSimbolos; //cantidad de simbolos
    vector<string> simbolosA; // arreglo de vectores de los simbolos del alfabeto
    string s; 
    cout<<"cantidad de estados: ";
    cin>>cantidadEstados;
    cout<<"cantidad de simbolos: ";
    cin>>cantidadSimbolos;
    cout<<"simbolos: \n";
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
                
    vector<Arista *> crearEstados; //nuevos estados juntados
    int cantidadTransiciones; //cuantas transiciones hay en la nfs
    string ss;
    int cantEstadosJuntados;  //cuantos estados estan juntados para hacer una arista nueva
    vector<string> estadosJuntos;  //estados juntados para hacer la arista   
    string estadosjuntostable;
    for(int x=0;x<cantidadEstados;x++){ //el estado actual
        for(int y=0;y<cantidadSimbolos;y++){    //el simbolo actual
            cout<<"cuantos estados iria el simbolo "<<simbolosA[y]<<" con el estado "<<to_string(x)<<endl;
            cin>>cantidadTransiciones; //a cuantas ira esa transicion
            cout<<"cuales: \n"; //cuales serian esos estados
            for(int a=0;a<cantidadTransiciones;a++){ //poner los estados juntos
                cin>>ss;
                estadosJuntos.push_back(ss); //juntar los estados para luego hacer un nuevo estado
            }
            for(int a=0;a<estadosJuntos.size();a++){ //for para poder imprimir el nuevo estado   
                estadosjuntostable+=estadosJuntos[a];
            }
            for(int a=0;a<estadosJuntos.size();a++){ //for para crear la nueva arista con los estados ya juntados y con el simbolo en el cual un estado llegara a ellos
                Arista * nuevaArista = new Arista(stoi(estadosJuntos[a]),automa->simbolos.at(y)); //instanciar la arista con la funcion string to int y su simbolo
                automa->getEstado(x)->addTransicion(nuevaArista); //agrego una nueva transicion de ese estado a una nueva arista
                table[x+1][y+1]=estadosjuntostable;  //poner el nuevo estado junto a la table para imprimirla
            }
            if(cantidadTransiciones==1){ //si solo hay una transicion la posicion del estadojuntado es 0 
                Arista * nuevaArista = new Arista(stoi(estadosJuntos[0]),automa->simbolos.at(y)); //creo la nueva arista con el estado juntado en la posicion 0 y el simbolo al que se va a acceder
                automa->getEstado(x)->addTransicion(nuevaArista);    //agarro el estado y le agrego la transicion con la arista
            }else{ //sino busco que el nuevo estado no este en el nfa si es asi exite 
                string nuevoEstado;
                bool existe = false;
                for(int x=0;x<automa->estadosA.size();x++){
                    if(automa->estadosA.at(x)->name==nuevoEstado){
                        existe=true;
                        break;
                    }
                }
                if(existe==false){ //si no existe entonces creo un nuevo estado y lo junto a el arreglo de estados juntados y sumo uno a la cantidad de estadosjuntados
                    Estado * nfaEstado= new Estado(nuevoEstado);
                    automa->estadosJuntadosA.push_back(nfaEstado);
                    cantEstadosJuntados++;
                }
            }
            estadosJuntos.clear(); //clear para pasar a otro estado
            estadosjuntostable.clear(); ///cleear para pasar a otro estado
        }
    }

    for(int a = 0; a<cantidadEstados+1; a++){//for para imprimir la tabla NFAe
        for(int b = 0; b<cantidadSimbolos+1; b++){
            if(b!=cantidadSimbolos){
                cout<<table[a][b]<<' ';
            } else{
                cout<<table[a][b]<<endl;
            }                
        }
    }
    //leere el txt con las cadenas para ver si la cadena es aceptada por el nfae
    string filename;
    leercadena *leer = new leercadena();
    cout<<"Ingrese nombre del archivo: ";
    cin>>filename;
    leer->leerCadenaDeArchivoNFAe(automa,filename);        

    break;
    }

}    

}