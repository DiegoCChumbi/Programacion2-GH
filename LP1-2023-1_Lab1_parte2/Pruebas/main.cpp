/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 29 de marzo de 2024, 05:52 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
struct Persona{
    int edad = -1;
};

bool operator +=(struct Persona* arrPersona, struct Persona& per){
    int n = 0;
    while(1){
        cout << arrPersona[n].edad<<endl;
        if(arrPersona[n].edad == -1) break;
        n++;
    }
}

int main(int argc, char** argv) {
    
    struct Persona arrPersonas[5];
    
    arrPersonas[0].edad = 18;
    arrPersonas[1].edad = 22;
    arrPersonas[2].edad = 6;
    arrPersonas[3].edad = -1;
    
    struct Persona p;
    p.edad = 23;
    
    arrPersonas += p;
    
    return 0;
}

