/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.hpp
 * Author: user
 *
 * Created on 29 de marzo de 2024, 01:06 PM
 */

#ifndef SOBRECARGA_HPP
#define SOBRECARGA_HPP

#include "general.hpp"

using namespace std;

bool operator>>(ifstream& arch, struct Cliente& cli);
bool operator>>(ifstream& arch, struct Producto& pro);
bool operator>>(ifstream& arch, struct Pedido& pe);
void operator+=(struct Cliente* arrClientes, struct Pedido& pedido);
bool operator+=(struct Producto* arrProductos, struct Pedido& pedido);
ofstream& operator<<(ofstream& arch, struct Cliente cli);
ofstream& operator<<(ofstream& arch, struct Producto pro);

#endif /* SOBRECARGA_HPP */

