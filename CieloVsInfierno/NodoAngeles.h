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
    }

};

#endif // NODOANGELES_H
