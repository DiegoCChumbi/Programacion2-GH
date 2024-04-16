/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void lecturaDeLibros(const char* nombre,char***& libros,int**& stock){
    
    int cant = 0, capacidad = 0;
    char** datosLibro;
    int* infStock;
    libros = nullptr;
    stock = nullptr;
    double d;
   
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);
    
    while(1){
        arch >> ws;
        if(arch.eof()) break;
        datosLibro = leerStrings(arch);
        infStock = leerInt(arch);
        arch >> d;
        if(cant == capacidad)incrementoMemoria(libros,stock,capacidad,cant);
        libros[cant-1] = datosLibro;
        stock[cant-1] = infStock;
        cant++;
    }
}

char** leerStrings(ifstream& arch){
    
    char codigo[60]{};
    char nombre[150]{};
    char autor[100]{};
    arch.getline(codigo,60,',');
    arch.getline(nombre,150,',');
    arch.getline(autor,100,',');
    char** resultado = new char*[3];
    resultado[0] = new char[strlen(codigo)+1]{};
    resultado[1] = new char[strlen(nombre)+1]{};
    resultado[2] = new char[strlen(autor)+1]{};
    strcpy(resultado[0],codigo);
    strcpy(resultado[1],nombre);
    strcpy(resultado[2],autor);
    
    return resultado;
}

int* leerInt(ifstream& arch){
    int* resultado = new int[2]{};
    arch >> resultado[0];
    arch.get();
    return resultado;
}

void incrementoMemoria(char***& libros,int**& stock,int& capacidad,int& cant){
    
    capacidad += AUMENTO;

    if(libros == nullptr){
        
        libros = new char**[capacidad];
        stock = new int*[capacidad];
        cant = 1;
        
    }else{
        
        char*** auxLibros = new char**[capacidad]{};
        int** auxStock = new int*[capacidad]{};
        
        for(int n = 0; libros[n];n++) auxLibros[n] = libros[n];
        for(int n = 0; stock[n];n++) auxStock[n] = stock[n];
        
        delete libros;
        delete stock;
        
        libros = auxLibros;
        stock = auxStock;
        
    }

}

void pruebaDeLecturaDeLibros(const char* nombre,char*** libros,int** stock){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre);
    
    for(int n = 0; libros[n];n++){
        char** auxLib = libros[n];
        int* auxSt = stock[n];
        arch << left <<setw(10) << auxLib[0] << setw(80) << auxLib[1] << setw(30) << auxLib[2] << setw(5) << auxSt[0] << setw(5) << auxSt[1] << endl;
    }
    
}