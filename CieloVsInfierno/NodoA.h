#ifndef NODOA_H
#define NODOA_H
#include "includes.h"

struct NodoA{

    Nodo *  dato;
    NodoA * hijoizquierdo;
    NodoA * hijoderecho;

    NodoA(Nodo * dato){
        this->dato = dato;
        hijoderecho = hijoizquierdo = nullptr;
    }

};

#endif // NODOA_H
