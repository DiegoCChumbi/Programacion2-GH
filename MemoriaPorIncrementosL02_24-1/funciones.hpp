/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: user
 *
 * Created on 16 de abril de 2024, 09:43 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"

#define AUMENTO 5

using namespace std;

void lecturaDeLibros(const char* nombre,char***& libros,int**& stock);
char** leerStrings(ifstream& arch);
int* leerInt(ifstream& arch);
void incrementoMemoria(char***& libros,int**& stock,int& capacidad,int& cant);

void pruebaDeLecturaDeLibros(const char* nombre,char*** libros,int** stock);

#endif /* FUNCIONES_HPP */

