/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecarga.hpp"

bool operator>>(ifstream& arch, struct Cliente& cli) {

    int dni = 0;
    char nombre[60] = {};
    int telefono = 0;
    char c;

    //inicializamos lo que no leeremos ahora
    cli.cantidadProductosEntrgados = 0;
    cli.montoTotal = 0;

    arch >> dni >> c;

    if (arch.eof()) return false;

    //getline(arch, nombre, ',');
    arch.getline(nombre,60,',');
    arch >>telefono;

    cli.dni = dni;
    strcpy(cli.nombre, nombre);
    cli.telefono = telefono;

    return true;

}

bool operator>>(ifstream& arch, struct Producto& pro) {
    
    //BIT-434,Campana Extractora modelo Glass,375.09,10
    char codigo[8];
    strcpy(codigo,"XXXXXXX");
    char descripcion[60] = {};
    double precio = -1;
    int stock = -1;

    char c;

    //inicializamos los datos que no leeremos

    pro.cantidadClientesNoServidos = 0;
    pro.cantidadClientesServidos = 0;

    arch.getline(codigo,8,',');
    if (arch.eof()) return false;
    arch.getline(descripcion,60,',');
    arch >> precio >> c >> stock;
    arch >> ws;
    

    strcpy(pro.codigo, codigo);
    strcpy(pro.descripcion, descripcion);
    pro.precio = precio;
    pro.stock = stock;

    return true;

}

bool operator>>(ifstream& arch, struct Pedido& pe) {
    char CodigoProducto[8] = {};
    int dniCliente = 0;

    //inicializamos lo que no se leera en este momento
    pe.precioProducto = 0;
    
    arch >> ws;
    if(arch.eof()) return false;

    arch.getline(CodigoProducto,8,',');
    arch >> dniCliente;

    strcpy(pe.CodigoProducto, CodigoProducto);
    pe.dniCliente = dniCliente;
    
    return true;

}

void operator+=(struct Cliente* arrClientes, struct Pedido& pedido) {

    //buscamos al cliente
    int objetivo = 0;

    int n = 0;
    while(1){
        if (arrClientes[n].dni == pedido.dniCliente || arrClientes[n].dni == 0) {
            objetivo = n;
            break;
        }
        n++;
    }

    /*
     En el enunciado dice esto: "Como no se puede llevar la cuenta de datos 
     en el arreglo, el arreglo deberá tener como último dato un DNI con 
     valor cero." Pero buscamos un dni especifico (asumiendo que existe)
     */

    //el ultimo indices disponible es la cantida de pedidos entregados

    int ultimo = arrClientes[objetivo].cantidadProductosEntrgados;

    arrClientes[objetivo].productosEntregados[ultimo].precio = pedido.precioProducto;
    strcpy(arrClientes[objetivo].productosEntregados[ultimo].codigo, pedido.CodigoProducto);

    arrClientes[objetivo].cantidadProductosEntrgados++;
    arrClientes[objetivo].montoTotal += pedido.precioProducto;

}

bool operator+=(struct Producto* arrProductos, struct Pedido& pedido) {
    
    cout << arrProductos[3].codigo <<endl;
    int n = 3;
    cout << arrProductos[n].codigo <<endl;
    
//    int objetivo;
//
//    //buscamos el producto
//    cout<<"antes"<<endl;
//    int n = 0;
//    cout<<"hola";
//    
//    //strcmp(arrProductos[n].codigo,"XXXXXXX") == 0)||(strcmp(arrProductos[n].codigo,pedido.CodigoProducto) == 0)
////    while(1){
////        bool condicion1 = (strcmp(arrProductos[n].codigo,"XXXXXXX") == 0);
////        bool condicion2 = (strcmp(arrProductos[n].codigo,pedido.CodigoProducto) == 0);
////        if(condicion1 or condicion2){
////            objetivo = n;
////            break;
////        }
////        n++;
////    }
//    objetivo = n;
//
//    if (arrProductos[objetivo].stock > 0) {
//
//        //buscamos el ultimo dni
//        int ultimo;
//        for (int n = 0; n < 20; n++) {
//            if (arrProductos[objetivo].clientesServidos[n] == 0) {
//                ultimo = n;
//                break;
//            }
//        }
//
//        arrProductos[objetivo].clientesServidos[ultimo] = pedido.dniCliente;
//        arrProductos[objetivo].stock--;
//        pedido.precioProducto = arrProductos[objetivo].precio;
//
//        return true;
//    } else {
//        //buscamos el ultimo dni
//        int ultimo;
//        for (int n = 0; n < 20; n++) {
//            if (arrProductos[objetivo].clientesNoServidos[n] == 0) {
//                ultimo = n;
//                break;
//            }
//        }
//        arrProductos[objetivo].clientesNoServidos[ultimo] = pedido.dniCliente;
//
//        return false;
//
//    }

}

ofstream& operator<<(ofstream& arch, struct Cliente cli) {

    arch << setw(11) << cli.dni << setw(30) << left << cli.nombre << setw(12) << right << cli.telefono << setw(12) << cli.montoTotal;
    arch << "Productos entregados: ";

    if (cli.cantidadProductosEntrgados > 0) {
        for (int n = 0; n < cli.cantidadProductosEntrgados; n++) {
            arch << left << setw(10) << cli.productosEntregados[n].codigo;
        }
    } else {
        cout << "NO SE LE ENTREGARON PRODUCTOS";
    }

    arch << endl;
    return arch;

}

ofstream& operator<<(ofstream& arch, struct Producto pro) {

    arch << left << setw(10) << pro.codigo << setw(30) << pro.descripcion << setw(12) << right << pro.precio << setw(5) << pro.stock << endl;

    arch << "Clientes atendidos: \t\t";

    if (pro.cantidadClientesServidos > 0) {
        for (int n = 0; n < pro.cantidadClientesServidos; n++) {
            arch << left << setw(11) << pro.clientesServidos[n];
        }
        arch << endl;
    } else {
        arch << "NO SE ATENDIERON PEDIDOS" << endl;
    }
    
    arch << "Clientes no atendidos: \t";

    if (pro.cantidadClientesNoServidos > 0) {
        for (int n = 0; n < pro.cantidadClientesNoServidos; n++) {
            arch << left << setw(11) << pro.clientesNoServidos[n];
        }
        arch << endl;
    } else {
        arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    }

    return arch;

}