/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>

#include "MetodoExactoDeMemoria.hpp"

void lecturaDeLibros(const char* nombre,char***& libros,int**& stock){
    
    char** Blibros[300]{};
    int* Bstock[300]{};
    
    for(int n = 0; n < 300; n++)Blibros[n] = new char*[3]{};
    for(int n = 0; n < 300; n++)Bstock[n] = new int[2]{};
    
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);
    
    int cantLibros = 0;
    while(1){
        arch >> ws;
        if(arch.eof()) break;
        leerStrings(arch,Blibros[cantLibros]);
        leeNums(arch,Bstock[cantLibros]);
        cantLibros++;
    }
    
    libros = new char**[cantLibros+1]{};
    stock = new int*[cantLibros+1]{};
    
    for(int n = 0; n < cantLibros; n++){
        libros[n] = Blibros[n];
        stock[n] = Bstock[n];
    }
}

void leerStrings(ifstream& arch,char**& Blibros){
    
    char* codigo = new char[8]{};
    char* nombre = new char[300]{};
    char* autor = new char[150]{};
    
    arch.getline(codigo,8,',');
    arch.getline(nombre,300,',');
    arch.getline(autor,150,',');
    
    Blibros[0] = codigo;
    Blibros[1] = nombre;
    Blibros[2] = autor;
    
}

void leeNums(ifstream& arch,int*& Bstock){
    
    int stock;
    double precio;
    
    arch >> stock;
    arch.get();
    arch >> precio;
    
    Bstock[0] = stock;
    
}

void pruebaDeLecturaDeLibros(const char* nombre,char*** libros,int**stock){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre);
    
    for(int n = 0; libros[n];n++){
        char** auxLib = libros[n];
        int* auxSt = stock[n];
        arch << left <<setw(10) << auxLib[0] << setw(80) << auxLib[1] << setw(30) << auxLib[2] << setw(5) << auxSt[0] << setw(5) << auxSt[1] << endl;
    }
    
}

void atencionDeLecturaDeLibros(const char* nombre,char*** libros,int**stock,int**& pedidosClientes,char***& pedidosLibros,bool**& pedidosAtendidos){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);
    
    int* BpedidoClientes[200]{};
    char** BpedidosLibros[200]{};
    bool* BpedidosAtendidos[200]{};
    
    int cantClientes = 0,cantPedidos[200]{},cantPedidosLong=0;
    
    for(int n = 0; n < 200; n++) BpedidoClientes[n] = new int[30]{};
    for(int n = 0; n < 200; n++) BpedidosLibros[n] = new char*[10]{};
    for(int n = 0; n < 200; n++) BpedidosAtendidos[n] = new bool[10]{};
    
    while(1){
        arch >> ws;
        if(arch.eof()) break;
        int orden=0,dni=0;
        arch >> orden;
        arch.get();
        arch >> dni;
        int* auxCli = BpedidoClientes[buscaIndiceCli(BpedidoClientes,dni,cantClientes)];
        auxCli[0] = dni;
        auxCli[auxCli[1]+2] = orden;
        auxCli[1]++;
        while(1){
            char *codigo,c;
            codigo = new char[8]{};
            arch >> codigo;
            c = arch.get();
            agregaDatos(libros,stock, BpedidoClientes,BpedidosLibros[orden-1],BpedidosAtendidos[orden-1],dni,codigo,orden,cantClientes,cantPedidos[orden-1],cantPedidosLong);
            if(c=='\n'||c=='\r') break;
        }
    }
    asignaValores(BpedidoClientes,BpedidosLibros,BpedidosAtendidos,cantClientes,cantPedidos,cantPedidosLong,
                pedidosClientes,pedidosLibros,pedidosAtendidos);
}

void agregaDatos(char*** libros,int** stock,int** BpedidoClientes,char**& BpedidosLibros,
                bool* BpedidosAtendidos,int dni,char* codigo,int numPedido,int& cantClientes,int& cantPedidos,int& cantPedidosLong){
    
    if(numPedido>cantPedidosLong) cantPedidosLong=numPedido;
    
    int indiceLibro = buscaIndiceLib(libros,codigo);
    
    
    BpedidosLibros[cantPedidos] = codigo;
    int* auxSt = stock[indiceLibro];
    if(auxSt[0]>0){
        auxSt[0]--;
        BpedidosAtendidos[cantPedidos] = true;
    }else{
        auxSt[1]++;
        BpedidosAtendidos[cantPedidos] = false;
    }
    
    cantPedidos++;

}

int buscaIndiceLib(char*** libros,char* codigo){
    int n;
    for(n = 0;*libros[n];n++ ){
        char** auxLib = libros[n];
        if(strcmp(auxLib[0],codigo)==0) return n;
    }
    cout << "No se encontro el codigo" <<endl;
    exit(1);
}

int buscaIndiceCli(int** pedidoClientes,int dni,int& cantClientes){
    
    int n = 0; 
    while(1){
        int* auxCli = pedidoClientes[n];
        if(auxCli[0]==0){
            cantClientes++;
            return n;
        }  
        if(auxCli[0]==dni) return n;
        n++;
    }
    
}

void asignaValores(int** BpedidosClientes,char*** BpedidosLibros,bool** BpedidosAtendidos,int cantClientes,int cantPedidos[200],int cantPedidosLong,
                int**& pedidosClientes,char***& pedidosLibros,bool**& pedidosAtendidos){
    
    pedidosClientes = new int*[cantClientes+1]{};
    pedidosLibros = new char**[cantPedidosLong+1]{};
    pedidosAtendidos = new bool*[cantPedidosLong+1]{};
    
    for(int n = 0; !(BpedidosClientes[n]==nullptr);n++){
        pedidosClientes[n] = BpedidosClientes[n];
    }
    for(int n = 0; !(*BpedidosLibros[n]==nullptr);n++){
        pedidosLibros[n] = BpedidosLibros[n];
        pedidosAtendidos[n] = BpedidosAtendidos[n];
    }
    
}

void reporteDeEntregaDePedidos(const char* nombre,int** pedidosClientes,char*** pedidosLibros,bool** pedidosAtendidos){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre);
    
    arch << setw(60) << "REPORTE DE ATENCION DE PEDIDOS" << endl;
    int n = 0;
    int* auxCli = pedidosClientes[n];
    //for(n = 0; auxCli[0]!=0;n++){
    while(1){
        auxCli = pedidosClientes[n];
        if(auxCli[0]==0) break;
        linea(arch,'=');
        arch << "CLIENTE:" << setw(11) << auxCli[0] << endl;
        linea(arch,'=');
        
        for(int m = 0; m < auxCli[1];m++){
            arch << setw(12) << " " << setw(30) << "Pedidos No." << setw(30) << "Codigos del libro" << setw(30) << "Observacion" << endl;
            linea(arch,'-');
            char** auxLib = pedidosLibros[auxCli[m+2]-1];
            bool* auxAt = pedidosAtendidos[auxCli[m+2]-1];
            arch << setw(31) << " " << setw(6) << setfill('0') << auxCli[m+2] << setfill(' ');
            for(int j = 0; !(auxLib[j]==nullptr);j++){
                if(j != 0 ) arch << setw(37) << " ";
                arch << setw(20) << auxLib[j];
                if(auxAt[j]) arch << setw(40) << "ATENDIDO" << endl;
                else arch << setw(40) << "NO ATENDIDO" << endl;
            }
            linea(arch,'-');
        }
        n++;
    }
    
}

void linea(ofstream& arch,char c){
    for(int n = 0; n < 150;n++){
        arch << c;
    }
    arch << endl;
}