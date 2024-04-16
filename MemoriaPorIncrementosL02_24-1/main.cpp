/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 16 de abril de 2024, 09:41 AM
 */

#include "funciones.hpp"

int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
//    
//    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
//    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
//    
//    reporteDeEntregaDePedidos("ReporteDeEntregaDePedisos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    //cout << "Fin"<<endl;
    return 0;
}

