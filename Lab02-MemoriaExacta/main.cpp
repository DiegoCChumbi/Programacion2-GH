/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 13 de abril de 2024, 09:27 PM
 */

#include "MetodoExactoDeMemoria.hpp"
int main(int argc, char** argv) {
    
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibros.txt",libros,stock);
    
    atencionDeLecturaDeLibros("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedisos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    
    return 0;
}

