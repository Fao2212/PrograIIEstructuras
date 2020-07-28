#ifndef NODOAG_H
#define NODOAG_H
#include "includes.h"

struct NodoAG{

    ArbolGenealogico * dato;
    NodoAG * siguiente;

    NodoAG(ArbolGenealogico * dato){
        this->dato = dato;
        this->siguiente = nullptr;
    }

};

#endif // NODOAG_H
