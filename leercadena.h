#ifndef __fileH__
#define __file_H__
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
#include "Automata.h"

class leercadena
{
    public:
    void leerCadenaDeArchivoDFA(Automata *automa,string filename);
    void leerCadenaDeArchivoNFA(Automata *automa,string filename);
    void leerCadenaDeArchivoNFAe(Automata *automa,string filename);
};
#endif