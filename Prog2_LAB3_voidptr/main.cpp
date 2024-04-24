/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 23 de abril de 2024, 02:34 PM
 */
#include "MetodoPorIncrementosVoid.hpp"
int main(int argc, char** argv) {
    
    void* libros;
    void* pedidosLibros;
    void* clientes;
    
    lecturaDeLibros("Libros.csv",libros);
    pruebaDeLecturaLibros("ReporteDeLibrosInicial.txt",libros);
    
    atencionDePedidos("Pedidos.txt",clientes,pedidosLibros,libros);
    pruebaDeLecturaLibros("ReporteDeLibrosInicial.txt",libros);
//    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",libros,clientes,pedidosLibros);

    return 0;
}

