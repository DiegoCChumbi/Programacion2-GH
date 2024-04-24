/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MetodoPorIncrementosVoid.hpp"

void lecturaDeLibros(const char* nombre, void*& libros) {

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombre);

    int cant = 0, cap = 0;

    void** arrLibros = nullptr;

    while (1) {
        arch >> ws;
        if (arch.eof()) break;
        if (cant == cap) reservaMemoria(arrLibros, cant, cap);
        //        leerString(arch,arrLibros,cant);
        //        leerNumeros(arch,arrLibros,cant);
        arrLibros[cant - 1] = leeLibro(arch);
        cant++;
    }
    libros = arrLibros;
}

void reservaMemoria(void**& arrLibros, int& cant, int& cap) {
    cap += INCREMENTO;

    if (arrLibros == nullptr) {
        arrLibros = new void*[cap] {
        };
        cant = 1;
    } else {
        void** aux = new void*[cap] {
        };
        for (int n = 0; arrLibros[n]; n++) aux[n] = arrLibros[n];
        delete arrLibros;
        arrLibros = aux;
    }
}

//void leerString(ifstream& arch,void**& arrLibros,int cant){
//    
//    void ** registro = (void**) arrLibros[cant-1];
//    
//    registro = new void*[4]{};
//    
//    char *codigo,_codigo[100];
//    char *titulo,_titulo[200];
//    char *autor,_autor[100];
//    
//    arch.getline(_codigo,100,',');
//    arch.getline(_titulo,200,',');
//    arch.getline(_autor,100,',');
//    
//    codigo = new char[strlen(_codigo)+1]{};
//    titulo = new char[strlen(_titulo)+1]{};
//    autor = new char[strlen(_autor)+1]{};
//    
//    strcpy(codigo,_codigo);
//    strcpy(titulo,_titulo);
//    strcpy(autor,_autor);
//    
//    registro[CODIGO] = codigo;
//    registro[TITULO] = titulo;
//    registro[AUTOR] = autor;
//    
//}
//
//void leerNumeros(ifstream& arch,void**& arrLibros,int cant){
//    void ** registro = (void**) arrLibros[cant-1];
//    char c;
//    double d;
//    int n;
//    arch >> n >> c >> d;
//    
//    int* stockV = new int[2]{};
//    stockV[STOCK] = n;
//    
//    registro[STOCKV] = stockV;
//}

void* leeLibro(ifstream& arch) {

    void ** registro = new void*[4];
    registro[CODIGO] = leerStr(arch);
    registro[TITULO] = leerStr(arch);
    registro[AUTOR] = leerStr(arch);
    registro[STOCKV] = leerStock(arch);

    return registro;
}

char* leerStr(ifstream& arch) {
    char *palabra, _palabra[200];
    arch.getline(_palabra, 200, ',');
    palabra = new char[strlen(_palabra) + 1] {
    };
    strcpy(palabra, _palabra);
    return palabra;
}

int* leerStock(ifstream& arch) {
    int* stockV = new int[2] {
    };
    int n;
    double d;
    arch >> n;
    arch.get();
    arch >> d;
    stockV[STOCK] = n;
    return stockV;
}

void pruebaDeLecturaLibros(const char* nombre, void* libros) {

    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombre);

    void** registros = (void**) libros;

    for (int n = 0; registros[n]; n++) {
        imprimirA(arch, registros[n]);
        imprimirB(arch, registros[n]);
    }

}

void imprimirA(ofstream& arch, void* registros) {
    void** aux = (void**) registros;
    arch << setw(10) << (char*) aux[CODIGO] << setw(60) << (char*) aux[TITULO] << setw(30) << (char*) aux[AUTOR];
}

void imprimirB(ofstream& arch, void* registros) {
    void** aux = (void**) registros;
    void** aux2 = (void**) aux[STOCKV];
    arch << setw(5) << (int) aux2[STOCK] << setw(5) << (int) aux2[NOATEN] << endl;
}

void atencionDePedidos(const char* nombre, void*& clientes, void*& pedidosLibros, void* libros) {

    //000059,34460612   CRY6839    VYG3594

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombre);

    int ArrCant[200]{}, ArrCap[200]{}, PMAX = 0, Ccant = 0, Ccap = 0;
    void** arrPedidos = nullptr;
    void** arrClientes = nullptr;
    while (1) {
        arch >> ws;
        if (arch.eof()) break;
        int orden;
        agregaCliente(arch, arrClientes, Ccant, Ccap, ArrCant, ArrCap, orden);
        while (1) {
            char codigo[100], c;
            arch >> codigo;
            c = arch.get();
            if (c == '\n') break;
        }
        //agregaPedido(arch,arrPedidos,PMAX,orden);
    }
    clientes = arrClientes;
}

void reservaMemoria2(void**& arrClientes, int& cant, int& cap) {

    cap += INCREMENTO;

    if (arrClientes == nullptr) {
        arrClientes = new void*[cap] {
        };
        cant = 1;
    } else {
        void** aux = new void*[cap] {
        };
        for (int n = 0; arrClientes[n]; n++) aux[n] = arrClientes[n];
        delete arrClientes;
        arrClientes = aux;
    }

}

void agregaCliente(ifstream& arch, void**& arrClientes, int& Ccant, int& Ccap,
        int ArrCant[200], int ArrCap[200], int& orden) {

    int dni;
    arch >> orden;
    arch.get();
    arch >> dni;
    arch.get();

    bool nuevo;

    int n = hallaCliente(arrClientes, dni, nuevo);

    if (nuevo) {
        if (Ccant == Ccap) reservaMemoria(arrClientes, Ccant, Ccap);
        //        int* aux = (int*)arrClientes[n];
        //        reservaMemoria3(aux,ArrCant[n],ArrCap[n]);
        //        aux[DNI] = dni;
        //        aux[2] = orden;
        int* aux = new int[5] {
        };
        aux[DNI] = dni;
        aux[aux[CANTPEDIDOS] + 2] = orden;
        aux[CANTPEDIDOS]++;
        arrClientes[n] = aux;
        Ccant++;
        ArrCant[n] = 4;
        ArrCap[n] = 5;
    } else {
        //        int* aux = (int*)arrClientes[n];
        //        if(ArrCant[n] == ArrCap[n]) reservaMemoria3(aux,ArrCant[n],ArrCap[n]);
        //        aux[aux[CANTPEDIDOS]+2] = orden;
        copiaAgrega(arrClientes[n], orden, ArrCant[n], ArrCap[n]);
        ArrCant[n]++;
    }

}

int hallaCliente(void** arrCliente, int dni, bool& nuevo) {

    if (arrCliente == nullptr) {
        nuevo = true;
        return 0;
    }
    int n;
    for (n = 0; arrCliente[n]; n++) {
        void** aux = (void**) arrCliente[n];
        if ((int) aux[DNI] == dni) {
            nuevo = false;
            return n;
        }
    }
    nuevo = true;
    return n;

}

void reservaMemoria3(int*& aux, int& cant, int& cap) {
    cap += INCREMENTO;

    if (aux == nullptr) {
        aux = new int[cap] {
        };
        cant = 1;
    } else {
        int* aux2 = new int[cap] {
        };
        for (int n = 0; aux[n]; n++) aux2[n] = aux[n];
        delete aux;
        aux = aux2;
    }
}

void agregaPedido(ifstream& arch, void** arrPedido, int& PMAX, int orden) {



}

void reporteDeEntregaDePedidos(const char* nombre, void* libros, void* clientes, void* pedidosLibros) {

    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombre);

    void**aux = (void**) clientes;

    for (int n = 0; aux[n]; n++) {
        void** aux2 = (void**) aux[n];
        arch << (int) aux2[0] << ":" << endl;
        for (int n = 2; aux2[n]; n++) {
            arch << "\t" << (int) aux2[n] << endl;
        }
    }

}

void copiaAgrega(void*& registro, int orden, int& cant, int& cap) {
    if (cant == cap) {
        cap += INCREMENTO;

    }
    int* arr = (int*) registro;
    int* aux = new int[cap] {};
    for (int n = 0; arr[n]; n++) aux[n] = arr[n];
    aux[aux[CANTPEDIDOS] + 2] = orden;
    aux[CANTPEDIDOS]++;
    delete arr;
    registro = aux;
    cout<< "stop";
}