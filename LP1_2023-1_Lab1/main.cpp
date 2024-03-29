/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 28 de marzo de 2024, 11:08 PM
 */

#include <cstdlib>
#include "general.hpp"
#include "sobrecarga.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        
    ifstream archClientes;
    ifstream archPedidos;
    ifstream archProductos;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProductos,"Productos.csv");
    
    struct Cliente arrClientes[150];
    struct Producto arrProductos[200];
    
    for(int n = 0; n < 150; n++){
        if(!(archClientes >> arrClientes[n])) break;
    }
    
    for(int n = 0; n < 200; n++){
        if(!(archProductos >> arrProductos[n])) break;
    }
    
    struct Pedido _pedido; 
    
    while(archPedidos >> _pedido){
        arrProductos+=_pedido;
        arrClientes+=_pedido;
    }
    
    return 0;
}

