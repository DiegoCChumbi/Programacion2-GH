/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estructuras.hpp
 * Author: user
 *
 * Created on 29 de marzo de 2024, 01:07 PM
 */

#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

struct Producto{
    char codigo[8];
    char descripcion[60];
    double precio;
    int stock;
    int clientesServidos[20];
    int clientesNoServidos[20];
    int cantidadClientesServidos;
    int cantidadClientesNoServidos;
};

struct ProductoEntregado{
    char codigo[8];
    double precio;
};

struct Cliente{
    int dni;
    char nombre[60];
    int telefono;
    struct ProductoEntregado productosEntregados[20];
    int cantidadProductosEntrgados;
    double montoTotal;
};

struct Pedido{
    char CodigoProducto[8];
    int dniCliente;
    double precioProducto;
};


#endif /* ESTRUCTURAS_HPP */

