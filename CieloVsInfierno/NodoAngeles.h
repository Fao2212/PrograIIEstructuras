#ifndef NODOANGELES_H
#define NODOANGELES_H
#include "includes.h"

struct NodoAngeles{
    NodoAngeles* hijoIzquierdo;
    NodoAngeles* hijoMedio;
    NodoAngeles* hijoDerecho;
    Angel * angel;

    NodoAngeles(Angel * angel){
        this->angel = angel;
        this->hijoMedio = this->hijoDerecho = this->hijoIzquierdo = nullptr;
    }

};

#endif // NODOANGELES_H
