/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoPorIncrementosVoid.hpp
 * Author: user
 *
 * Created on 23 de abril de 2024, 02:39 PM
 */

#ifndef METODOPORINCREMENTOSVOID_HPP
#define METODOPORINCREMENTOSVOID_HPP

#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"

#define INCREMENTO 5

using namespace std;

enum lib {
    CODIGO,
    TITULO,
    AUTOR,
    STOCKV,
};

enum st {
    STOCK,
    NOATEN,
};

enum cli {
    DNI,
    CANTPEDIDOS,
};

void lecturaDeLibros(const char* nombre,void*& libros);
void reservaMemoria(void**& arrLibros,int& cant,int& cap);
//void leerString(ifstream& arch,void**& arrLibros,int cant);
//void leerNumeros(ifstream& arch,void**& arrLibros,int cant);
void* leeLibro(ifstream& arch);
char* leerStr(ifstream& arch);
int* leerStock(ifstream& arch);
void pruebaDeLecturaLibros(const char* nombre,void* libros);
void imprimirA(ofstream& arch,void* registros);
void imprimirB(ofstream& arch,void* registros);
    
void atencionDePedidos(const char* nombre,void*& clientes,void*& pedidosLibros,void* libros);
void reservaMemoria2(void**& arrClientes,int& cant,int& cap);
void agregaCliente(ifstream& arch,void**& arrClientes,int& Ccant,int& Ccap,
        int ArrCant[200],int ArrCap[200],int& orden);
int hallaCliente(void** arrCliente,int dni,bool& nuevo);
void reservaMemoria3(int*& aux,int& cant,int& cap);
void copiaAgrega(void*& registro, int orden, int& cant, int& cap);
void pruebaDeLecturaLibros(const char* nombre,void* libros);
    
void reporteDeEntregaDePedidos(const char* nombre,void* libros,void* clientes,void* pedidosLibros);

#endif /* METODOPORINCREMENTOSVOID_HPP */

