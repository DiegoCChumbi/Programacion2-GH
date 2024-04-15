/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.hpp
 * Author: user
 *
 * Created on 13 de abril de 2024, 09:30 PM
 */

#ifndef METODOEXACTODEMEMORIA_HPP
#define METODOEXACTODEMEMORIA_HPP

#include "AperturaDeArchivos.h"
#include <iostream>
#include <cstring>

using namespace std;

void lecturaDeLibros(const char* nombre,char***& libros,int**& stock);
void leerStrings(ifstream& arch,char**& libros);
void leeNums(ifstream& arch,int*& stock);

void pruebaDeLecturaDeLibros(const char* nombre,char*** libros,int**stock);

void atencionDeLecturaDeLibros(const char* nombre,char*** libros,int**stock,int**& pedidosClientes,char***& pedidosLibros,bool**& pedidosAtendidos);
void agregaDatos(char*** libros,int** stock,int** BpedidoClientes,char**& BpedidosLibros,
                bool* BpedidosAtendidos,int dni,char* codigo,int numPedido,int& cantClientes,int& cantPedidos,int& cantPedidosLong);
int buscaIndiceLib(char*** libros,char* codigo);
int buscaIndiceCli(int** pedidoClientes,int dni,int& cantClientes);
void asignaValores(int** BpedidosClientes,char*** BpedidosLibros,bool** BpedidosAtendidos,int cantClientes,int cantPedidos[200],int cantPedidosLong,
                int**& pedidosClientes,char***& pedidosLibros,bool**& pedidosAtendidos);

void reporteDeEntregaDePedidos(const char* nombre,int** pedidosClientes,char*** pedidosLibros,bool** pedidosAtendidos);
void linea(ofstream& arch,char c);

#endif /* METODOEXACTODEMEMORIA_HPP */

